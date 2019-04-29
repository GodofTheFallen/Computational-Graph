#ifndef COMPUTATIONAL_GRAPH_SIGCNODE_H
#define COMPUTATIONAL_GRAPH_SIGCNODE_H

#include"../lib/calcnode.h"

template<typename _T>
class SigCNode : public CalcNode<_T>
{
protected:
    _T Calc(); //重载Calc，在这里进行计算

public:
    using CalcNode<_T>::OperandNum;
    using CalcNode<_T>::Operands; //直接将基类的操作元using下来，简化代码
	using CalcNode<_T>::CalcNode;
	//从含有所有参数地址的vector建立
	//不需要特别的清除和析构，因为没有多余成员
};

template<>
double SigCNode<double>::Calc()
{
	if (Result) return *Result;
	Result = new double(1 / (1 + exp(-1 * Operands[0]->GetVal())));
	return *Result;
}

#endif //COMPUTATIONAL_GRAPH_SIGCNODE_H

