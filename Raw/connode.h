#ifndef COMPUTATIONAL_GRAPH_CONNODE_H
#define COMPUTATIONAL_GRAPH_CONNODE_H

#include "node.h"

template<typename _T>
class ConNode : public Node<_T>
{
private:
    _T *const Result;
public:
    explicit ConNode(_T _InitData) : Result(new const _T(_InitData)) {};

    _T GetVal();

    void Clear();

    ~ConNode()
    {
        delete Result;
        Result = nullptr;
    }
};


#endif //COMPUTATIONAL_GRAPH_CONNODE_H
