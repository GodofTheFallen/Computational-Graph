#ifndef COMPUTATIONAL_GRAPH_CONNODE_H
#define COMPUTATIONAL_GRAPH_CONNODE_H

#include "node.h"

template<typename _T>
class ConNode : public Node<_T>
{
private:
    _T *const ConVal; //指向常量的指证，用来储存初始化的答案，不可更改
public:
    explicit ConNode(_T _InitData) : ConVal(new const _T(_InitData)) {};

    _T GetVal();

    void Clear();

    ~ConNode()
    {
        delete ConVal;
        ConVal = nullptr;
    }
};


#endif //COMPUTATIONAL_GRAPH_CONNODE_H
