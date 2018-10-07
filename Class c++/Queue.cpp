#include <iostream>
#include <vector>
#include <deque>
using namespace std;

template <typename T, typename Container = deque<T>>
class Queue {
private:
    Container q;

public:
    Queue() {}

    T front() const {
        return *q.front();
    }

    T& front() {
        return *q.begin();
    }

    void pop() {
        q.pop_front();
    }

    void push(T a) {
        q.push_back(a);
    }

    int size() {
        return q.size();
    }

    bool empty() {
        return q.size() == 0;
    }

    bool operator == (const Queue& other) {
        return q == other.q;
    }

    bool operator != (const Queue& other) {
        return q != other.q;
    }
};