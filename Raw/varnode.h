#ifndef COMPUTATIONAL_GRAPH_VARNODE_H
#define COMPUTATIONAL_GRAPH_VARNODE_H

#include "phnode.h"

template<typename _T>
class VarNode : PHNode<_T>
{
private:
public:
    using PHNode<_T>::Result;

    VarNode() { Result = nullptr; }

    explicit VarNode(_T _InitVal) { Result = new _T(_InitVal); }

    _T GetVal();

    void Clear() {}

    void ForcedClear();

};

template<typename _T>
void VarNode<_T>::ForcedClear()
{
    Node<_T>::Clear();
}

template<typename _T>
_T VarNode<_T>::GetVal()
{

}


#endif //COMPUTATIONAL_GRAPH_VARNODE_H
