#ifndef COMPUTATIONAL_GRAPH_EQCNODE_H
#define COMPUTATIONAL_GRAPH_EQCNODE_H

#include"../lib/calcnode.h"

template<typename _T>
class EQCNode : public CalcNode<_T> //比较运算符EQCNode
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
double EQCNode<double>::Calc()
{
	Result = new double(Operands[0]->GetVal() == Operands[1]->GetVal());
	return *Result;
}

#endif //COMPUTATIONAL_GRAPH_EQCNODE_H


