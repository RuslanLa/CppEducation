#include "Node.h"
#include "LinkedListUtils.h"
#include <utility>
#include <iostream>
#include <memory>


/*
 *  Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting node.
 *  Note that the intersection is defined based on reference, not value.
 *  That is, if the kth node of the first linked list is the exact same node (by reference) as the jth node of the second linked list, then they are intersecting
 * */
template <typename T>
void toSameLength(Node<T>*& firstHead, Node<T>*& secondHead){
    auto firstLength = length(firstHead);
    auto secondLength = length(secondHead);
    if(secondLength > firstLength){
        std::swap(firstHead, secondHead);
    }
    for(auto i = 0; i < abs(secondLength - firstLength); i++){
        firstHead = firstHead->next;
    }
}

template <typename T>
Node<T>* getIntersection(Node<T>* firstHead, Node<T>* secondHead) {
    toSameLength(firstHead, secondHead);
    while (firstHead != secondHead) {
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }
    return firstHead;
}

int main(){
    std::unique_ptr<Node<int>> intersection = std::make_unique<Node<int>>(std::vector {1, 2, 3, 4, 5, 6});
    std::unique_ptr<Node<int>> first  = std::make_unique<Node<int>>(std::vector {10, 11, 15, 14});
    first->next->next->next->next = intersection.get();
    std::unique_ptr<Node<int>> second = std::make_unique<Node<int>>(std::vector {12, 13});
    second->next->next = intersection.get();

    Node<int>* intersectionResult = getIntersection(first.get(), second.get());

    std::cout <<"intersection is " << intersectionResult->data << std::endl;

    intersectionResult = getIntersection(second.get(), first.get());

    std::cout <<"intersection is " << intersectionResult->data << std::endl;
}