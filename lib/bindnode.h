#ifndef COMPUTATIONAL_GRAPH_BINDNODE_H
#define COMPUTATIONAL_GRAPH_BINDNODE_H

#include<iostream>
#include"node.h"

template<typename _T>
class BindNode : public Node<_T>
{
protected:
    Node<_T> *MainNode;
    Node<_T> *ExtraNode;

    std::string MainName() const { return MainNode->GetNodeName(); }; //需要被输出的节点名称
    std::string ExtraName() const { return ExtraNode->GetNodeName(); }; //需要被计算的节点名称
public:
    using Node<_T>::Result;

    BindNode(std::string NodeName, Node<_T> *_MN, Node<_T> *_EN) : Node<_T>(NodeName), MainNode(_MN), ExtraNode(_EN) {};

    _T GetVal();

    void Clear();
};

template<typename _T>
_T BindNode<_T>::GetVal()
{
    if (Result) return *Result;
    Result = new _T(MainNode->GetVal());
    ExtraNode->GetVal();
    return *Result;
}

template<typename _T>
void BindNode<_T>::Clear()
{
    MainNode->Clear();
    ExtraNode->Clear();
    Node<_T>::Clear();
}

#endif //COMPUTATIONAL_GRAPH_BINNODE_H