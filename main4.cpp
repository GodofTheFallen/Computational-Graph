//多变量线性方程组，迭代解

#include "./lib/comgraph.h"
#include "./basic_calc_pack/basic_calc_pack.h"

const double eps = 1e-4; //当两次迭代区别较小时停止迭代
const double InitDelta = 0.05, FinalDelta = 0.005, DeltaDec = 0.96; //模拟退火，设定初始步长和每一次迭代步长衰减
const int MaxM = 1005, MaxN = 15;
const int RandTimes = 50, MaxIter = 50000; //初始解随机次数（防止落入极小值），最大迭代次数（防止死循环）

inline void QBuild(ComGraph<double> &_CG, string TypeName, string NodeName, string OP1, string OP2);

int main()
{
    int N, M;
    srand(time(NULL)); //随机种子
    double Ans = -1, AnsK[MaxN], MaxValue = -1e9, MinValue = 1e9; //记录答案，Ans为负数表示尚未计算出答案
    cout << "Number of variables(<=" << MaxN - 5 << "): " << endl;
    cin >> N; //自变量的个数（空间维度N+1）
    cout << "Number of points(<=" << MaxM - 5 << "): " << endl;
    cin >> M; //待拟合的点数
    if (M <= 1) {
        cout << "No Accurate Solution." << endl;
        return 0;
    }//M少于2点无法拟合
    double X[MaxM][MaxN];
    cout << "Input " << N + 1 << " \'double\' number in the following " << M << " lines as Y,X1,X2,... : " << endl;
    for (int i = 1; i <= M; ++i)
        for (int j = 0; j <= N; ++j) {
            cin >> X[i][j];
            MaxValue = max(MaxValue, X[i][j]);
            MinValue = min(MinValue, X[i][j]);
        }
    //读入M行，每行表示一个点，N+1个数，分别是Y,X1~XN
    ComGraph<double> LSMGraph; //计算图
    for (int i = 0; i <= N; ++i) LSMGraph.BuildPHNode("K" + to_string(i)); //建立N+1个系数
    for (int i = 1; i <= M; ++i) { //对于每一个点
        for (int j = 1; j <= N; ++j) LSMGraph.BuildConNode("X" + to_string(i) + "," + to_string(j), X[i][j]);
        LSMGraph.BuildConNode("Y" + to_string(i), -X[i][0]);
        //建立点相关的常数节点
        QBuild(LSMGraph, "Plu", "D" + to_string(i), "Y" + to_string(i), "K0");
        for (int j = 1; j <= N; ++j) {
            QBuild(LSMGraph, "Mul",
                   "Prod" + to_string(i) + "," + to_string(j),
                   "X" + to_string(i) + "," + to_string(j), "K" + to_string(j));
            QBuild(LSMGraph, "Plu", "D" + to_string(i), "D" + to_string(i), "Prod" + to_string(i) + "," + to_string(j));
        }
        QBuild(LSMGraph, "Mul", "D" + to_string(i), "D" + to_string(i), "D" + to_string(i));
        //建立残差公式
    }
    QBuild(LSMGraph, "Plu", "L", "D1", "D2");
    for (int i = 3; i <= M; ++i) QBuild(LSMGraph, "Plu", "L", "L", "D" + to_string(i));
    //累加，至少有两个点，建立目标函数
    LSMGraph.BuildGradNode("DL", "L"); //梯度
    for (int i = 0; i <= N; ++i) LSMGraph.BuildGradAtNode("DLK" + to_string(i), "DL", "K" + to_string(i)); //偏导
    for (int RandCount = 0; RandCount < RandTimes; ++RandCount) {
        double K[MaxN], DK[MaxN], res = -1, delta =
                InitDelta * exp(log(FinalDelta / InitDelta) * RandCount / (RandTimes - 1));
        //初始学习率随随机次数逐次变化
        static vector<pair<string, double>> PHList;
        PHList.clear();
        for (int i = 0; i <= N; ++i) {
            PHList.push_back(make_pair("K" + to_string(i), 0));
            K[i] = (rand() - RAND_MAX) * 2.0 / RAND_MAX * (MaxValue - MinValue) + MinValue;
        }//初始随机
        int IterCount = 0;
        do {
            for (int i = 0; i <= N; ++i) PHList[i].second = K[i];
            double L = LSMGraph.Eval("L", PHList);
            if (res > 0 && fabs((res - L)) < eps) break;
            else {
                for (int j = 0; j <= N; ++j) DK[j] = LSMGraph.Eval("DLK" + to_string(j), PHList);
                for (int j = 0; j <= N; ++j) K[j] = K[j] - delta * DK[j];
                //梯度下降
                delta *= DeltaDec;
                //步长减小
                res = L;
                //临时答案更新
            }
        } while (++IterCount < MaxIter); //最大迭代次数
        if (Ans < 0 || res < Ans) {
            Ans = res;
            for (int j = 0; j <= N; ++j) AnsK[j] = K[j];
            //答案覆盖
        }
    }

    for (int i = 0; i <= N; ++i)
        cout << "K" << i << "=" << AnsK[i] << endl;
    cout << "Minium Loss: " << Ans << endl;
}

inline void QBuild(ComGraph<double> &_CG, string TypeName, string NodeName, string OP1, string OP2)
{
    static vector<string> OperandList;
    OperandList.clear();
    OperandList.push_back(OP1);
    OperandList.push_back(OP2);
    if (TypeName == "Plu") _CG.BuildCalcNode<PluCNode<double>>(NodeName, 2, OperandList);
    if (TypeName == "Mul") _CG.BuildCalcNode<MulCNode<double>>(NodeName, 2, OperandList);
}
