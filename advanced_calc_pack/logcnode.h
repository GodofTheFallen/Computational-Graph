#ifndef COMPUTATIONAL_GRAPH_LOGCNODE_H
#define COMPUTATIONAL_GRAPH_LOGCNODE_H

#include"../lib/calcnode.h"

template<typename _T>
class LogCNode : public CalcNode<_T>
{
protected:
    _T Calc(); //重载Calc，在这里进行计算

public:
    using CalcNode<_T>::OperandNum;
    using CalcNode<_T>::Operands; //直接将基类的操作元using下来，简化代码

    explicit LogCNode(Node<_T> *_Ope0)
    {
        CalcNode<_T>(1);
        Operands = new Node<_T> *[1];
        Operands[0] = _Ope0;
    }

    explicit LogCNode(std::vector<Node<_T> *> OperandsList)
    {
        CalcNode<_T>(1);
        Operands = new Node<_T> *[1];
        for (int i = 0; i < OperandNum; ++i) Operands[i] = OperandsList[i];
    }
    //从含有所有参数地址的vector建立
    //不需要特别的清除和析构，因为没有多余成员
};

#endif //COMPUTATIONAL_GRAPH_LOGCNODE_H

