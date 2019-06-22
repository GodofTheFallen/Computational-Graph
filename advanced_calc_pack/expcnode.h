#ifndef COMPUTATIONAL_GRAPH_EXPCNODE_H
#define COMPUTATIONAL_GRAPH_EXPCNODE_H

#include"../lib/calcnode.h"

template<typename _T>
class ExpCNode : public CalcNode<_T>
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
double ExpCNode<double>::Calc()
{
    Result = new double(exp(Operands[0]->GetVal()));
    return *Result;
}

template<typename _T>
_T ExpCNode<_T>::CalcGrad(std::string AtVName)
{
    return Operands[0]->GetGrad(AtVName) * CalcNode<double>::GetVal();
}

#endif //COMPUTATIONAL_GRAPH_EXPCNODE_H

