#ifndef COMPUTATIONAL_GRAPH_DIVCNODE_H
#define COMPUTATIONAL_GRAPH_DIVCNODE_H

#include <string>
#include"../lib/calcnode.h"

template<typename _T>
class DivCNode : public CalcNode<_T>
{
private:
    static const std::string ErrMsg; //需要输出的错误信息，设定为静态
protected:
    _T Calc(); //重载Calc，在这里进行计算
    _T CalcGrad(std::string);

public:
    using CalcNode<_T>::Result;
    using CalcNode<_T>::OperandNum;
    using CalcNode<_T>::Operands;
    using CalcNode<_T>::CalcNode;
};

template<typename _T>
const std::string DivCNode<_T>::ErrMsg = "ERROR: Division by zero";

template<>
double DivCNode<double>::Calc()//存在报错的情况
{
    double Res0 = Operands[0]->GetVal(), Res1 = Operands[1]->GetVal();
    if (Res1 == 0) throw ErrMsg; //被0除
    Result = new double(Res0 / Res1);
    return *Result;
}

template<>
double DivCNode<double>::CalcGrad(std::string AtVName)
{
    double Res0 = Operands[0]->GetVal(), Res1 = Operands[1]->GetVal();
    if (Res1 == 0) throw ErrMsg; //被0除
    return (Operands[0]->GetGrad(AtVName) / Res1 - Operands[1]->GetGrad(AtVName) * Res0 / Res1 / Res1);
}

#endif //COMPUTATIONAL_GRAPH_DIVCNODE_H
