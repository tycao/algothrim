#pragma once

template<typename T> class LinkQueueNode
{
public:
    T data;
    LinkQueueNode<T>* link;
    LinkQueueNode(T& value) : data(value), link(nullptr) {}
};

template<class T> class LinkQueue
{
public:
    LinkQueue() : front(nullptr), back(nullptr){}
    void EnQueue(T&);
    T DelQueue();
    T& GetFront();
    void MakeEmpty();
    bool IsEmpty();
private:
    LinkQueueNode<T>* front;
    LinkQueueNode<T>* back;
};
