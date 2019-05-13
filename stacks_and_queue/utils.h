//
// Created by Akvelon on 5/13/2019.
//
#include <initializer_list>
#include <memory>
#include <iostream>
#ifndef CPPEDUCATION_UTILS_H
#define CPPEDUCATION_UTILS_H

template <typename TStack, typename TValue>
void fill(TStack& stack, std::initializer_list<TValue>&& list){
    for(auto it = list.end() - 1; it != list.begin() - 1; it--){
        stack.push(std::move(*it));
    }
}

template <typename TStack>
void print( TStack& stack) {
    while (!stack.empty()) {
        std::cout << stack.pop()<<std::endl;
    }
}

#endif //CPPEDUCATION_UTILS_H
