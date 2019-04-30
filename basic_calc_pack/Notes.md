#开发注记

##扩展包介绍

###派生类包 : 基本计算节点`basic_calc_pack`

包含加减乘除四则运算

都继承自`CalcNode`，仅重载了`Cal()`

<br/>

#### PluCNode

`PluCNode`是加法节点

实现了成员 `Calc()` ，将两个操作元的 `GetVal()` 返回值相加，储存在 `Result` 中并返回

#### MinCNode

`MinCNode`是减法节点

实现了成员 `Calc()` ，将两个操作元的 `GetVal()` 返回值相减，储存在 `Result` 中并返回

#### MulCNode

`MulCNode`是乘法节点

实现了成员 `Calc()` ，将两个操作元的 `GetVal()` 返回值相乘，储存在 `Result` 中并返回

#### DivCNode

`DivCNode`是除法节点

实现了成员 `Calc()` ，将两个操作元的 `GetVal()` 返回值相除，储存在 `Result` 中并返回，输入不合法时可能报错


