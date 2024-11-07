#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* frontNode;
    Node* rearNode;
    int queueSize;

public:
    Queue();
    ~Queue();
    void push(T value);
    void pop();
    T front() const;
    int size() const;
    bool empty() const;
    void move_to_rear();
    void insertion_sort(); // Function to sort the queue
};

template <typename Item_Type>
int linear_search_last(const vector<Item_Type>& items, const Item_Type& target, size_t pos_first);

#endif
