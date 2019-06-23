#include "./lib/comgraph.h"
#include "./basic_calc_pack/basic_calc_pack.h"

inline string AiToString(int i) { return "a" + to_string(i); }

int main()
{
    int QuestionNum;
    cin >> QuestionNum;
    while (QuestionNum--) {
        ComGraph<double> NtMGraph;
        NtMGraph.BuildVarNode("x");
        int N;
        double a;
        string LastNodeName;
        vector<string> OperandList;
        cin >> N >> a;
        NtMGraph.BuildConNode(LastNodeName = "a" + to_string(N), a); //fn=an
        for (int i = N - 1; i >= 0; --i) {
            OperandList.clear();
            OperandList.push_back(LastNodeName);
            OperandList.push_back("x");
            NtMGraph.BuildCalcNode<MulCNode<double>>("xa" + to_string(i + 1), 2, OperandList);
            //xa(i+1)=x*f(i+1)
            cin >> a;
            NtMGraph.BuildConNode("a" + to_string(i), a);
            OperandList.clear();
            OperandList.push_back("xa" + to_string(i + 1));
            OperandList.push_back("a" + to_string(i));
            NtMGraph.BuildCalcNode<PluCNode<double>>(LastNodeName = "f" + to_string(i), 2, OperandList);
            //fi=x*f(i+1)+ai
        }
        NtMGraph.BuildGradNode("df", "f0");
        NtMGraph.BuildGradAtNode("df/dx", "df", "x");
        OperandList.clear();
        OperandList.push_back("f0");
        OperandList.push_back("df/dx");
        NtMGraph.BuildCalcNode<DivCNode<double>>("f/(df/dx)", 2, OperandList);
        NtMGraph.BuildCalcNode<DivCNode<double>>("f/(df/dx)", 2, OperandList);
        OperandList.clear();
        OperandList.push_back("x");
        OperandList.push_back("f/(df/dx)");
        NtMGraph.BuildCalcNode<MinCNode<double>>("res", 2, OperandList);
        cin >> a;
        NtMGraph.SetVarVal("x", a);
        for (int i = 1; i <= 5; ++i) {
            vector<pair<string, double>> Empty;
            double res = NtMGraph.Eval("res", Empty);
            cout << res << ' ';
            NtMGraph.SetVarVal("x", res);
        }
        cout << endl;
    }
    return 0;
}