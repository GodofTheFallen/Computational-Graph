#ifndef COMPUTATIONAL_GRAPH_CONNODE_H
#define COMPUTATIONAL_GRAPH_CONNODE_H

#include "node.h"

template<typename _T>
class ConNode : public Node<_T>
{
private:
    const _T *ConVal; //指向常量的指证，用来储存初始化的答案，不可更改
public:
    explicit ConNode(const _T &_InitData) { ConVal = new const _T(_InitData); } //从常量构造节点

    _T GetVal(); //求值

    void Clear(); //清除（虽然能被调用，但实际上什么都不做）

    ~ConNode()
    {
        delete ConVal;
        ConVal = nullptr;
    }
};

template<typename _T>
_T ConNode<_T>::GetVal() //直接返回常值
{
    return *ConVal;
}

template<typename _T>
void ConNode<_T>::Clear() {} //清除时什么都不做

#endif //COMPUTATIONAL_GRAPH_CONNODE_H
