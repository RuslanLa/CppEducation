#pragma once
#include "linked_list_node.h"


size_t Length(const LinkedListNode<int>* node) {
    auto& current = node;
    auto count = 1;
    while (current->Next != nullptr) {
        ++count;
        current = current->Next;
    }
    return count;
}

std::stack<int> GetStackFromHalfOfList(const LinkedListNode<int>*& node, size_t middle) {
    std::stack<int> result {};
    for (size_t i = 0; i < middle; i++) {
        result.push(node->Value);
        node = node->Next;
    }
    return result;
}

bool CheckIsEqual(const LinkedListNode<int>* node, std::stack<int>* stack) {
    while (!stack->empty()) {
        if (stack->top() != node->Value) {
            return false;
        }
        stack->pop();
        node = node->Next;
    }

    return true;
}

bool IsPalindrome(const LinkedListNode<int>& node){
    auto current_node = &node;
    auto size = Length(current_node);
    size_t middle = size / 2;
    auto stack = GetStackFromHalfOfList(current_node, middle);
    if (size % 2 != 0) {
        current_node = current_node->Next;
    }
    return CheckIsEqual(current_node, &stack);
}