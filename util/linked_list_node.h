#include <initializer_list>
#include <iostream>
#include <memory>


// memory management isn't a part of this data structure (only to make this data structure look
// like "classical" linked list
// MEMORY LEAKS ARE POSSIBLE
// ALSO PROPERLY CLASS DESIGN AND COPY CONSTRUCTOR WHICH MAKES REAL COPY - ISN'T THE PART OF TASK
template <typename T>
struct LinkedListNode {
    LinkedListNode<T>* Next = nullptr;
    T Value;
};

template <typename T>
LinkedListNode<T> MakeList(std::initializer_list<T> inializer_list) {
    if (inializer_list.size() == 0) {
        throw std::runtime_error("MakeList requires non-empty inializer_list");
    }

    auto it = inializer_list.begin();
    LinkedListNode<T> head {};
    head.Value = *it;
    head.Next = nullptr;
    auto current = &head;
    ++it;

    while (it!= inializer_list.end()) {
        current->Next = new LinkedListNode<T>();
        current->Next->Value = *it;
        current->Next->Next = nullptr;
        current = current->Next;
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
    return os;
}