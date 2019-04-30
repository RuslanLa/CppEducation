#include <forward_list>
#include "LinkedListUtils.h"
#include <iostream>
#include <iterator>
#include <stack>
#include <algorithm>


/*
 * Palindrome: Implement a function to check if a linked list is a palindrome.
 */
template <typename T>
using Iterator = typename std::forward_list<T>::iterator;


template <typename T>
std::stack<T> buildStack(Iterator<T>& iterator, size_t length) {
    std::stack<T> stack{};
    int32_t lastIndex{static_cast<int32_t >(length / 2)};
    for (auto i = 0; i < lastIndex; i++) {
        stack.push(*iterator);
        ++iterator;
    }
    if(length % 2){
        ++iterator;
    }
    return stack;
}

template <typename T>
bool compare(Iterator <T>& listIt, std::stack<T>& stack) {
    while(!stack.empty()) {
        auto el = stack.top();
        stack.pop();
        if (*listIt != el) {
            return false;
        }
        ++listIt;
    }
    return true;
}

template <typename T>
bool isPalindrome(std::forward_list<T>& list, size_t length) {
    auto listIt = list.begin();
    std::stack<T> stack = buildStack<T>(listIt, length);
    return compare(listIt, stack);
}

template <typename T>
bool isPalindrome(std::forward_list<T>& list) {
    size_t size = length(list);
    return isPalindrome(list, size);
}

template <typename T>
void test(std::forward_list<T>&& list){
    std::cout << "checking for palindrome : " << list << " result " << isPalindrome(list) << std::endl;
}

int main(){
    test(std::forward_list<int32_t> {1, 2, 3, 4, 3, 2, 1});
    test(std::forward_list<int32_t> {'a', 'b', 'c', 'c', 'b', 'a'});
    test(std::forward_list<int32_t> {'a', 'b', 'c', 'd', 'b', 'a'});
}
