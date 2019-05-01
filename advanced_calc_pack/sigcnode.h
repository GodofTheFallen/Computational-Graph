#ifndef COMPUTATIONAL_GRAPH_SIGCNODE_H
#define COMPUTATIONAL_GRAPH_SIGCNODE_H

#include"../lib/calcnode.h"

template<typename _T>
class SigCNode : public CalcNode<_T>
{
protected:
    _T Calc(); //重载Calc，在这里进行计算

public:
    using CalcNode<_T>::Result;
    using CalcNode<_T>::OperandNum;
    using CalcNode<_T>::Operands;
    using CalcNode<_T>::CalcNode;
};

template<>
double SigCNode<double>::Calc()
{
    Result = new double(1 / (1 + exp((-1)*Operands[0]->GetVal())));
    return *Result;
}

#endif //COMPUTATIONAL_GRAPH_SIGCNODE_H

