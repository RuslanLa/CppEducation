#include <stack>
#include <iostream>
#include "utils.h"
#include <memory>
#ifndef CPPEDUCATION_STACKMIN_H
#define CPPEDUCATION_STACKMIN_H


template <typename T>
class StackMin {
private:
    std::stack<T> minStack;
    std::stack<T> innerStack;
public:
    StackMin() = default;
    StackMin(std::initializer_list<T>&& list){
        fill(*this, std::move(list));
    }
    void push(const T& value){
        if(minStack.empty()){
            minStack.push(value);
        }
        if(minStack.top() >= value){
            minStack.push(value);
        }

        innerStack.push(value);
    }

    T pop() {
        if(minStack.empty()){
            throw std::runtime_error("stack is empty");
        }
        auto topValue {innerStack.top()};
        if(topValue == minStack.top()){
            minStack.pop();
        }
        innerStack.pop();
        return topValue;
    }

    T getMin() const {
        return minStack.top();
    }
    bool empty(){
        return innerStack.empty();
    }
};


#endif //CPPEDUCATION_STACKMIN_H