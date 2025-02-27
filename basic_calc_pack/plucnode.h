#ifndef COMPUTATIONAL_GRAPH_PLUCNODE_H
#define COMPUTATIONAL_GRAPH_PLUCNODE_H

#include"../lib/calcnode.h"

template<typename _T>
class PluCNode : public CalcNode<_T>
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
double PluCNode<double>::Calc()
{
    Result = new double(Operands[0]->GetVal() + Operands[1]->GetVal());
    return *Result;
}

template<typename _T>
_T PluCNode<_T>::CalcGrad(std::string AtVName)
{
    return Operands[0]->GetGrad(AtVName) + Operands[1]->GetGrad(AtVName);
}

#endif //COMPUTATIONAL_GRAPH_PLUCNODE_H
