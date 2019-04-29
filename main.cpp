#include <iostream>
#include "lib/comgraph.h"
#include "basic_calc_pack/basic_calc_pack.h"
#include "advanced_calc_pack/advanced_calc_pack.h"
#include "compare_calc_pack/compare_calc_pack.h"

using namespace std;

int main()
{
    ComGraph<double> Sample_Graph;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        string NodeName;
        char NodeType;
        double val;
        cin >> NodeName >> NodeType; //cin会默认跳过空字符，所以不用getchar()
        switch (NodeType) {
            case 'C':
                cin >> val;
                Sample_Graph.BuildConNode(NodeName, val);
                break;
            case 'P':
                Sample_Graph.BuildPHNode(NodeName);
                break;
            case 'V':
                cin >> val;
                Sample_Graph.BuildVarNode(NodeName, val);
                break;
            default:
                cerr << "Error: Failed to build " << NodeName << endl;
                break;
        }
    }
    //初始节点的建立
    return 0;
}