#include <iostream>
#include <sstream>
#include "lib/comgraph.h"
#include "basic_calc_pack/basic_calc_pack.h"
#include "advanced_calc_pack/advanced_calc_pack.h"
#include "compare_calc_pack/compare_calc_pack.h"

typedef string string;
using namespace std;
ostream &ErrOut = cout; //应项目要求，错误信息向cout输出
ostream &PriOut = cout; //应项目要求，PriNode信息向cout输出
ostream &AnsOut = cout; //答案输出至cout

void BuildIndNode(ComGraph<double> &, string, string); //建立独立节点
void BuildDepNode(ComGraph<double> &, string, string); //建立依赖节点

int main()
{
    ComGraph<double> Sample_Graph(ErrOut, PriOut); //重新设定错误信息输出位置
    int n;
    //独立节点的建立-------BEGIN-------
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string NodeName;
        string NodeType;
        cin >> NodeName >> NodeType; //cin会默认跳过空字符，所以不用getchar()
        BuildIndNode(Sample_Graph, NodeType, NodeName);
    }
    //独立节点的建立--------END--------
    //依赖节点的建立-------BEGIN-------
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string NodeName, NodeType;
        cin >> NodeName >> NodeType; //多读一个等号
        cin >> NodeType;
        BuildDepNode(Sample_Graph, NodeType, NodeName);
    }
    //依赖节点的建立--------END--------
    //命令执行-------------BEGIN-------
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string Command, NodeName;
        cin >> Command;
        double Res = 0;
        bool failed = false;
        if (Command == "EVAL") {
            int InitPHNum = 0;
            string PHCommand;
            cin >> NodeName;
            getline(cin, PHCommand);
            istringstream PHC(PHCommand);
            PHC >> InitPHNum;
            vector<pair<string, double>> PHList;
            for (int j = 1; j <= InitPHNum; ++j) {
                string PHName;
                double Val;
                PHC >> PHName >> Val;
                PHList.push_back(make_pair(PHName, Val));
            }
            try {
                Res = Sample_Graph.Eval(NodeName, PHList);
            }
            catch (string &ErrMsg) {
                ErrOut << ErrMsg << endl;
                failed = true;
            }
            if (!failed) AnsOut << Res << endl;
        } else if (Command == "SETANSWER") {
            cin >> NodeName;
            int AnsPos;
            cin >> AnsPos;
            Sample_Graph.SetVarVal(NodeName, Sample_Graph.ReadFromHistory(AnsPos));
        } else if (Command == "SETCONSTANT") {
            cin >> NodeName;
            double Val;
            cin >> Val;
            Sample_Graph.SetVarVal(NodeName, Val);
        }
        Sample_Graph.RecInHistory(Res);
    }
    //命令执行--------------END--------
    return 0;
}

void BuildIndNode(ComGraph<double> &_CG, string NodeType, string NodeName)
{
    double val;
    if (NodeType == "C") { //创建ConNode
        cin >> val;
        _CG.BuildConNode(NodeName, val);
    } else if (NodeType == "P") { //创建PHNode
        _CG.BuildPHNode(NodeName);
    } else if (NodeType == "V") { //创建VarNode
        cin >> val;
        _CG.BuildVarNode(NodeName, val);
        //虽然VarNode还可以不赋初值构造，但是并没有这样的输入，所以我也没写这样的操作
    } else {//异常输入，输出错误信息，强行终止程序
        ErrOut << "ERROR: Failed to build " << NodeName << endl;
        exit(1);
    }
}

int CalcNodeOperands(ComGraph<double> _CG, string NodeType)
{
    if (NodeType == "SIN" || NodeType == "LOG" || NodeType == "EXP" || NodeType == "TANH" ||
        NodeType == "SIGMOID")
        return 1;
    if (_CG.FindNode(NodeType)) return 2;
    if (NodeType == "COND") return 3;
    return 0; // Not CalcNode
}

void BuildDepNode(ComGraph<double> &_CG, string NodeType, string NodeName)
{
    if (int OperandNumTemp = CalcNodeOperands(_CG, NodeType)) {
        vector<string> OperandsList;
        if (OperandNumTemp == 1) {//单目
            string OP;
            cin >> OP;
            OperandsList.push_back(OP);
            if (NodeType == "SIN")
                _CG.BuildCalcNode<SinCNode<double>>(NodeName, 1, OperandsList);
            else if (NodeType == "LOG")
                _CG.BuildCalcNode<LogCNode<double>>(NodeName, 1, OperandsList);
            else if (NodeType == "EXP")
                _CG.BuildCalcNode<ExpCNode<double>>(NodeName, 1, OperandsList);
            else if (NodeType == "TANH")
                _CG.BuildCalcNode<TanhCNode<double>>(NodeName, 1, OperandsList);
            else if (NodeType == "SIGMOID")
                _CG.BuildCalcNode<SigCNode<double>>(NodeName, 1, OperandsList);
        } else if (OperandNumTemp == 2) { //NodeType 实际上不是运算名而是双目运算符第一个操作元
            string OP1 = NodeType, OP2, OPRT;
            cin >> OPRT >> OP2;
            OperandsList.push_back(OP1);
            OperandsList.push_back(OP2);
            if (OPRT == "+")
                _CG.BuildCalcNode<PluCNode<double>>(NodeName, 2, OperandsList);
            else if (OPRT == "-")
                _CG.BuildCalcNode<MinCNode<double>>(NodeName, 2, OperandsList);
            else if (OPRT == "*")
                _CG.BuildCalcNode<MulCNode<double>>(NodeName, 2, OperandsList);
            else if (OPRT == "/")
                _CG.BuildCalcNode<DivCNode<double>>(NodeName, 2, OperandsList);
            else if (OPRT == ">")
                _CG.BuildCalcNode<GTCNode<double>>(NodeName, 2, OperandsList);
            else if (OPRT == "<")
                _CG.BuildCalcNode<LSCNode<double>>(NodeName, 2, OperandsList);
            else if (OPRT == ">=")
                _CG.BuildCalcNode<GECNode<double>>(NodeName, 2, OperandsList);
            else if (OPRT == "<=")
                _CG.BuildCalcNode<LECNode<double>>(NodeName, 2, OperandsList);
            else if (OPRT == "==")
                _CG.BuildCalcNode<EQCNode<double>>(NodeName, 2, OperandsList);

        } else if (OperandNumTemp == 3) { //条件
            for (int j = 1; j <= 3; ++j) {
                string OP;
                cin >> OP;
                OperandsList.push_back(OP);
            }
            _CG.BuildCalcNode<CondNode<double>>(NodeName, 3, OperandsList);
        }
    } else if (NodeType == "PRINT") { //调试输出
        string OP;
        cin >> OP;
        _CG.BuildPriNode(NodeName, OP);
    } else if (NodeType == "ASSERT") {
        string OP;
        cin >> OP;
        _CG.BuildAssertNode(NodeName, OP);
    } else if (NodeType == "ASSIGN") {
        string OP1, OP2;
        cin >> OP1 >> OP2;
        _CG.BuildAssignNode(NodeName, OP1, OP2);
    } else if (NodeType == "BIND") {
        string OP1, OP2;
        cin >> OP1 >> OP2;
        _CG.BuildBindNode(NodeName, OP1, OP2);
    } else {//异常输入，输出错误信息，强行终止程序
        ErrOut << "ERROR: Failed to build " << NodeName << endl;
        exit(1);
    }
}
