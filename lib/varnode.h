#ifndef COMPUTATIONAL_GRAPH_VARNODE_H
#define COMPUTATIONAL_GRAPH_VARNODE_H

#include "phnode.h"

template<typename _T>
class VarNode : PHNode<_T>
{
private:
    static const std::string ErrMsg;  //需要输出的错误信息，设定为静态
public:
    using PHNode<_T>::Result;

    VarNode() { Result = nullptr; } //第一种构造方式，建一个空变量

    explicit VarNode(_T _InitVal) { Result = new _T(_InitVal); } //第二种构造方式，建立变量的同时赋初值

    _T GetVal(); //如果未被赋值或被强制清除过则抛出错误信息，否则返回*Result

    void Clear() {}

    void ForcedClear();

};

template<typename _T>
const std::string VarNode<_T>::ErrMsg = "Error: variable missing";

template<typename _T>
void VarNode<_T>::ForcedClear()
{
    Node<_T>::Clear();
}

template<typename _T>
_T VarNode<_T>::GetVal()
{
    if (!Result) throw ErrMsg;
    return *Result;
}


#endif //COMPUTATIONAL_GRAPH_VARNODE_H
