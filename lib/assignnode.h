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
    using Node<_T>::Result;

    AssignNode(std::string NodeName, Node<_T> *_Tar, Node<_T> *_Src)
            : Node<_T>(NodeName), Target(_Tar), Source(_Src) {}

    _T GetVal();

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

#endif //COMPUTATIONAL_GRAPH_ASSIGNNODE_H