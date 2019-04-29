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

    vector<string> KeywordList;

    vector<_T> AnsHistory;

public:
    ComGraph()
    {
        Index.clear();
        KeywordList.clear();
    }

    _T SetVarVal(string, _T);
    //为变量节点赋值

    Node<_T> *GetNode(string);
    //获取指定关键字节点的节点地址

    template<typename _CN>
    Node<_T> *BuildCalcNode(string, std::vector<Node<_T> *>);

    /*
      这个地方出于可扩展性的考虑，没有直接把所有的feature放进来
      想实现根据主程序的需要来建点，于是采用模板函数
      具体用法BuildNode(节点关键字,所需建立的类型用例,包含节点所有依赖节点地址的vector);
      只能用来建立CalcNode的派生类节点
    */

    _T Eval(string, int, vector<pair<string, _T>>);
    //计算答案，vector内用pair存储参数

    Node<_T> *BuildPHNode(string);

    Node<_T> *BuildConNode(string, _T);

    Node<_T> *BuildVarNode(string, _T);

    Node<_T> *BuildPriNode(string, Node<_T> *, ostream &);

    _T RecInHistory(_T);//记录某一次操作的答案

    _T ReadFromHistory(int);//读取某一次操作的答案

    ~ComGraph()
    {
        for (int i = 0; i < KeywordList.size(); ++i) delete Index[KeywordList[i]];
        KeywordList.clear();
        Index.clear();
    }
};

#endif //COMPUTATIONAL_GRAPH_COMGRAPH_H
