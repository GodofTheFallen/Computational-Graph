#开发注记

## 扩展包介绍

###派生类包 : 高级计算节点 `advanced_calc_pack`

包含指数运算、对数运算、正弦运算、双曲正切运算、sigmoid函数运算

都继承自`CalcNode`，仅重载了`Cal()`

<br/>

#### ExpCNode

`ExpCNode`是指数节点

实现了成员 `Calc()` ，将操作元的 `GetVal()` 返回值取指数，储存在 `Result` 中并返回

#### LogCNode

`LogCNode`是对数节点

实现了成员 `Calc()` ，将操作元的 `GetVal()` 返回值取对数，储存在 `Result` 中并返回，输入不合法时可能报错

#### SinCNode

`SinCNode`是正弦节点

实现了成员 `Calc()` ，将操作元的 `GetVal()` 返回值取正弦，储存在 `Result` 中并返回

#### TanhCNode

`TanhCNode`是双曲正切节点

实现了成员 `Calc()` ，将操作元的 `GetVal()` 返回值取双曲正切，储存在 `Result` 中并返回

#### SigCNode

`SigCNode`是sigmoid节点

实现了成员 `Calc()` ，将操作元的 `GetVal()` 返回值代入sigmoid函数，储存在 `Result` 中并返回