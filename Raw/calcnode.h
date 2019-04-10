#ifndef COMPUTATIONAL_GRAPH_CALCNODE_H
#define COMPUTATIONAL_GRAPH_CALCNODE_H

#include <vector>
#include <cmath>
#include "node.h"

template<typename _T>
class CalcNode : public Node<_T>
{
protected:
    //protected允许子类访问
    const int OperandNum; //操作数个数
    Node<_T> **Operands; //操作数，指针的指针，第一个指针作为数组，第二个指针作为内容

    virtual _T Calc() = 0;
    //Calc函数用于计算该节点的答案，不允许从外部调用，只可以从GetVal()调用（因为所有的节点都有GetVal()，而Calc()不是）

public:

    using Node<_T>::Result;

    explicit CalcNode(int _OpeNum) : OperandNum(_OpeNum) { Node<_T>(); }

    _T GetVal();

    void Clear(); //所有的CalcNode都可以一起清除

    ~CalcNode()
    {
        delete[] Operands;
        //注意，这里不要释放Operands[]所指的东西，谁申请谁释放，这个申请是在构造前完成的，所以不由本类释放
    }
};

template<typename _T>
_T CalcNode<_T>::GetVal()
{
    if (Result) return *Result;
    for (int i = 0; i < OperandNum; ++i)
        Operands[i]->GetVal();
    Calc();
    return *Result;
}

template<typename _T>
void CalcNode<_T>::Clear()
{
    for (int i = 0; i < OperandNum; ++i)
        Operands[i]->Clear();
    Node<_T>::Clear();
}

#endif //COMPUTATIONAL_GRAPH_CALCNODE_H
