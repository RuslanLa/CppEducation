//
// Created by Akvelon on 5/13/2019.
//
#include <initializer_list>
#include <memory>
#ifndef CPPEDUCATION_UTILS_H
#define CPPEDUCATION_UTILS_H

template <typename TStack, typename TValue>
void fill(TStack& stack, std::initializer_list<TValue>&& list){
    for(auto it = list.end() - 1; it != list.begin() - 1; it--){
        stack.push(std::move(*it));
    }
}
#endif //CPPEDUCATION_UTILS_H
