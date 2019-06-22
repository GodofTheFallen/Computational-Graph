#ifndef COMPUTATIONAL_GRAPH_CONNODE_H
#define COMPUTATIONAL_GRAPH_CONNODE_H

#include "node.h"

template<typename _T>
class ConNode : public Node<_T>
{
private:
    const _T *ConVal; //指向常量的指证，用来储存初始化的答案，不可更改
public:
    using Node<_T>::GetNodeName;

    explicit ConNode(std::string NodeName, const _T &_InitData)
            : Node<_T>(NodeName) { ConVal = new const _T(_InitData); } //从常量构造节点

    _T GetVal(); //求值
    _T GetGrad(std::string);

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

template<typename _T>
_T ConNode<_T>::GetGrad(std::string AtVName)
{
    if (AtVName == GetNodeName()) Node<_T>::GetGrad(AtVName); //以该节点为自变量求导是不允许的
    else return 0; //如果不以该节点为自变量求导，则对常数求导必为0
}


#endif //COMPUTATIONAL_GRAPH_CONNODE_H
