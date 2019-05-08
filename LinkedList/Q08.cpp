#include <iostream>
#include <numeric>
#include "Node.h"
#include <memory>

/*
 * Loop detection:
 * Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.
 * DEFINITION Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so as to make a loop in the linked list.
 * EXAMPLE Input: A -> B -> C -> D -> E -> C [the same C as earlier] Output: C
 * */

template <typename  T>
Node<T>* getMeetPoint(Node<T>* head) {
    Node<T>* slow = head;
    Node<T>* fast = head->next;
    while(fast!= nullptr && fast->next!= nullptr && fast != slow){
        slow = slow->next;
        fast = fast->next->next;
    }
    return fast;
}

template <typename  T>
Node<T>* getMeetPoint(Node<T>* head, Node<T>* firstMeetPoint){
    auto headRunner = head;
    auto firstMeetPointRunner = firstMeetPoint;
    while (headRunner != firstMeetPointRunner){
        headRunner = headRunner->next;
        firstMeetPointRunner->next;
    }
    return headRunner;
}

template <typename  T>
Node<T>* findCycleBeginning(Node<T>* head){
    auto meetPoint = getMeetPoint(head);
    if(meetPoint == nullptr){
        return nullptr;
    }
    return getMeetPoint(head, meetPoint);
}

int main(){
    std::vector<int> v(17) ; // vector with 100 ints.
    std::iota (std::begin(v), std::end(v), 0);
    auto head = new Node<int>(std::move(v));
    Node<int>* cycleBeginning = head;
    for(int i = 0 ; i< 8; i++){
        cycleBeginning = cycleBeginning->next;
    }

    Node<int>* last = cycleBeginning->getLast();

    last->next = cycleBeginning;

    Node<int>* detectedBeginning = findCycleBeginning(head);

    if(detectedBeginning != nullptr) {
        std::cout << "Expected cycle beginning " << cycleBeginning->data << "; detected: " << detectedBeginning->data << std::endl;
    }
    else
    {
        std::cout << "Cycle isn't detected"<<std::endl;
    }
    delete head;
}