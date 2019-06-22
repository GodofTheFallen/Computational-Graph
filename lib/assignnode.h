#ifndef COMPUTATIONAL_GRAPH_ASSIGNNODE_H
#define COMPUTATIONAL_GRAPH_ASSIGNNODE_H

#include <iostream>
#include "node.h"
#include "varnode.h"

template<typename _T>
class AssignNode : public Node<_T>
{
protected:
    VarNode<_T> *Target;
    Node<_T> *Source;

    std::string TarName() const { return Target->GetNodeName(); }; //被赋值名称
    std::string SrcName() const { return Source->GetNodeName(); }; //值来源名称
public:
    using Node<_T>::GetNodeName;
    using Node<_T>::Result;

    AssignNode(std::string NodeName, Node<_T> *_Tar, Node<_T> *_Src)
            : Node<_T>(NodeName), Target(dynamic_cast<VarNode<_T> *>(_Tar)), Source(_Src) {}

    _T GetVal();

    _T GetGrad(std::string);

    void Clear();
};

template<typename _T>
_T AssignNode<_T>::GetVal()
{
    if (!Result) Result = new _T(Source->GetVal());
    return *Result;
}

template<typename _T>
void AssignNode<_T>::Clear()
{
    if (Result) Target->SetVal(*Result);
    Source->Clear();
    Node<_T>::Clear();
}

template<typename _T>
_T AssignNode<_T>::GetGrad(std::string AtVName)
{
    if (AtVName == GetNodeName()) Node<_T>::GetGrad(AtVName); //以该节点为自变量求导是不允许的
    else return Source->GetGrad(AtVName);
    //如果不以该节点为自变量求导，则会自动转接到该节点实际返回值对应的节点继续求导，但并不会进行Assign操作
}

#endif //COMPUTATIONAL_GRAPH_ASSIGNNODE_H