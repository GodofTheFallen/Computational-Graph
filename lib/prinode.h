#ifndef COMPUTATIONAL_GRAPH_PRINODE_H
#define COMPUTATIONAL_GRAPH_PRINODE_H

#include <iostream>
#include "node.h"

template<typename _T>
class PriNode : public Node<_T>
{
protected:
    std::string WatchName; //需要被输出的节点名称
    Node<_T> *WatchNode; //需要被输出的节点
    std::ostream &OUTPUT;

    _T Print();

public:
    using Node<_T>::GetNodeName;
    using Node<_T>::Result;

    explicit PriNode(std::string NodeName, Node<_T> *_NtoW, std::ostream &_OSTR)
            : Node<_T>(NodeName), WatchNode(_NtoW), WatchName(_NtoW->GetNodeName()), OUTPUT(_OSTR) {};

    _T GetVal();

    _T GetGrad(std::string);

    void Clear();
};

template<typename _T>
_T PriNode<_T>::Print()
{
    Result = new _T(WatchNode->GetVal());
    OUTPUT << "PRINT operator: " << WatchName << " = " << *Result << std::endl; //输出观察结果
    return *Result;
}

template<typename _T>
_T PriNode<_T>::GetVal()
{
    if (!Result) Print();
    return *Result;
}

template<typename _T>
void PriNode<_T>::Clear()
{
    WatchNode->Clear();
    Node<_T>::Clear();
}

template<typename _T>
_T PriNode<_T>::GetGrad(std::string AtVName)
{
    if (AtVName == GetNodeName()) Node<_T>::GetGrad(AtVName); //以该节点为自变量求导是不允许的
    else return WatchNode->GetGrad(AtVName);
    //如果不以该节点为自变量求导，则会自动转接到该节点实际返回值对应的节点继续求导，但并不会进行输出
}

#endif //COMPUTATIONAL_GRAPH_PRINODE_H
