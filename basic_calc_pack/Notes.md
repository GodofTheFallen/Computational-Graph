#Basic_Calc_Pack

包含四个双目运算节点：加减乘除四则运算

都继承自 `CalcNode` ，仅重载了 `Calc()`

<br/>

#### PluCNode

`PluCNode` 是加法节点

实现了成员 `Calc()` ，将两个操作元的 `GetVal()` 返回值相加，储存在 `Result` 中并返回

<br/>