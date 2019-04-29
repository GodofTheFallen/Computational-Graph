# Computational-Graph

## 库与类功能介绍

### Node

`Node` 是一个虚基类

<br/>

#### 保护成员列表：

##### `_T *Result;`

用于储存计算结果，为空表示未计算出答案

<br/>

#### 公开成员列表：

##### `virtual _T GetVal() = 0;`

纯虚函数，获取答案时使用，需要在派生类中被重载

<br/>

##### `virtual void Clear() = 0;`

纯虚函数，清除答案，需要在派生类中被重载

<br/>

<br/>

### ConNode : Node

`ConNode` 继承自 `Node` ，是常数节点

<br/>

#### 私有成员列表

##### `_T *const ConVal;`

用来储存常数值

初始化时就必须将 `ConVal` 指针指向 `_T` 类常数，不提供修改接口

<br/>

#### 公开成员列表

##### `_T GetVal();`

重载基类的 `GetVal()` ，直接返回 `*ConVal`

<br/>

##### `void Clear();`

重载基类的 `Clear()` ，什么都不干

<br/>

<br/>

### PHNode : Node

<br/>

<br/>

### CalcNode : Node

`CalcNode` 继承自 `Node` ，是进行计算操作的节点，是虚基类

<br/>

#### 成员列表

##### `const int OperandNum;`

记录计算节点操作元的个数，由派生类调用 `CalcNode(int)` 进行初始化

<br/>

##### `Node<_T> **Operands;`

指向操作元的指针数组，由派生类初始化

<br/>

##### `virtual _T Calc() = 0;`

虚函数，进行计算，结果储存在 `Result` 中

不可从外部调用，仅在 `Result` 为空指针时由 `GetVal()` 调用

<br/>

##### `_T GetVal();`

重载基类的求值函数，在 `Result` 为空指针时调用 `Calc()` 求值，否则直接返回答案

<br/>

##### `void Clear();`

重载基类的清除函数，会在清除自身答案前递归调用所有操作元的清除函数

<br/>

<br/>

---

## 扩展包介绍
 
### 派生类包：基础计算节点 `basic_calc_pack.h`

包含四个双目运算节点：加减乘除四则运算

都继承自 `CalcNode` ，仅重载了 `Calc()`

<br/>

<br/>

#### PluCNode

`PluCNode` 是加法节点

实现了成员 `Calc()` ，将两个操作元的 `GetVal()` 返回值相加，储存在 `Result` 中并返回

<br/>
