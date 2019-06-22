#ifndef COMPUTATIONAL_GRAPH_SIGCNODE_H
#define COMPUTATIONAL_GRAPH_SIGCNODE_H

#include"../lib/calcnode.h"

template<typename _T>
class SigCNode : public CalcNode<_T>
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
double SigCNode<double>::Calc()
{
    Result = new double(1 / (1 + exp((-1) * Operands[0]->GetVal())));
    return *Result;
}

template<>
double SigCNode<double>::CalcGrad(std::string AtVName)
{
    double Res0 = exp(-Operands[0]->GetVal());
    return Operands[0]->GetGrad(AtVName) * (Res0 / (1 + Res0) / (1 + Res0));
}

#endif //COMPUTATIONAL_GRAPH_SIGCNODE_H

