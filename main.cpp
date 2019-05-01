#include <iostream>
#include "lib/comgraph.h"
#include "basic_calc_pack/basic_calc_pack.h"
#include "advanced_calc_pack/advanced_calc_pack.h"
#include "compare_calc_pack/compare_calc_pack.h"

using namespace std;
ostream &ErrOut = cout; //应项目要求，错误信息向cout输出
ostream &PriOut = cout; //应项目要求，PriNode信息向cout输出

int main()
{
    ComGraph<double> Sample_Graph(ErrOut, PriOut); //重新设定错误信息输出位置
    int n;
    //独立节点的建立-------BEGIN-------
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string NodeName;
        char NodeType;
        double val;
        cin >> NodeName >> NodeType; //cin会默认跳过空字符，所以不用getchar()
        if (Sample_Graph.FindNode(NodeName)) { //输入节点重名，输出错误信息，强行终止程序
            ErrOut << "ERROR: " << NodeName << " already exist" << endl;
            return i;
        }
        switch (NodeType) {
            case 'C': //创建ConNode
                cin >> val;
                Sample_Graph.BuildConNode(NodeName, val);
                break;
            case 'P': //创建PHNode
                Sample_Graph.BuildPHNode(NodeName);
                break;
            case 'V': //创建VarNode
                cin >> val;
                Sample_Graph.BuildVarNode(NodeName, val);
                break; //虽然VarNode还可以不赋初值构造，但是并没有这样的输入，所以我也没写这样的操作
            default:  //异常输入，输出错误信息，强行终止程序
                ErrOut << "ERROR: Failed to build " << NodeName << endl;
                exit(i);
        }
    }
    //独立节点的建立--------END--------
    //依赖节点的建立-------BEGIN-------
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string NodeName, TempStr;
        vector<string> OperandsList;
        cin >> NodeName >> TempStr; //多读一个等号
        if (Sample_Graph.FindNode(NodeName)) { //输入节点重名，输出错误信息，强行终止程序
            ErrOut << "ERROR: " << NodeName << " already exist" << endl;
            return i;
        }
        cin >> TempStr;
        if (TempStr == "SIN" || TempStr == "LOG" || TempStr == "EXP" || TempStr == "TANH" ||
            TempStr == "SIGMOID") { //单目
            cin >> TempStr;
            OperandsList.clear();
            OperandsList.push_back(TempStr);
            if (TempStr == "SIN")
                Sample_Graph.BuildCalcNode<SinCNode<double>>(NodeName, 1, OperandsList);
            else if (TempStr == "LOG")
                Sample_Graph.BuildCalcNode<LogCNode<double>>(NodeName, 1, OperandsList);
            else if (TempStr == "EXP")
                Sample_Graph.BuildCalcNode<ExpCNode<double>>(NodeName, 1, OperandsList);
            else if (TempStr == "TANH")
                Sample_Graph.BuildCalcNode<TanhCNode<double>>(NodeName, 1, OperandsList);
            else if (TempStr == "SIGMOID")
                Sample_Graph.BuildCalcNode<SigCNode<double>>(NodeName, 1, OperandsList);
        } else if (TempStr == "PRINT") {
            Sample_Graph.BuildPriNode(NodeName, TempStr);
        } else if (TempStr == "COND") { //条件
            OperandsList.clear();
            for (int i = 1; i <= 3; ++i) { //这里继续用i不虚，因为临时定义，不会对原来的i产生影响
                cin >> TempStr;
                OperandsList.push_back(TempStr);
            }
            Sample_Graph.BuildCalcNode<CondNode<double>>(NodeName, 3, OperandsList);
        } else if (Sample_Graph.FindNode(TempStr)) { //双目
            string OP1 = TempStr, OP2, OPRT;
            cin >> OPRT >> OP2;
            OperandsList.clear();
            OperandsList.push_back(OP1);
            OperandsList.push_back(OP2);
            if (OPRT == "+")
                Sample_Graph.BuildCalcNode<PluCNode<double>>(NodeName, 2, OperandsList);
            else if (OPRT == "-")
                Sample_Graph.BuildCalcNode<MinCNode<double>>(NodeName, 2, OperandsList);
            else if (OPRT == "*")
                Sample_Graph.BuildCalcNode<MulCNode<double>>(NodeName, 2, OperandsList);
            else if (OPRT == "/")
                Sample_Graph.BuildCalcNode<DivCNode<double>>(NodeName, 2, OperandsList);
            else if (OPRT == ">")
                Sample_Graph.BuildCalcNode<GTCNode<double>>(NodeName, 2, OperandsList);
            else if (OPRT == "<")
                Sample_Graph.BuildCalcNode<LSCNode<double>>(NodeName, 2, OperandsList);
            else if (OPRT == ">=")
                Sample_Graph.BuildCalcNode<GECNode<double>>(NodeName, 2, OperandsList);
            else if (OPRT == "<=")
                Sample_Graph.BuildCalcNode<LECNode<double>>(NodeName, 2, OperandsList);
            else if (OPRT == "==")
                Sample_Graph.BuildCalcNode<EQCNode<double>>(NodeName, 2, OperandsList);
        } else { //异常输入，输出错误信息，强行终止程序
            ErrOut << "ERROR: Failed to build " << NodeName << endl;
            exit(i);
        }
    }
    //依赖节点的建立--------END--------
    //命令执行-------------BEGIN-------
    cin >> n;
    for (int i = 1; i <= n; ++i) {

    }
    //命令执行--------------END--------
    return 0;
}