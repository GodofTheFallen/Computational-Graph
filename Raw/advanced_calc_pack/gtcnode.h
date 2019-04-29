#ifndef COMPUTATIONAL_GRAPH_GTCNODE_H
#define COMPUTATIONAL_GRAPH_GTCNODE_H

#include"calcnode.h"

template<typename _T>
class GTCNode : public CalcNode<_T> //比较运算符GTCNode
{
protected:
    _T Calc(); //重载Calc，在这里进行计算
public:
    using CalcNode<_T>::Result;
    using CalcNode<_T>::OperandNum;
    using CalcNode<_T>::Operands;           //Using 基类的操作元
    using CalcNode<_T>::CalcNode;
};


template<>
double GTCNode<double>::Calc()
{
    Result = new double(Operands[0]->GetVal() > Operands[1]->GetVal());
    return *Result;
}

//这里注意，由于第一阶段只要定义double，所以这个比较节点的Calc只特化double类型
//然后记得加GetVal








#endif //COMPUTATIONAL_GRAPH_GTCNODE_H
