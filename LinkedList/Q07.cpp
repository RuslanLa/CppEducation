#include "Node.h"
#include "LinkedListUtils.h"
#include <utility>
#include <iostream>
#include <memory>

template <typename T>
void toSameLength(Node<T>*& firstHead, Node<T>*& secondHead){
    auto firstLength = length(*firstHead);
    auto secondLength = length(*secondHead);
    if(secondLength > firstLength){
        std::swap(firstHead, secondHead);
    }
    for(auto i = 0; i < abs(secondLength - firstLength); i++){
        firstHead = firstHead->next.get();
    }
}

template <typename T>
Node<T>* getIntersection(Node<T>* firstHead, Node<T>* secondHead) {
    toSameLength(firstHead, secondHead);
    while (firstHead != secondHead) {
        firstHead = firstHead->next.get();
        secondHead = secondHead->next.get();
    }
    return firstHead;
}

int main(){
    std::shared_ptr<Node<int>> intersection =  std::make_shared<Node<int>>(std::vector {1, 2, 3, 4, 5, 6});
    Node first  {std::vector {10, 11, 15, 14}};
    first.next->next->next->next = intersection;

    Node second {std::vector {12, 13}};
    second.next->next = intersection;

    Node<int>* intersectionResult = getIntersection(&first, &second);

    std::cout <<"intersection is " << intersectionResult->data << std::endl;

    intersectionResult = getIntersection(&second, &first);

    std::cout <<"intersection is " << intersectionResult->data << std::endl;
}