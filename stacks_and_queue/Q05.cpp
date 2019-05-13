#include <stack>
#include "utils.h"

/*
 * Sort Stack: Write a program to sort a stack such that the smallest items are on the top.
 * You can use an additional temporary stack, but you may not copy the elements into any other data structure (such as an array).
 * The stack supports the following operations: push, pop, peek, and is Empty.
 */


template<typename T>
void copyTo(std::stack<T>& from, std::stack<T>& to) {
    while (!from.empty()) {
        to.push(from.top());
        from.pop();
    }
}

template<typename T>
void sortStack(std::stack<T>& stack) {
    std::stack<T> tempStack{};
    tempStack.push(stack.top());
    stack.pop();
    while (!stack.empty()) {
        auto currentValue{stack.top()};
        stack.pop();
        if (tempStack.top() > currentValue) {
            copyTo(tempStack, stack);
        }
        tempStack.push(currentValue);
    }
    copyTo(tempStack, stack);
}

int main(){
    std::stack<int> stack {};
    fill(stack, {10, 50, 1, 2, 40, 40, 1, 3, 100, 99, 80});
    sortStack(stack);
    print(stack);
}