#include "Queue.h"
#include <stdexcept>
#include <vector>

template <typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}

template <typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
void Queue<T>::push(T value) {
    Node* newNode = new Node{value, nullptr};
    if (empty()) {
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    queueSize++;
}

template <typename T>
void Queue<T>::pop() {
    if (empty()) {
        cout << "Queue is empty, cannot pop!" << endl;
        return;
    }
    Node* temp = frontNode;
    frontNode = frontNode->next;
    delete temp;
    queueSize--;
    if (queueSize == 0) {
        rearNode = nullptr;
    }
}

template <typename T>
T Queue<T>::front() const {
    if (empty()) {
        throw runtime_error("Queue is empty!");
    }
    return frontNode->data;
}

template <typename T>
int Queue<T>::size() const {
    return queueSize;
}

template <typename T>
bool Queue<T>::empty() const {
    return queueSize == 0;
}

template <typename T>
void Queue<T>::move_to_rear() {
    if (empty()) {
        cout << "Queue is empty, cannot move to rear!" << endl;
        return;
    }
    T frontValue = front();
    pop();
    push(frontValue);
}

// Insertion Sort for the queue
template <typename T>
void Queue<T>::insertion_sort() {
    // Step 1: Extract elements into a vector
    vector<T> temp;
    while (!empty()) {
        temp.push_back(front());
        pop();
    }

    // Step 2: Perform insertion sort on the vector
    int i, j;
    T key;
    for (j = 1; j < temp.size(); j++) {
        key = temp[j];
        i = j - 1;
        while (i >= 0 && key < temp[i]) {
            temp[i + 1] = temp[i];
            i--;
        }
        temp[i + 1] = key;
    }

    // Step 3: Reinsert sorted elements back into the queue
    for (const auto& value : temp) {
        push(value);
    }
}

// Explicit template instantiation
template class Queue<int>;

// Recursive linear search function to find the last occurrence of a target in a vector
template <typename Item_Type>
int linear_search_last(const vector<Item_Type>& items, const Item_Type& target, size_t pos_first) {
    if (pos_first == items.size()) {
        return -1;
    }
    int pos_in_rest = linear_search_last(items, target, pos_first + 1);
    if (pos_in_rest != -1) {
        return pos_in_rest;
    }
    if (items[pos_first] == target) {
        return pos_first;
    }
    return -1;
}

// Explicit template instantiation for linear_search_last function
template int linear_search_last(const vector<int>& items, const int& target, size_t pos_first);