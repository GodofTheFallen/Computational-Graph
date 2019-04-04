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
    explicit PriNode(Node<_T> &_NtoW) : WatchNode(_NtoW) {};

    _T GetVal()

};


#endif //COMPUTATIONAL_GRAPH_PRINODE_H
