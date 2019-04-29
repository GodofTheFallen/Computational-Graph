#ifndef COMPUTATIONAL_GRAPH_GECNODE_H
#define COMPUTATIONAL_GRAPH_GECNODE_H

#include"../lib/calcnode.h"

template<typename _T>
class GECNode : public CalcNode<_T> //�Ƚ������GECNode
{
protected:
	_T Calc(); //����Calc����������м���
public:
	using CalcNode<_T>::Result;
	using CalcNode<_T>::OperandNum;
	using CalcNode<_T>::Operands;           //Using ����Ĳ���Ԫ
	using CalcNode<_T>::CalcNode;
};

template<>
double GECNode<double>::Calc()
{
	Result = new double(Operands[0]->GetVal() >= Operands[1]->GetVal());
	return *Result;
}

#endif //COMPUTATIONAL_GRAPH_GECNODE_H


