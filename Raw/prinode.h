#ifndef COMPUTATIONAL_GRAPH_PRINODE_H
#define COMPUTATIONAL_GRAPH_PRINODE_H

#include <iostream>
#include "node.h"

template<typename _T>
class PriNode : Node<_T>
{
protected:
    Node<_T> *WatchNode; //需要被输出的节点
    std::ostream &OUTPUT;

    _T Print();

public:
    using Node<_T>::Result;

    explicit PriNode(Node<_T> &_NtoW, std::ostream &_OSTR) : WatchNode(_NtoW), OUTPUT(_OSTR) {};

    _T GetVal();

};

template<typename _T>
_T PriNode<_T>::Print()
{
    Result = new _T(WatchNode->GetVal());
    return *Result;
}

template<typename _T>
_T PriNode<_T>::GetVal()
{
    if (!Result) Print();
    return *Result;
}


#endif //COMPUTATIONAL_GRAPH_PRINODE_H
