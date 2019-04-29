#ifndef COMPUTATIONAL_GRAPH_PLUCNODE_H
#define COMPUTATIONAL_GRAPH_PLUCNODE_H

#include"../lib/calcnode.h"

template<typename _T>
class PluCNode : public CalcNode<_T>
{
protected:
    _T Calc(); //重载Calc，在这里进行计算

public:
    using CalcNode<_T>::Result;
    using CalcNode<_T>::OperandNum;
    using CalcNode<_T>::Operands;
    using CalcNode<_T>::CalcNode;
};

template<typename _T>
_T PluCNode<_T>::Calc()
{
    Result = new _T(Operands[0]->GetVal() + Operands[1]->GetVal());
    return *Result;
}

#endif //COMPUTATIONAL_GRAPH_PLUCNODE_H
