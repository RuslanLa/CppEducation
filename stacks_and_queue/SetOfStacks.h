#ifndef CPPEDUCATION_SETOFSTACKS_H
#define CPPEDUCATION_SETOFSTACKS_H

#include <initializer_list>
#include "utils.h"
#include <deque>
#include <vector>
#include <iostream>
/*
 * Stack of Plates: Imagine a (literal) stack of plates.
 * If the stack gets too high, it might topple. Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold.
 * Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity.
 * SetOfStacks. push() and SetOfStacks. pop() should behave identically to a single stack (that is, pop () should return the same values as it would if there were just a single stack).
 * FOLLOW UP Implement a function popAt(int index) which performs a pop operation on a specific substack.
 * */
template <typename T>
class SetOfStacks {
private:
    std::vector<std::deque<T>> stacks;
    int maxSize;
    void checkTop(){
        if(stacks.back().size() == maxSize){
            stacks.push_back(std::deque<T>{});
        }
    }
    T leftShift(unsigned int index, bool isFromTop){
        std::cout<<"popAt for stack " <<index<<std::endl;
        auto stack = stacks.begin()+index;
        auto value { isFromTop? stack->front() : stack->back() };
        std::cout<<"value " <<value<<std::endl;
        if(isFromTop) {
            stack->pop_front();
        }
        else{
            stack->pop_back();
        }
        if(stack->empty()){
            std::cout<<"remove empty stack" <<std::endl;
            stacks.erase(stacks.begin()+index);
            return value;
        }
        if(stack->size() < maxSize && index < stacks.size() - 1){
            std::cout<<"resize " <<std::endl;
            auto nextStackTopValue {leftShift(index+1, false)};
            std::cout << "moving "<<nextStackTopValue <<" from "<<index + 1 <<" to "<<index <<std::endl;
            stack->push_front(nextStackTopValue);
        }
        return value;
    }
public:
    SetOfStacks(int maxSizeOfSubStack, std::initializer_list<T> list):maxSize(maxSizeOfSubStack){
        fill(*this, std::move(list));
    }
    void push(const T& value) {
        if (stacks.empty()) {
            stacks.push_back(std::deque<T>{});
        }
        checkTop();
        stacks.back().push_front(value);
    }
    T pop(){
        auto returnValue = stacks.back().front();
        stacks.back().pop_front();
        if(stacks.back().empty()){
            stacks.erase(stacks.end()-1);
        }
        std::cout<<" remaining stacks count "<<stacks.size() << " ";
        return returnValue;
    }
    T popAt(unsigned int stackIndex){
        return leftShift(stackIndex, true);
    }
    bool isEmpty(){
        return stacks.empty();
    }
};

#endif //CPPEDUCATION_SETOFSTACKS_H
