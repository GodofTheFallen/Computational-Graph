#ifndef COMPUTATIONAL_GRAPH_BINNODE_H
#define COMPUTATIONAL_GRAPH_BINNODE_H

#include<iostream>
#include"node.h"

template<typename _T>
class BinNode : public Node<_T>
{
protected:
	std::string WatchName; //需要被输出的节点名称
	Node<_T>* WatchNode;
	std::string CalName; //需要被计算的节点名称
	Node<_T>* CalNode;

public:
	using Node<_T>::Result;

	explicit BinNode(std::string a, Node<_T>* b, std::string c, Node<_T>* d)
		: WatchName(a), WatchNode(b), CalName(c), CalNode(d) {};

	_T GetVal();

	void Clear();
}

_T BinNode<_T>::GetVal()
{
	Result = new _T(WatchNode->GetVal());
	CalNode->GetVal();
	return *Result;
}

void BinNode<_T>::Clear()
{
	WatchNode->Clear();
	CalNode->Clear();
	Node<_T>::Clear();
}
#endif //COMPUTATIONAL_GRAPH_BINNODE_H