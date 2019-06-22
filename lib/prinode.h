#ifndef COMPUTATIONAL_GRAPH_PRINODE_H
#define COMPUTATIONAL_GRAPH_PRINODE_H

#include <iostream>
#include "node.h"

template<typename _T>
class PriNode : public Node<_T>
{
protected:
    std::string WatchName() const { return WatchNode->GetNodeName(); } //需要被输出的节点名称
    Node<_T> *WatchNode; //需要被输出的节点
    std::ostream &OUTPUT;

    _T Print();

public:
    using Node<_T>::Result;

    explicit PriNode(std::string NodeName, Node<_T> *_NtoW, std::ostream &_OSTR)
            : Node<_T>(NodeName), WatchNode(_NtoW), OUTPUT(_OSTR) {};

    _T GetVal();

    void Clear();
};

template<typename _T>
_T PriNode<_T>::Print()
{
    Result = new _T(WatchNode->GetVal());
    OUTPUT << "PRINT operator: " << WatchName() << " = " << *Result << std::endl; //输出观察结果
    return *Result;
}

template<typename _T>
_T PriNode<_T>::GetVal()
{
    if (!Result) Print();
    return *Result;
}

template<typename _T>
void PriNode<_T>::Clear()
{
    WatchNode->Clear();
    Node<_T>::Clear();
}


#endif //COMPUTATIONAL_GRAPH_PRINODE_H
