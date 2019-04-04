#ifndef COMPUTATIONAL_GRAPH_CONNODE_H
#define COMPUTATIONAL_GRAPH_CONNODE_H

#include "node.h"

template<typename _T>
class ConNode : public Node<_T>
{
private:
    _T *const Result; //指向常量的指证，用来储存初始化的答案，不可更改
public:
    explicit ConNode(_T _InitData) : Result(new const _T(_InitData)) {};

    _T GetVal();

    void Clear();
};


#endif //COMPUTATIONAL_GRAPH_CONNODE_H
