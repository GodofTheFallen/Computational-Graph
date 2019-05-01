# 派生类包 : 比较计算节点 

## 基本信息

- 文件夹名： `compare_calc_pack`
- 头文件名： `compare_calc_pack.h`
- CMake链接库名： `Compare_Calc_Pack`

<br/>

## 概述

包含一个三目条件运算节点：

1. `CondNode` 条件运算节点

和五个双目比较节点:

1. `GTCNode` 大于节点
2. `LSCNode` 小于节点
3. `GECNode` 大于等于节点
4. `LECNode` 小于等于节点
5. `EQCNode` 等于节点

都继承自 `CalcNode` ，仅重载了 `<double>` 版本的 `Calc()`

<br/>

## 派生类介绍 

### CondNode

`CondNode` 是条件运算节点

实现了成员 `Calc()` ，会先按顺序调用三个操作元的 `GetVal()` 

如果第一个操作元的值大于 $0$ ，则结果为第二个操作元的值，否则结果为第三个操作元的值

结果储存在 `*Result` 中并返回

只要操作元求值时存在异常，就会被该函数继续抛出，即使最终不会选用该分支的结果

如果存在多个异常，仅会抛出最早遇到的异常

### GTCNode

`GTCNode` 是大于节点

实现了成员 `Calc()` ，将两个操作元的 `GetVal()` 返回值用 `>` 进行逻辑运算，为真结果为 $1.0$ ，为假结果为 $0.0$ ，结果储存在 `*Result` 中并返回

### LSCNode

`LSCNode` 是小于节点

实现了成员 `Calc()` ，将两个操作元的 `GetVal()` 返回值用 `<` 进行逻辑运算，为真结果为 $1.0$ ，为假结果为 $0.0$ ，结果储存在 `*Result` 中并返回

### GeCNode

`GECNode` 是大于等于节点

实现了成员 `Calc()` ，将两个操作元的 `GetVal()` 返回值用 `>=` 进行逻辑运算，为真结果为 $1.0$ ，为假结果为 $0.0$ ，结果储存在 `*Result` 中并返回

### LECNode

`LECNode` 是小于等于节点

实现了成员 `Calc()` ，将两个操作元的 `GetVal()` 返回值用 `<=` 进行逻辑运算，为真结果为 $1.0$ ，为假结果为 $0.0$ ，结果储存在 `*Result` 中并返回

### EqCNode

`EQCNode` 是等于节点

实现了成员 `Calc()` ，将两个操作元的 `GetVal()` 返回值用 `==` 进行逻辑运算，为真结果为 $1.0$ ，为假结果为 $0.0$ ，结果储存在 `*Result` 中并返回

<br>

## 使用方法

在主程序中使用 

```c++
#include "compare_calc_pack/compare_calc_pack.h"
```

可包含本扩展包中所有库

使用 `CalcNode` 的构造函数构造

如果你使用 `ComGraph<double>` 构建计算图

可使用其成员函数 `BuildCalcNode<CLASSNAME>(int,vector<string>)` 构建 `CLASSNAME` 类型的节点
