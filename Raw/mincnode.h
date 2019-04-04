#ifndef COMPUTATIONAL_GRAPH_SINGCNODE_H
#define COMPUTATIONAL_GRAPH_SINGCNODE_H

#include"doucnode.h"

template<typename _T>
class MinCNode : public DUNCNode<_T> {//¼õ·¨½Úµã
	MinCNode() {

	}
	friend MinCNode& operator- (const CalcNode& sub1, const CalcNode& sub2) {
		MinCNode ans;
		*ans.Result = *sub1.Result - *sub2.Result;
		return ans;
	}
	~MinCNode() {
		delete Result;
		Result = nullptr;
	}
};

#endif //COMPUTATIONAL_GRAPH_DOUCNODE_H
