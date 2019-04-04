#ifndef COMPUTATIONAL_GRAPH_PRINODE_H
#define COMPUTATIONAL_GRAPH_PRINODE_H

#include "node.h"

template<typename _T>
class PriNode : Node<_T>
{
protected:
    Node<_T>*;
};


#endif //COMPUTATIONAL_GRAPH_PRINODE_H
