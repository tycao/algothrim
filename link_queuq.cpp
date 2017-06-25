#include "link_queue_node.h"
#include <assert.h>

template<typename T> void LinkQueue<T>::EnQueue(T& value)
{
    LinkQueueNode<T>* add = new LinkQueueNode<T>(value);
    if (back == nullptr)
        front = back = add; //添加第一个元素
    else
    {
        back->link = add;
        back = back->link;
    }
}
template<typename T> T LinkQueue<T>::DelQueue()
{
    assert(!IsEmpty());
    LinkQueueNode<T>* old = front;
    T data = old->data;
    front = front->link;
    if (back == old)
        back = nullptr;
    delete old;
    return data;
}
template<typename T> T& LinkQueue<T>::GetFront()
{
    assert(!IsEmpty());
    return front->data;
}
template<typename T> void LinkQueue<T>::MakeEmpty()
{
    while (!this->IsEmpty())
        this->DelQueue();
}
template<typename T> bool LinkQueue<T>::IsEmpty()
{
    return front == nullptr;
}
