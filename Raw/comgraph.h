#ifndef COMPUTATIONAL_GRAPH_COMGRAPH_H
#define COMPUTATIONAL_GRAPH_COMGRAPH_H

#include <map>
#include "connode.h"
#include "phnode.h"
#include "basic_calc_pack.h"
#include "advanced_calc_pack.h"
#include "compare_calc_pack.h"
#include "prinode.h"



using namespace std;

template<typename _T>
class ComGraph
{
private:
    map<string, Node<_T> *> Index;
_T
    _T SetNodeVal(Node<_T> *, _T);

public:


};


#endif //COMPUTATIONAL_GRAPH_COMGRAPH_H
