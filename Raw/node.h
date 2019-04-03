#ifndef COMPUTATIONAL_GRAPH_NODE_H
#define COMPUTATIONAL_GRAPH_NODE_H

template<typename _T>
class Node
{
private:
    _T *Result;
public:
    virtual _T GetVal() = 0; //获取节点的计算结果
    virtual _T Clear() = 0;  //清除节点的计算结果
};


#endif //COMPUTATIONAL_GRAPH_NODE_H
