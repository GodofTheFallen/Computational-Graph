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
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string NodeName;
        char NodeType;
        double val;
        cin >> NodeName >> NodeType; //cin会默认跳过空字符，所以不用getchar()
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
                break;
            default:  //异常输入，输出错误信息，忽略本行
                ErrOut << "Error: Failed to build " << NodeName << endl;
                break;
        }
    }
    //初始节点的建立
    return 0;
}