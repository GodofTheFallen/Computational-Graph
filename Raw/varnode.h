#ifndef COMPUTATIONAL_GRAPH_VARNODE_H
#define COMPUTATIONAL_GRAPH_VARNODE_H

#include "phnode.h"

template<typename _T>
class VarNode : PHNode<_T>
{
private:
public:
    using PHNode<_T>::Result;

    explicit VarNode(_T _InitVal) { Result = new _T(_InitVal); }

    void Clear() {}

    void ForcedClear();

};


#endif //COMPUTATIONAL_GRAPH_VARNODE_H
