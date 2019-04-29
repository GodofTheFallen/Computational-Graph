# 计算图任务列表

**UPD！：写一段代码更新一下README.md 和 wiki，内容仿照已有的部分，README.md与wiki内容相同，后期再对README.md进行简化**

## 需要编写的内容

### 计算图节点class

1. 基类 Node
2. 常节点 ConNode : Node
3. 占位节点 PHNode : Node
4. 计算节点 CalcNode : Node
    
    单目运算节点 SINGCNode : CalcNode
    双目运算节点 DOUCNode : CalcNode 
        
        建议每种运算都定义一个节点（有更多可扩展性）
        + PluCNode : DOUCNode
        - MinCNode
        * MulCNode
        / DivCNode
        SIN SinCNode : SINGCNode
        LOG LogCNode
        EXP ExpCNode
        TANH TanhCNode
        SIGMOID SigCNode
    
5. 调试节点 PriNode : Node
6. VarNode + set(x) : PHNode
7. CompNode : CalcNode

    ```  
        >   GTCNode
        <   LSCNode
        >=  GECNode
        <=  LECNode
        ==  EqCNode
    ```    
4. CondNode : CalcNode

### 图类 ComGraph

- map <string,Node*>;
- eval+clear

### Bonus: Template <_T>

## Error

报错请用 try-catch

## Clear

1. 节点处计算，节点处调用依赖节点的计算，用一个指针_T*存临时结果
2. Clear 在节点中定义，递归地clear
3. 防止内存泄露，及时清理内存

## Main
1. 创建一个储存结果的数组

# Git提交与代码的一些建议

记得每个函数都要写注释

建立.h的时候顺便提交一个空的.cpp

文件名一律小写，类名按照上面的大小写来

及时commit

**写一段代码更新一下README.md 和 wiki，内容仿照已有的部分，README.md与wiki内容相同，后期再对README.md进行简化**
