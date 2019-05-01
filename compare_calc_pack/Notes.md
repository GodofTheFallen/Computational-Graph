#开发注记

##扩展包介绍

###派生类包 : 比较计算节点`compare_calc_pack`

包含`大于、小于、等于、大于等于、小于等于`节点

都继承自`CalcNode`，仅重载了`Cal()`

<br/>

#### GtCNode

`GtCNode`是大于节点

实现了成员 `Calc()` ，将两个操作元的 `GetVal()` 返回值用`>`比较，结果储存在 `Result` 中并返回

#### LsCNode

`LsCNode`是小于节点

实现了成员 `Calc()` ，将两个操作元的 `GetVal()` 返回值用`<`比较，结果储存在 `Result` 中并返回

#### EqCNode

`EqCNode`是等于节点

实现了成员 `Calc()` ，将两个操作元的 `GetVal()` 返回值用`==`比较，结果储存在 `Result` 中并返回

#### GeCNode

`GeCNode`是大于等于节点

实现了成员 `Calc()` ，将两个操作元的 `GetVal()` 返回值用`>=`比较，结果储存在 `Result` 中并返回

#### LeCNode

`GtCNode`是小于等于节点

实现了成员 `Calc()` ，将两个操作元的 `GetVal()` 返回值用`<=`比较，结果储存在 `Result` 中并返回

