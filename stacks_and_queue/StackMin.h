#include <stack>
#include <iostream>
#ifndef CPPEDUCATION_STACKMIN_H
#define CPPEDUCATION_STACKMIN_H


template <typename T>
class StackMin : public std::stack<T> {
private:
    std::stack<T> minStack;
public:
    StackMin() = default;
    StackMin(std::initializer_list<T> list){
        for(auto it = list.end() - 1; it != list.begin() - 1; it--){
            this->push(*it);
        }
    }
    void push(const T& value){
        if(minStack.empty()){
            minStack.push(value);
        }
        if(minStack.top() >= value){
            minStack.push(value);
        }

        std::stack<T>::push(value);
    }

    T pop() {
        if(minStack.empty()){
            throw std::runtime_error("stack is empty");
        }
        auto topValue {std::stack<T>::top()};
        if(std::stack<T>::top() == minStack.top()){
            minStack.pop();
        }
        std::stack<T>::pop();
        return topValue;
    }

    T getMin() const {
        return minStack.top();
    }
};


#endif //CPPEDUCATION_STACKMIN_H