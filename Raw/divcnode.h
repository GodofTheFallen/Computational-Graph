#ifndef COMPUTATIONAL_GRAPH_SINGCNODE_H
#define COMPUTATIONAL_GRAPH_SINGCNODE_H

#include"calcnode.h"

template<typename _T>
class DivCNode : public CalcNode<_T>
{
protected:
	_T Calc(); //����Calc����������м���

public:
	using CalcNode<_T>::OperandNum;
	using CalcNode<_T>::Operands; //ֱ�ӽ�����Ĳ���Ԫusing�������򻯴���

	DivCNode(Node<_T> &_Ope0, Node<_T> &_Ope1)
	{
		CalcNode<_T>(2);
		Operands = new Node<_T> *[2];
		Operands[0] = &_Ope0;
		Operands[1] = &_Ope1;
	}

	//����Ҫ�ر���������������Ϊû�ж����Ա
};

#endif //COMPUTATIONAL_GRAPH_DOUCNODE_H
