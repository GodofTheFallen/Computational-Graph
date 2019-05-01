#ifndef COMPUTATIONAL_GRAPH_TANHCNODE_H
#define COMPUTATIONAL_GRAPH_TANHCNODE_H

#include"../lib/calcnode.h"

template<typename _T>
class TanhCNode : public CalcNode<_T>
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
double TanhCNode<double>::Calc()
{
    Result = new double(tanh(Operands[0]->GetVal()));
    return *Result;
}

#endif //COMPUTATIONAL_GRAPH_TANHCNODE_H
