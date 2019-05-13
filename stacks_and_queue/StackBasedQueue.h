#include <stack>

#ifndef CPPEDUCATION_STACKBASEDQUEUE_H
#define CPPEDUCATION_STACKBASEDQUEUE_H

template <typename T>
class StackBasedQueue {
private:
    std::stack<T> innerStack;
    bool isReversed = false;

    void reverse() {
        std::stack<T> temp;
        while (!innerStack.empty()) {
            temp.push(innerStack.top());
            innerStack.pop();
        }
        temp.swap(innerStack);
        isReversed = !isReversed;
    }

public:
    void push(const T &value) {
        if (isReversed) {
            reverse();
        }
        innerStack.push(value);
    }

    T pop() {
        if (!isReversed) {
            reverse();
        }
        auto returnValue = innerStack.top();
        innerStack.pop();
        return returnValue;
    }
    bool empty(){
        return innerStack.empty();
    }
};

#endif //CPPEDUCATION_STACKBASEDQUEUE_H
