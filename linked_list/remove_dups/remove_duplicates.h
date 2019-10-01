#include <forward_list>
#include <list>
#include <algorithm>
#include "linked_list_node.h"
#include <iostream>

template <typename TData>
void RemoveDuplicatesWithoutAdditionalMemory(std::forward_list<TData>* data) {
    data->sort();
    data->unique();
}

template <typename TData>
void RemoveDuplicatesWithAdditionalMemory(std::forward_list<TData>* data) {
    std::set<TData> data_set {};
    auto current = data->begin();
    auto previous = data->begin();

    while (current != data->end()) {
        if (data_set.find(*current) != data_set.end()) {
            current = data->erase_after(previous);
        } else {
            data_set.insert(*current);
            previous = current;
            ++current;
        }
    }
}


template <typename TData>
void RemoveDuplicatesWithSimpleLinkedListNode(LinkedListNode<TData>* first_node) {
    std::set<TData> data_set {};
    data_set.insert(first_node->Value);
    LinkedListNode<TData>* current = first_node;
    while (current->Next != nullptr) {
        if (data_set.find(current->Next->Value) != data_set.end()) {
            current->Next = std::move(current->Next->Next);
        }
        else {
            data_set.insert(current->Next->Value);
            current = current->Next.get();
        }
    }
}