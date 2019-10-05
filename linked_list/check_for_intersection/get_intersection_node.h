#pragma once
#include "linked_list_node.h"

size_t Length(const LinkedListNode<int>& list) {
    auto it = list.Next;
    auto size = 1;
    while (it != nullptr) {
        ++size;
        it = it->Next;
    }

    return size;
}

void Skip(LinkedListNode<int>*& node, size_t num) {
    for (size_t i = 0; i < num; i++) {
        node = node->Next;
    }
}

LinkedListNode<int>* GetIntersection(LinkedListNode<int>& first, LinkedListNode<int>&
second) {
    auto first_it = &first;
    auto second_it = &second;
    auto first_size = Length(first);
    auto second_size = Length(second);
    if (first_size < second_size) {
        std::swap(first_it, second_it);
    }

    Skip(first_it, first_size > second_size ? first_size - second_size : second_size - first_size);
    while (first_it != nullptr) {
        if (first_it == second_it) {
            return first_it;
        }
        first_it = first_it->Next;
        second_it = second_it->Next;
    }

    return nullptr;
}