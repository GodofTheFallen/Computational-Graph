#ifndef COMPUTATIONAL_GRAPH_SINGCNODE_H
#define COMPUTATIONAL_GRAPH_SINGCNODE_H

#include"doucnode.h"

template<typename _T>
class DivCNode : public DUNCNode<_T> {//³ý·¨½Úµã
	DivCNode() {

	}
	friend DivCNode& operator/ (const CalcNode& div1, const CalcNode& div2){
		DivCNode ans;
		if (*div2.Result == 0) {
			std::cout << "error!" << std::endl;
			ans.Result = nullptr;
		}
		else {
			*ans.Result = *div1.Result / *div2.Result;
			return ans;
		}
	}
	~DivCNode() {
		delete Result;
		Result = nullptr;
	}
};

#endif //COMPUTATIONAL_GRAPH_DOUCNODE_H
