#ifndef COMPUTATIONAL_GRAPH_SINGCNODE_H
#define COMPUTATIONAL_GRAPH_SINGCNODE_H

#include"calcnode.h"

template<typename _T>
class PluCNode : public CalcNode<_T>
{
protected:
    _T Calc(); //重载Calc，在这里进行计算

public:
    PluCNode(Node<_T> &_Ope0, Node<_T> &_Ope1)
    {
        CalcNode<_T>(2);
        CalcNode<_T>::Operands = new Node<_T> *[2];
        CalcNode<_T>::Operands[0] = _Ope0;
        CalcNode<_T>::Operands[1] = _Ope1;
    }

    _T GetVal();//获取答案，外部只可以调用这个

    //不需要特别的清除和析构，因为没有多余成员
};

#endif //COMPUTATIONAL_GRAPH_DOUCNODE_H
