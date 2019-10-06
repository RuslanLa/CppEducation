#pragma once
#include "linked_list_node.h"

LinkedListNode<int>* MoveUntilCollied(const LinkedListNode<int>& node) {
    auto slow_runner = node.Next;
    if (slow_runner == nullptr) {
        return nullptr;
    }
    auto fast_runner = node.Next->Next;
    while (fast_runner != nullptr && fast_runner != slow_runner) {
        slow_runner = slow_runner->Next;
        if (fast_runner->Next != nullptr) {
            fast_runner = fast_runner->Next->Next;
        }
    }
    return fast_runner;
}

LinkedListNode<int>* DetectLoop(const LinkedListNode<int>& node) {
    auto first_runner = MoveUntilCollied(node);
    if (first_runner == nullptr) {
        return nullptr;
    }
    auto second_runner = &node;

    while (first_runner->Next != second_runner->Next) {
        first_runner = first_runner->Next;
        second_runner = second_runner->Next;
    }
    return first_runner->Next;
}