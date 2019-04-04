#ifndef COMPUTATIONAL_GRAPH_SINGCNODE_H
#define COMPUTATIONAL_GRAPH_SINGCNODE_H

#include"doucnode.h"

template<typename _T>
class MulCNode : public DUNCNode<_T> {//³Ë·¨½Úµã
	MulCNode() {

	}
	friend MulCNode& operator* (const CalcNode& mul1, const CalcNode& mul2) {
		MulCNode ans;
		*ans.Result = *mul1.Result * *mul2.Result;
		return ans;
	}
	~MulCNode() {
		delete Result;
		Result = nullptr;
	}
};

#endif //COMPUTATIONAL_GRAPH_DOUCNODE_H
