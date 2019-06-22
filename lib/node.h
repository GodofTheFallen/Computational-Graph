#ifndef COMPUTATIONAL_GRAPH_NODE_H
#define COMPUTATIONAL_GRAPH_NODE_H

#include <string>

template<typename _T>
class Node
{
protected:
    _T *Result;
    const std::string NodeName;
public:
    explicit Node(std::string NodeName = "") : NodeName(NodeName), Result(nullptr) {};

    virtual _T GetVal() = 0; //获取节点的计算结果
    virtual void Clear();  //清除节点的计算结果
    virtual std::string GetNodeName() const;

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
}

template<typename _T>
std::string Node<_T>::GetNodeName() const { return NodeName; }

#endif //COMPUTATIONAL_GRAPH_NODE_H
