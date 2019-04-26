/*
 * Delete Middle Node: Implement an algorithm to delete a node in the middle
 * (i.e., any node but the first and last node, not necessarily the exact middle) of a singly linked list, given only access to that node.
 */

#include <forward_list>
#include "Node.h"
#include <vector>
#include <iostream>

template <typename T>
void deleteMiddleNode(Node<T>& middleNode){
    if(middleNode.next == nullptr){
        throw std::invalid_argument("Unable to delete node that doesn't have next node");
    }
    std::swap(middleNode, *middleNode.next);
}

int main(){
    std::vector<int32_t > vector {1, 2, 3, 4, 5};
    Node<int32_t> head (std::move(vector));
    std::cout << "before deletion " << head << std::endl;
    deleteMiddleNode(*head.next->next->next);
    std::cout << "after deletion " << head << std::endl;

    deleteMiddleNode(*head.next->next);
    std::cout << "after another deletion " << head << std::endl;

    deleteMiddleNode(head);
    std::cout << "after another one deletion " << head << std::endl;
}
