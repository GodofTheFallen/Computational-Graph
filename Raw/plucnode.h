#ifndef COMPUTATIONAL_GRAPH_SINGCNODE_H
#define COMPUTATIONAL_GRAPH_SINGCNODE_H

#include"doucnode.h"

template<typename _T>
class PluCNode : public DUNCNode<_T> {//¼Ó·¨½Úµã
	PluCNode() {

	}
	friend PluCNode& operator+ (const CalcNode& add1, const CalcNode& add2) {
		PluCNode ans;
		*ans.Result = *add1.Result + *add2.Result;
		return ans;
	}
	~PluCNode() {
		delete Result;
		Result = nullptr;
	}
};

#endif //COMPUTATIONAL_GRAPH_DOUCNODE_H
