#ifndef COMPUTATIONAL_GRAPH_PHNODE_H
#define COMPUTATIONAL_GRAPH_PHNODE_H

#include <string>
#include "node.h"

template<typename _T>
class PHNode : public Node<_T>
{
private:
    static const std::string ErrMsg; //需要输出的错误信息，设定为静态
public:
    using Node<_T>::Node;
    using Node<_T>::GetNodeName;
    using Node<_T>::Result;

    _T GetVal();

    _T GetGrad(std::string);

    _T SetVal(_T);

    using Node<_T>::Clear;
};

template<typename _T>
const std::string PHNode<_T>::ErrMsg = "ERROR: Placeholder missing"; //类外定义

template<typename _T>
_T PHNode<_T>::GetVal()
{
    if (!Result) throw ErrMsg; //如果未被赋值则出错，抛出错误信息
    return *Result;
}

template<typename _T>
_T PHNode<_T>::SetVal(_T _Val) //在Eval的时候用来预先赋值
{
    if (Result) *Result = _Val;
    else Result = new _T(_Val);
    return *Result;
}

template<>
double PHNode<double>::GetGrad(std::string AtVName)
{
    if (AtVName == GetNodeName()) return 1; //以该节点为自变量求导返回1（并不需要被赋值过）
    else return 0; //否则返回0
}

#endif //COMPUTATIONAL_GRAPH_PHNODE_H
