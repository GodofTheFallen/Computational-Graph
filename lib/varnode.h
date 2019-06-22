#ifndef COMPUTATIONAL_GRAPH_VARNODE_H
#define COMPUTATIONAL_GRAPH_VARNODE_H

#include "phnode.h"

template<typename _T>
class VarNode : public PHNode<_T>
{
private:
    static const std::string ErrMsg;  //需要输出的错误信息，设定为静态
public:
    using PHNode<_T>::Result;
    using PHNode<_T>::GetGrad;//与PHNode的求导方法相同

    explicit VarNode(std::string NodeName) : PHNode<_T>(NodeName) { Result = nullptr; } //第一种构造方式，建一个空变量

    VarNode(std::string NodeName, _T _InitVal)
            : PHNode<_T>(NodeName) { Result = new _T(_InitVal); } //第二种构造方式，建立变量的同时赋初值

    _T GetVal(); //如果未被赋值或被强制清除过则抛出错误信息，否则返回*Result

    void Clear() {}

    void ForcedClear();

};

template<typename _T>
const std::string VarNode<_T>::ErrMsg = "ERROR: Variable missing";

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
