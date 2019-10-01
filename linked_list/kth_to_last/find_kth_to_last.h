#include "linked_list_node.h"
#include <forward_list>
#include <optional>

template <typename TData>
LinkedListNode<TData>* MoveToKSteps(LinkedListNode<TData>* head, size_t k) {
    auto counter = 1;
    auto current = head;
    while (current->Next != nullptr && counter < k) {
        current = current->Next.get();
        ++counter;
    }

    if (counter != k) {
        return nullptr;
    }

    return current;
}

template <typename TData>
LinkedListNode<TData>* FindKthToLast(LinkedListNode<TData>* head, size_t k) {
    auto runner = head;
    runner = MoveToKSteps(runner, k);
    if (runner == nullptr) {
        return nullptr;
    }

    auto kth = head;

    while (runner->Next != nullptr) {
        runner = runner->Next.get();
        kth = kth->Next.get();
    }
    return kth;
}


template <typename TData>
typename std::forward_list<TData>::const_iterator MoveKStepsForward(const std::forward_list<TData>& list,
    size_t k) {
    auto current = list.begin();
    auto counter = 0;
    while (current != list.end() && counter < k) {
        ++current;
        ++counter;
    }

    return current;
}


template <typename TData>
std::optional<TData> FindKthToLast(const std::forward_list<TData>& list, size_t k) {
    auto fast = MoveKStepsForward(list, k);
    auto slow = list.begin();
    while (fast != list.end()) {
        ++slow;
        ++fast;
    }
    return std::make_optional(*slow);
}
