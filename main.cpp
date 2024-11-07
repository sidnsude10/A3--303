#include <iostream>
#include <vector>
#include "Queue.h"

using namespace std;

int main() {
    // Part 1: Queue Operations
    Queue<int> q;

    // a) Instantiate the queue with integers and push 10 values into the queue
    for (int i = 1; i <= 10; ++i) {
        q.push(i);
    }

    // b) Display all the elements in a queue using just the queue functions
    cout << "Queue elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    // Re-push elements to demonstrate move_to_rear function
    for (int i = 1; i <= 10; ++i) {
        q.push(i);
    }

    // c) Move the element currently at the front of the queue to the rear of the queue
    cout << "Moving front element to rear..." << endl;
    q.move_to_rear();

    // Display queue after move_to_rear operation
    cout << "Queue elements after move_to_rear: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    // Test recursive linear search function
    vector<int> items = {1, 3, 5, 3, 7, 9, 3};
    int target = 3;
    int last_pos = linear_search_last(items, target, 0);

    if (last_pos != -1) {
        cout << "The last occurrence of " << target << " is at index " << last_pos << endl;
    } else {
        cout << target << " not found in the vector." << endl;
    }

    // Part 2: Insertion Sort on Queue
    // Push some unsorted integers into the queue
    q.push(20);
    q.push(65);
    q.push(30);
    q.push(10);

    // Display elements before sorting
    cout << "Queue elements before sorting: ";
    for (int i = 0; i < 4; i++) { // Only display the 4 elements we added
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    // Reinsert the elements for sorting
    q.push(20);
    q.push(65);
    q.push(30);
    q.push(10);

    // Sort the queue
    q.insertion_sort();

    // Display elements after sorting
    cout << "Queue elements after sorting: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}