#ifndef COMPUTATIONAL_GRAPH_GRADATNODE_H
#define COMPUTATIONAL_GRAPH_GRADATNODE_H

#include "gradnode.h"

template<typename _T>
class GradAtNode : public Node<_T>
{
private:
    GradNode<_T> *GradTarget;
    std::string AtName;
public:
    using Node<_T>::Result;

    GradAtNode(std::string NodeName, Node<_T> *_GT, std::string _At)
            : Node<_T>(NodeName), GradTarget(dynamic_cast<GradNode<_T> *>(_GT)), AtName(_At) {}

    _T GetVal();

    using Node<_T>::Clear;
};

template<typename _T>
_T GradAtNode<_T>::GetVal()
{
    if (Result) return *Result;
    Result = new _T(GradTarget->GetGrad(AtName));
    return *Result;
}


#endif //COMPUTATIONAL_GRAPH_GRADATNODE_H
