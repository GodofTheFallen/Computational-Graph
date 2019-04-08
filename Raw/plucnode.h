#ifndef COMPUTATIONAL_GRAPH_PLUCNODE_H
#define COMPUTATIONAL_GRAPH_PLUCNODE_H

#include"calcnode.h"

template<typename _T>
class PluCNode : public CalcNode<_T>
{
protected:
    _T Calc(); //重载Calc，在这里进行计算

public:
    using CalcNode<_T>::Result;
    using CalcNode<_T>::OperandNum;
    using CalcNode<_T>::Operands;

    explicit PluCNode(std::vector<Node<_T> *> OperandsList) //从Vector建立
    {
        CalcNode<_T>(2);
        Operands = new Node<_T> *[2];
        for (int i = 0; i < OperandNum; ++i) Operands[i] = OperandsList[i];
    }
};

template<typename _T>
_T PluCNode<_T>::Calc()
{
    Result = new _T(OperandNum[0] + OperandNum[1]);
    return *Result;
}

#endif //COMPUTATIONAL_GRAPH_PLUCNODE_H
