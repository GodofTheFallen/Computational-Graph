# 派生类包 : 高级计算节点

## 基本信息

- 文件夹名： `advanced_calc_pack`
- 头文件名： `advanced_calc_pack.h`
- CMake链接库名： `Advanced_Calc_Pack`

<br/>

## 概述

包含五个单目计算节点：

1. `ExpCNode` 指数运算节点
2. `LogCNode` 对数运算节点
3. `SinCNode` 正弦节点
4. `TanhCNode` 双曲正切节点
5. `SigCNode`  $\mathrm{sigmoid}$ 函数计算节点

都继承自 `CalcNode` ，仅重载了 `<double>` 版本的 `Calc()`

<br/>

## 派生类介绍

### ExpCNode

`ExpCNode` 是指数运算节点

实现了成员 `Calc()` ，将操作元的 `GetVal()` 返回值取指数，储存在 `*Result` 中并返回

### LogCNode

`LogCNode` 是对数运算节点

实现了成员 `Calc()` ，将操作元的 `GetVal()` 返回值取自然对数，储存在 `*Result` 中并返回

取对数的操作元必须为正数，如果不满足该条件，会抛出 `std::string` 类异常 `"ERROR: LOG operator's input must be positive"`

### SinCNode

`SinCNode` 是正弦节点

实现了成员 `Calc()` ，将操作元的 `GetVal()` 返回值取正弦，储存在 `*Result` 中并返回

### TanhCNode

`TanhCNode` 是双曲正切节点

实现了成员 `Calc()` ，将操作元的 `GetVal()` 返回值取双曲正切，储存在 `*Result` 中并返回

双曲正切函数计算公式为：

$$\tanh(x)=\frac{e^x-e^{-x}}{e^x+e^{-x}}$$

### SigCNode

`SigCNode` 是 $\mathrm{sigmoid}$ 函数计算节点

实现了成员 `Calc()` ，将操作元的 `GetVal()` 返回值代入$\mathrm{sigmoid}$函数，储存在 `*Result` 中并返回

$\mathrm{sigmoid}$ 函数计算公式为：

$$\mathrm{sigmoid}(x)=\frac{1}{1+e^{-x}}$$

<br/>

## 使用方法

在主程序中使用 

```c++
#include "advanced_calc_pack/advanced_calc_pack.h"
```

可包含本扩展包中所有库

使用 `CalcNode` 的构造函数构造

如果你使用 `ComGraph<double>` 构建计算图

可使用其成员函数 `BuildCalcNode<CLASSNAME>(int,vector<string>)` 构建 `CLASSNAME` 类型的节点
