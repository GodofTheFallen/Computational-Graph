#ifndef COMPUTATIONAL_GRAPH_NODE_H
#define COMPUTATIONAL_GRAPH_NODE_H

#include <string>
#include <set>

template<typename _T>
class Node
{
protected:
    _T *Result;
    const std::string NodeName;
    std::set<std::string, _T> GradAt;
public:
    explicit Node(std::string NodeName = "") : NodeName(NodeName), Result(nullptr) { GradAt.clear(); };

    virtual _T GetVal() = 0; //获取节点的计算结果
    virtual _T GetGrad(std::string); //获取节点的导数
    virtual void Clear();  //清除节点的计算结果
    virtual std::string GetNodeName() const;

    void OverRD();

    bool IsOVRD();

    virtual ~Node() //析构时必须释放Result
    {
        Clear();
    }
};

template<typename _T>
void Node<_T>::Clear()
{
    if (Result) delete Result;
    Result = nullptr;
    GradAt.clear();
}

template<typename _T>
std::string Node<_T>::GetNodeName() const { return NodeName; }

template<typename _T>
void Node<_T>::OverRD()
{
    NodeName = "";
}

template<typename _T>
_T Node<_T>::GetGrad(std::string)
{
    throw NodeName + "Grad Undefined";
}

template<typename _T>
bool Node<_T>::IsOVRD()
{
    return GetNodeName() == "";
}

#endif //COMPUTATIONAL_GRAPH_NODE_H
