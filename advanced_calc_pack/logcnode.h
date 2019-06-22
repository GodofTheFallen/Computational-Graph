#ifndef COMPUTATIONAL_GRAPH_LOGCNODE_H
#define COMPUTATIONAL_GRAPH_LOGCNODE_H

#include <string>
#include"../lib/calcnode.h"

template<typename _T>
class LogCNode : public CalcNode<_T>
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
const std::string LogCNode<_T>::ErrMsg = "ERROR: LOG operator's input must be positive";

template<>
double LogCNode<double>::Calc()
{
    double Res0 = Operands[0]->GetVal();
    if (Res0 <= 0) throw ErrMsg; //对非正数取对数
    Result = new double(log(Res0));
    return *Result;
}

template<>
double LogCNode<double>::CalcGrad(std::string AtVName)
{
    double Res0 = Operands[0]->GetVal();
    if (Res0 <= 0) throw ErrMsg; //对非正数取对数
    return Operands[0]->GetGrad(AtVName)/Res0;
}

#endif //COMPUTATIONAL_GRAPH_LOGCNODE_H

