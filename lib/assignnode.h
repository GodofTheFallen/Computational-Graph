#ifndef COMPUTATIONAL_GRAPH_ASSIGNNODE_H
#define COMPUTATIONAL_GRAPH_ASSIGNNODE_H

#include<iostream>
#include"node.h"

template<typename _T>
class BinNode : public Node<_T>
{
protected:
	Node<_T>* Var1;
	Node<_T>* Var2;

	std::string Var1Name() const { return Var1->GetNodeName(); }; //变量节点1名称
	std::string Var2Name() const { return Var2->GetNodeName(); }; //变量节点2名称
public:
	using Node<_T>::Result;

	AssignNode(std::string Nodename, Node<_T>* _V1, Node<_T>* _V2) : Node<_T>(NodeName), Var1(_V1), Var2(_V2) {};

	_T GetVal();

	void Clear();
};

_T AssignNode<_T>::GetVal()
{
	if (!Result)
	{
		Result = new _T(Var2->GetVal());
		Var1->Result = Var2->Getval();
	}
	return *Result;
}

void AssignNode<_T>::Clear()
{
	Var1->Clear();
	Var2->Clear();
	Node<_T>::Clear();
}

#endif //COMPUTATIONAL_GRAPH_ASSIGNNODE_H