#ifndef COMPUTATIONAL_GRAPH_ASSERTNODE_H
#define COMPUTATIONAL_GRAPH_ASSERTNODE_H

#include "node.h"

template<typename _T>
class AssertNode : public Node<_T>
{
private:
    Node<_T> *PosAssertion;
    const std::string ErrMsg = "ERROR: Assertion failed"; //Assert不满足时抛出异常
public:
    using Node<_T>::GetNodeName;
    using Node<_T>::Result;

    AssertNode(std::string NodeName, Node<_T> *_Ass)
            : Node<_T>(NodeName), PosAssertion(_Ass) {}

    _T GetVal(); //在计算时检查是否满足要求，并返回0
    //对Assert节点求导是未定义的
    bool Check(); //检查是否满足要求

    void Clear();
};

template<>
bool AssertNode<double>::Check()
{
    if (Result) return *Result > 0;
    return false;
}

template<>
double AssertNode<double>::GetVal()
{
    if (Result) return 0;
    Result = new double(PosAssertion->GetVal());
    if (!Check()) throw ErrMsg;
    return 0;
}

template<typename _T>
void AssertNode<_T>::Clear()
{
    PosAssertion->Clear();
    Node<_T>::Clear();
}


#endif //COMPUTATIONAL_GRAPH_ASSERTNODE_H
