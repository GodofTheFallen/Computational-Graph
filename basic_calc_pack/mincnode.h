#ifndef COMPUTATIONAL_GRAPH_MINCNODE_H
#define COMPUTATIONAL_GRAPH_MINCNODE_H

#include"../lib/calcnode.h"

template<typename _T>
class MinCNode : public CalcNode<_T>
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
double MinCNode<double>::Calc()
{
    Result = new double(Operands[0]->GetVal() - Operands[1]->GetVal());
    return *Result;
}

#endif //COMPUTATIONAL_GRAPH_MINCNODE_H
