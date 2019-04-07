#ifndef COMPUTATIONAL_GRAPH_COSCNODE_H
#define COMPUTATIONAL_GRAPH_COSCNODE_H

#include"calcnode.h"

template<typename _T>
class CosCNode : public CalcNode<_T>
{
protected:
	_T Calc(); //重载Calc，在这里进行计算

public:
	using CalcNode<_T>::OperandNum;
	using CalcNode<_T>::Operands; //直接将基类的操作元using下来，简化代码

	CosCNode(Node<_T> &_Ope0)
	{
		CalcNode<_T>(1);
		Operands = new Node<_T> *;
		Operands = &_Ope0;
	}
	explicit CosCNode(std::vector<Node<_T> *> OperandsList)
	{
		CalcNode<_T>(1);
		Operands = new Node<_T> *;
		Operands = OperandsList[0];
	}
	//从含有所有参数地址的vector建立
	//不需要特别的清除和析构，因为没有多余成员
};

#endif //COMPUTATIONAL_GRAPH_COSNODE_H

