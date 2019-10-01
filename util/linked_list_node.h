#include <initializer_list>
#include <iostream>
#include <memory>

template <typename T>
struct LinkedListNode {
    using NodePtr = std::unique_ptr<LinkedListNode<T>>;
    NodePtr Next = nullptr;
    T Value;
};

template <typename T>
std::unique_ptr<LinkedListNode<T>> MakeList(std::initializer_list<T> inializer_list) {
    if (inializer_list.size() == 0) {
        throw std::runtime_error("MakeList requires non-empty inializer_list");
    }

    auto it = inializer_list.begin();
    auto head = std::make_unique<LinkedListNode<T>>();
    head->Value = *it;
    head->Next = nullptr;
    auto current = head.get();
    ++it;

    while (it!= inializer_list.end()) {
        current->Next = std::make_unique<LinkedListNode<T>>();
        current->Next->Value = *it;
        current->Next->Next = nullptr;
        current = current->Next.get();
        ++it;
    }

    return head;
}

template <typename TData>
bool operator==(const LinkedListNode<TData>& rhs, const LinkedListNode<TData>& lhs) {
    return rhs.Value == lhs.Value &&
           ((lhs.Next == nullptr && rhs.Next == nullptr) ||
            (lhs.Next != nullptr && rhs.Next != nullptr && *lhs.Next == *rhs.Next));
}

template <typename TData>
std::ostream& operator<<(std::ostream& os, const LinkedListNode<TData> node) {
    auto node_pointer = node.Next;
    os << "{";
    os << node.Value;
    while (node_pointer != nullptr) {
        os << ", " << node_pointer->Value;
        node_pointer = node_pointer->Next;
    }
    os << "}";
}