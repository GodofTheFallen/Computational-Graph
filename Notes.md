#开发注记

这篇注记比较长，推荐导出成 pdf 结合自动生成的目录查阅哦！

## 设计思路

### `class Node` 及其派生类

对于计算图的每一个节点

### `CalcNode` 的处理

### `ComGraph`

## 库与类功能介绍

### Node

`Node` 是一个虚基类

#### 保护成员列表：

##### `_T *Result;`

用于储存计算结果，为空表示未计算出答案

#### 公开成员列表：

##### `virtual _T GetVal() = 0;`

纯虚函数，获取答案时使用，需要在派生类中被重载

##### `virtual void Clear() = 0;`

纯虚函数，清除答案，需要在派生类中被重载

<br/>

### ConNode : Node

`ConNode` 继承自 `Node` ，是常数节点

#### 私有成员列表

##### `_T *const ConVal;`

用来储存常数值

初始化时就必须将 `ConVal` 指针指向 `_T` 类常数，不提供修改接口

#### 公开成员列表

##### `_T GetVal();`

重载基类的 `GetVal()` ，直接返回 `*ConVal`

##### `void Clear();`

重载基类的 `Clear()` ，什么都不干

<br/>

### PHNode : Node

`PHNode` 继承自 `Node` ，是占位符节点

#### 私有成员列表

##### `const std::string ErrMsg;`

一个字符串，会在需要 `GetVal()` 但本节点并未被赋值时被作为异常抛出

#### 公开成员列表

##### `_T GetVal();`

重载基类的 `GetVal()` ，返回被 `SetVal(_T)` 赋的值

若未被 `SetVal(_T)` 赋值过，则抛出 `ErrMsg`

##### `_T SetVal(_T);`

在Eval的时候会被调用，给该节点赋值，结果储存在 `*Result`

<br/>

### VarNode : PHNode

`VarNode` 继承自 `PHNode` ，是变量节点

#### 私有成员列表

##### `const std::string ErrMsg;`

一个字符串，会在需要 `GetVal()` 但本节点并未被赋值时被作为异常抛出

#### 公开成员列表

##### `_T GetVal();`

重载基类的 `GetVal()` ，返回被 `SetVal(_T)` 赋的值

若未被 `SetVal(_T)` 赋值过，则抛出 `ErrMsg`

##### `_T SetVal(_T);`

在Eval的时候会被调用，给该节点赋值，结果储存在 `*Result`

<br/>

### CalcNode : Node

`CalcNode` 继承自 `Node` ，是进行计算操作的节点，是虚基类

#### 保护成员列表

##### `const int OperandNum;`

记录计算节点操作元的个数

##### `Node<_T> **Operands;`

指向所有操作元的指针数组

##### `virtual _T Calc() = 0;`

虚函数，进行计算，结果储存在 `Result` 中

不可从外部调用，仅在 `Result` 为空指针时由 `GetVal()` 调用

#### 公开成员列表

##### `_T GetVal();`

重载基类的求值函数，在 `Result` 为空指针时调用 `Calc()` 求值，否则直接返回答案

##### `void Clear();`

重载基类的清除函数，会在清除自身答案前递归调用所有操作元的清除函数

#### 构造函数

##### `CalcNode(int, const vector<Node<_T> *> &)`

推荐的构造方法，给出操作元个数，给出操作元指针列表来初始化一个CalcNode（的派生类），可以有效避免vector后面一不小心加入了多余的东西

##### `CalcNode(const vector<Node<_T> *> &)`

仅给出操作元指针列表来初始化一个CalcNode（的派生类），请确保指针列表仅仅只含有操作元的指针

<br/>

## 扩展包介绍
 
### 派生类包：基础计算节点 `basic_calc_pack.h`

包含四个双目运算节点：加减乘除四则运算

详见 `basic_calc_pack/Notes.md`

### 派生类包：高级计算节点 `advanced_calc_pack.h`

包含五个单目运算节点，仅可用于 double 类型的计算图

详见 `advanced_calc_pack/Notes.md`

### 派生类包：比较计算节点 `compare_calc_pack.h`

包含五个双目逻辑运算节点和一个三目条件计算节点，仅可用于 double 类型的计算图

详见 `compare_calc_pack/Notes.md`
 
<br>

## 如何自定义计算节点

`COSTOM_NODE_CLASS.h`
```c++
#include "../lib/calcnode.h" //或换成你需要的相对路径

template<typename _T>
class COSTOM_NODE_CLASS : public CalcNode<_T>
{
protected:
    _T Calc(); //重载Calc，在这里进行计算

public:
    using CalcNode<_T>::Result;
    using CalcNode<_T>::OperandNum;
    using CalcNode<_T>::Operands;
    using CalcNode<_T>::CalcNode;
    //以上是进行必要的成员链接，可以简化之后的代码
};

template<typename _T>
_T COSTOM_NODE_CLASS<_T>::Calc()
{
    /*
    在这里定义计算你的答案，对操作元求值必须用Operands[x]->GetVal()
    求完值后：Result = new _T(结果);
    return *Result;这句话其实没啥用，但是能返回代表new成功了    
    */
}
```