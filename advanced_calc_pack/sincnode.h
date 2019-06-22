#ifndef COMPUTATIONAL_GRAPH_SINCNODE_H
#define COMPUTATIONAL_GRAPH_SINCNODE_H

#include"../lib/calcnode.h"

template<typename _T>
class SinCNode : public CalcNode<_T>
{
protected:
    _T Calc(); //重载Calc，在这里进行计算
    _T CalcGrad(std::string);

public:
    using CalcNode<_T>::Result;
    using CalcNode<_T>::OperandNum;
    using CalcNode<_T>::Operands;
    using CalcNode<_T>::CalcNode;
};

template<>
double SinCNode<double>::Calc()
{
    Result = new double(sin(Operands[0]->GetVal()));
    return *Result;
}

template<>
double SinCNode<double>::CalcGrad(std::string AtVName)
{
    return Operands[0]->GetGrad(AtVName) * cos(Operands[0]->GetVal());
}

#endif //COMPUTATIONAL_GRAPH_SINCNODE_H
