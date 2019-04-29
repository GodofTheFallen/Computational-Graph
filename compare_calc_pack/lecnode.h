#ifndef COMPUTATIONAL_GRAPH_LECNODE_H
#define COMPUTATIONAL_GRAPH_LECNODE_H

#include"../lib/calcnode.h"

template<typename _T>
class LECNode : public CalcNode<_T> //�Ƚ������LECNode
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
double LECNode<double>::Calc()
{
	Result = new double(Operands[0]->GetVal() <= Operands[1]->GetVal());
	return *Result;
}

#endif //COMPUTATIONAL_GRAPH_LECNODE_H

