#ifndef COMPUTATIONAL_GRAPH_NODE_H
#define COMPUTATIONAL_GRAPH_NODE_H

template<typename _T>
class Node
{
protected:
    _T *Result;
public:
    Node() : Result(nullptr) {};

    virtual _T GetVal() = 0; //获取节点的计算结果
    virtual void Clear() = 0;  //清除节点的计算结果

    virtual ~Node()
    {
        if (Result) {
            delete Result;
            Result = nullptr;
        }
    }
}


#endif //COMPUTATIONAL_GRAPH_NODE_H
