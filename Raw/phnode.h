#ifndef COMPUTATIONAL_GRAPH_PHNODE_H
#define COMPUTATIONAL_GRAPH_PHNODE_H

#include <string>
#include "node.h"

template<typename _T>
class PHNode : public Node<_T>
{
private:
    const std::string ErrMsg = "Error: Placeholder missing";
public:
    using Node<_T>::Result;

    _T GetVal();

    _T SetVal(_T);

    void Clear();
};

template<typename _T>
_T PHNode<_T>::GetVal()
{
    if (!Result) throw ErrMsg;
    return *Result;
}

template<typename _T>
_T PHNode<_T>::SetVal(_T _Val)
{
    if (Result) *Result = _Val;
    else Result = new _T(_Val);
    return *Result;
}

template<typename _T>
void PHNode<_T>::Clear()
{
    Node<_T>::Clear();
}

#endif //COMPUTATIONAL_GRAPH_PHNODE_H
