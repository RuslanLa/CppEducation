#include "linked_list_node.h"

//Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x.
//If x is contained within the list, the values of x only need to be after the elements less than x (see below).
//The partition element x can appear anywhere in the "right partition"; it does not need to appear between the left and right partitions.


//12 3 39 11 8 -> 7 -> 5 ->  -3 -> 1000
LinkedListNode<int>* Partition(LinkedListNode<int>* list, int value) {
    LinkedListNode<int>* first_less = nullptr; // 3
    LinkedListNode<int>* last_less = nullptr;  // 3
    LinkedListNode<int>* greater_or_equal = nullptr; // 39 -> 12
    auto current = list; // 7
    while (current != nullptr) {
        auto next = current->Next; // 5
        if (current->Value < value) {
            if (first_less == nullptr) {
                first_less = current; // 3
                last_less = current; // 3 -> 8
            } else {
                last_less->Next = current; // 3->8
                last_less = current;
            }
        } else {
            current->Next = greater_or_equal; // 11 -> 39 -> 12
            greater_or_equal = current; // 11
        }
        current = next; // 7
    }

    if (last_less == nullptr) {
        return greater_or_equal;
    }
    last_less->Next = greater_or_equal;
    return first_less;
}


// 12 -> 3 -> 39 -> 11 -> 8 -> 7 -> 5 ->  -3 -> 1000      10
// left: 3->8->7->5->-3
// right: 1000->11->39->12

