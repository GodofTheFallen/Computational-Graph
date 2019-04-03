#ifndef COMPUTATIONAL_GRAPH_PHNODE_H
#define COMPUTATIONAL_GRAPH_PHNODE_H

#include "node.h"

template<typename _T>
class PHNode : public Node<_T>
{
public:

    _T GetVal();

    _T SetVal(_T);

    void Clear();
};


#endif //COMPUTATIONAL_GRAPH_PHNODE_H
