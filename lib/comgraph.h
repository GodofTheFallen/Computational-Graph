#ifndef COMPUTATIONAL_GRAPH_COMGRAPH_H
#define COMPUTATIONAL_GRAPH_COMGRAPH_H

#include <vector>
#include <map>
#include "connode.h"
#include "phnode.h"
#include "prinode.h"
#include "varnode.h"
#include "calcnode.h"

using namespace std;

template<typename _T>
class ComGraph
{
private:
    map<string, Node<_T> *> Index;

    _T SetPHNodeVal(Node<_T> *, _T);

    vector<_T> AnsHistory;

    ostream &ErrOut, &PriOut;

    Node<_T> *GetNode(string);    //获取指定关键字节点的节点地址，{不推荐==>不允许}在类外使用

public:
    ComGraph() : ErrOut(cerr), PriOut(cout)
    //构造时载入错误信息和默认PriNode输出流，默认分别为cerr和cout
    {
        Index.clear();
    }

    ComGraph(ostream &_ErrO, ostream &_PrO) : ErrOut(_ErrO), PriOut(_PrO)
    //构造时载入错误信息和默认PriNode输出流，如果要自定义，就必须两个一起自定义
    {
        Index.clear();
    }

    bool FindNode(string);

    _T SetVarVal(string, _T);    //为变量节点赋值

    //template<typename _CN>
    //Node<_T> *BuildCalcNode(string, std::vector<Node<_T> *>); //不推荐，vector包含节点所有依赖节点地址

    template<typename _CN>
    Node<_T> *BuildCalcNode(string, std::vector<string>); //推荐，vector包含节点所有依赖节点名称
    template<typename _CN>
    Node<_T> *BuildCalcNode(string, int, std::vector<string>); //更推荐，指定操作元个数，vector包含节点所有依赖节点名称

    /*
      这个地方出于可扩展性的考虑，没有直接把所有的feature放进来
      想实现根据主程序的需要来建点，于是采用模板函数
      具体用法BuildNode(节点关键字,所需建立的类型用例,包含节点所有依赖节点地址或名称的vector);
      只能用来建立CalcNode的派生类节点
    */

    _T Eval(string, vector<pair<string, _T>>);
    //计算答案，vector内用pair存储参数

    Node<_T> *BuildPHNode(string);

    Node<_T> *BuildConNode(string, _T);

    Node<_T> *BuildVarNode(string);

    Node<_T> *BuildVarNode(string, _T);

    Node<_T> *BuildPriNode(string, string);

    Node<_T> *BuildPriNode(string, string, ostream &);

    _T RecInHistory(_T);//记录某一次操作的答案

    _T ReadFromHistory(int);//读取某一次操作的答案

    void clear();

    ~ComGraph()
    {
        clear();
    }
};
//一个安全性考虑，在类外除了节点建立时，不允许通过任何方式获取建立的节点的地址，防止其被提前删除

template<typename _T>
bool ComGraph<_T>::FindNode(string NodeName)
{
    return Index.count(NodeName);
}

template<typename _T>
Node<_T> *ComGraph<_T>::GetNode(string NodeName)
{
    if (!Index.count(NodeName)) {
        ErrOut << "NodeName " << NodeName << " not found" << endl;
        throw NodeName;
    } //安全检查，这里抛出的异常我没有处理，会直接杀死程序
    return Index[NodeName];
}

template<typename _T>
_T ComGraph<_T>::SetPHNodeVal(Node<_T> *NodetoSet, _T Val)
{
    dynamic_cast<PHNode<_T> *>(NodetoSet)->SetVal(Val); //安全类型转换，调用SetVal
    return NodetoSet->GetVal(); //返回值本身没什么作用，但是能返回代表成功了
}

template<typename _T>
_T ComGraph<_T>::SetVarVal(string NodeName, _T Val)
{
    Node<_T> *NodetoSet = GetNode(NodeName); //获取
    dynamic_cast<VarNode<_T> *>(NodetoSet)->SetVal(Val);
    return NodetoSet->GetVal(); //返回值本身没什么作用，但是能返回代表成功了
}

/*
template<typename _T>
template<typename _CN>
Node<_T> *ComGraph<_T>::BuildCalcNode(string NodeName, vector<Node<_T> *> OperandLists)
{
    Node<_T> *temp = new _CN(OperandLists); //直接建立对应的计算节点（派生类）
    Index[NodeName] = temp;
    return temp;
}
*/

template<typename _T>
template<typename _CN>
Node<_T> *ComGraph<_T>::BuildCalcNode(string NodeName, vector<string> OperandNameLists)
{
    vector<Node<_T> *> OperandLists;
    for (int i = 0; i < OperandNameLists.size(); ++i) OperandLists.push_back(GetNode(OperandNameLists[i]));
    //先转换为包含操作元地址的vector
    Node<_T> *temp = new _CN(OperandLists);
    Index[NodeName] = temp;
    return temp;
}

template<typename _T>
template<typename _CN>
Node<_T> *ComGraph<_T>::BuildCalcNode(string NodeName, int OperandNum, vector<string> OperandNameLists)
{
    vector<Node<_T> *> OperandLists;
    for (int i = 0; i < OperandNum; ++i) OperandLists.push_back(GetNode(OperandNameLists[i]));
    //先转换为包含操作元地址的vector
    Node<_T> *temp = new _CN(OperandNum, OperandLists);
    Index[NodeName] = temp;
    return temp;
}

template<typename _T>
_T ComGraph<_T>::Eval(string NodeName, vector<pair<string, _T>> PHList)
{
    for (int i = 0; i < PHList.size(); ++i) SetPHNodeVal(GetNode(PHList[i].first), PHList[i].second);
    //先对所有占位节点赋值
    Node<_T> *Target = GetNode(NodeName); //获取目标节点地址
    _T Res;
    try {
        Res = Target->GetVal(); //计算
    }
    catch (string &ErrMsg) {
        Target->Clear(); //清除中间结果
        for (int i = 0; i < PHList.size(); ++i) GetNode(PHList[i].first)->Clear();
        throw ErrMsg;
    }
    Target->Clear(); //清除中间结果
    for (int i = 0; i < PHList.size(); ++i) GetNode(PHList[i].first)->Clear(); //清除对占位符的赋值
    return Res; //返回答案
}

template<typename _T>
Node<_T> *ComGraph<_T>::BuildPHNode(string NodeName)
{
    Node<_T> *temp = new PHNode<_T>;
    Index[NodeName] = temp;
    return temp;
}

template<typename _T>
Node<_T> *ComGraph<_T>::BuildConNode(string NodeName, _T ConVal)
{
    Node<_T> *temp = new ConNode<_T>(ConVal);
    Index[NodeName] = temp;
    return temp;
}

template<typename _T>
Node<_T> *ComGraph<_T>::BuildVarNode(string NodeName)
{
    Node<_T> *temp = new VarNode<_T>;
    Index[NodeName] = temp;
    return temp;
}

template<typename _T>
Node<_T> *ComGraph<_T>::BuildVarNode(string NodeName, _T InitVal)
{
    Node<_T> *temp = new VarNode<_T>(InitVal);
    Index[NodeName] = temp;
    return temp;
}

template<typename _T>
Node<_T> *ComGraph<_T>::BuildPriNode(string NodeName, string WatchName)
{
    return BuildPriNode(NodeName, WatchName, PriOut);
}

template<typename _T>
Node<_T> *ComGraph<_T>::BuildPriNode(string NodeName, string WatchName, ostream &_OSTR)
{
    Node<_T> *temp = new PriNode<_T>(WatchName, GetNode(WatchName), _OSTR);
    Index[NodeName] = temp;
    return temp;
}

template<typename _T>
_T ComGraph<_T>::RecInHistory(_T Ans)
{
    AnsHistory.push_back(Ans);
    return Ans;
}

template<typename _T>
_T ComGraph<_T>::ReadFromHistory(int Pos)
{
    return AnsHistory[Pos];
}

template<typename _T>
void ComGraph<_T>::clear()
{
    for (auto i = Index.begin(); i != Index.end(); ++i) delete (i->second);
    Index.clear();
    AnsHistory.clear();
}

#endif //COMPUTATIONAL_GRAPH_COMGRAPH_H
