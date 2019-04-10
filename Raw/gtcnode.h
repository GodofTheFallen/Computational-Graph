//
// 比较运算符GreaterThan-CalculationNode.
//

#ifndef COMPUTATIONAL_GRAPH_GTCNODE_H
#define COMPUTATIONAL_GRAPH_GTCNODE_H
#include"calcnode.h"
template<typename _T>
class GTCNode : public CalcNode<_T>
{
protected:
    template<typename _T1> _T1 Calc(); //重载Calc，在这里进行计算
public:
    using CalcNode<_T>::Result;
    using CalcNode<_T>::OperandNum;
    using CalcNode<_T>::Operands;           //Using 基类的操作元

    explicit GTCNode(Node<_T> *_Ope0, Node<_T> *_Ope1)
    {
        CalcNode<_T>(2);
        Operands = new Node<_T> *[2];
        Operands[0] = _Ope0;
        Operands[1] = _Ope1;
    }            //两点输入构造

    explicit GTCNode(std::vector<Node<_T> *> OperandsList) //从Vector建立
    {
        CalcNode<_T>(2);
        Operands = new Node<_T> *[2];
        for (int i = 0; i < OperandNum; ++i) Operands[i] = OperandsList[i];
    }  //Vector 构造
};
template<typename _T> template<typename _T1>
_T1 GTCNode<_T>::Calc()
{
    Result = new _T1((Operands[0] > Operands[1]));
    return *Result;
}
//写这里的时候 '>' 操作符没有重载
//题目要求_T1默认为float 1.0000








#endif //COMPUTATIONAL_GRAPH_GTCNODE_H
