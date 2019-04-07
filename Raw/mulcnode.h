#ifndef COMPUTATIONAL_GRAPH_SINGCNODE_H
#define COMPUTATIONAL_GRAPH_SINGCNODE_H

#include"calcnode.h"

template<typename _T>
class MulCNode : public CalcNode<_T>
{
protected:
	_T Calc(); //重载Calc，在这里进行计算

public:
	using CalcNode<_T>::OperandNum;
	using CalcNode<_T>::Operands; //直接将基类的操作元using下来，简化代码

	MulCNode(Node<_T> &_Ope0, Node<_T> &_Ope1)
	{
		CalcNode<_T>(2);
		Operands = new Node<_T> *[2];
		Operands[0] = &_Ope0;
		Operands[1] = &_Ope1;
	}

	//不需要特别的清除和析构，因为没有多余成员
};

#endif //COMPUTATIONAL_GRAPH_DOUCNODE_H