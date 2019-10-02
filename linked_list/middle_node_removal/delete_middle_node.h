#include "linked_list_node.h"


//Delete Middle Node: Implement an algorithm to delete a node in the middle
//(i.e., any node but the first and last node, not necessarily the exact middle) of a singly linked list, given only access to that node.
//EXAMPLE
//input:the node c from the linked lista->b->c->d->e->f
//Result: nothing is returned, but the new linked list looks likea->b->d->e- >f

template <typename TData>
void DeleteMiddleNode(LinkedListNode<TData>* node) {
    if (node->Next == nullptr) {
        throw std::runtime_error("DeleteMiddleNode doesn't work for last node");
    }
    auto current = node;
    auto prev = node;
    while (current->Next != nullptr) {
        current->Value = std::move(current->Next->Value);
        prev = current;
        current = current->Next;
    }
    prev->Next = nullptr;
}