#ifndef COMPUTATIONAL_GRAPH_GRADNODE_H
#define COMPUTATIONAL_GRAPH_GRADNODE_H

#include "node.h"

template<typename _T>
class GradNode : public Node<_T>
{
private:
    Node<_T> *GradTarget;
public:
    GradNode(std::string NodeName, Node<_T> *_GT) : Node<_T>(NodeName), GradTarget(_GT) {}

    _T GetVal();

    _T GetGrad(std::string);

    using Node<_T>::Clear;
};

template<typename _T>
_T GradNode<_T>::GetVal()
{
    throw Node<_T>::GetNodeName() + "Val Undefined";
}

template<typename _T>
_T GradNode<_T>::GetGrad(std::string AtVName)
{
    if (AtVName == Node<_T>::GetNodeName()) Node<_T>::GetGrad(AtVName);
    return GradTarget->GetGrad(AtVName);
}


#endif //COMPUTATIONAL_GRAPH_GRADNODE_H
