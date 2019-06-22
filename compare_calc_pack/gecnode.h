#ifndef COMPUTATIONAL_GRAPH_GECNODE_H
#define COMPUTATIONAL_GRAPH_GECNODE_H

#include"../lib/calcnode.h"

template<typename _T>
class GECNode : public CalcNode<_T> //比较运算符GECNode
{
protected:
    _T Calc(); //重载Calc，在这里进行计算
public:
    using CalcNode<_T>::Result;
    using CalcNode<_T>::OperandNum;
    using CalcNode<_T>::Operands;           //Using 基类的操作元
    using CalcNode<_T>::CalcNode;
    using Node<_T>::GetGrad; //不允许求导
    GRAD_DISABLE
};

template<>
double GECNode<double>::Calc()
{
    Result = new double(Operands[0]->GetVal() >= Operands[1]->GetVal());
    return *Result;
}

#endif //COMPUTATIONAL_GRAPH_GECNODE_H


