#include "linked_list_node.h"
#include <stack>
// Sum Lists: You have two numbers represented by a linked list, where each node contains a single
// digit.
// The digits are stored in reverse order, such that the 1 's digit is at the head of the list.
// Write a function that adds the two numbers and returns the sum as a linked list.
// EXAMPLE
// Input:(7-> 1 -> 6) + (5 -> 9 -> 2).Thatis,617 + 295. Output:2 -> 1 -> 9.Thatis,912.

LinkedListNode<int> SumListsReversed(const LinkedListNode<int>& first,
                                     const LinkedListNode<int>& second) {

    LinkedListNode<int> head{};
    LinkedListNode<int>* sum = &head;
    auto firs_node = &first;
    auto second_node = &second;
    bool remainder = false;

    while (firs_node != nullptr && second_node != nullptr) {
        auto current_sum = firs_node->Value + second_node->Value + remainder;
        remainder = current_sum >= 10;
        sum->Next = new LinkedListNode<int>();
        sum->Next->Value = current_sum % 10;
        sum = sum->Next;
        firs_node = firs_node->Next;
        second_node = second_node->Next;
    }

    auto remaining_node = firs_node == nullptr ? second_node : firs_node;
    while (remaining_node != nullptr) {
        sum->Next = new LinkedListNode<int>();
        sum->Next->Value = remaining_node->Value + remainder;
        remainder = false;
        sum = sum->Next;
        remaining_node = remaining_node->Next;
    }

    if (remainder) {
        sum->Next = new LinkedListNode<int>();
        sum->Next->Value = 1;
    }
    return *head.Next;
}


size_t Length(const LinkedListNode<int>& head) {
    auto current = &head;
    size_t length = 1;
    while (current->Next != nullptr) {
        length++;
        current = current->Next;
    }

    return length;
}

std::pair<const LinkedListNode<int>*, LinkedListNode<int>*> PutBiggestInResult(
    const LinkedListNode<int>* biggest_head, LinkedListNode<int>* result_head, long difference,
    std::stack<LinkedListNode<int>*>* result_stack) {
    for (size_t i = 0; i < abs(difference); i++) {
        result_head->Next = new LinkedListNode<int>();
        result_head = result_head->Next;
        result_head->Value = biggest_head->Value;
        biggest_head = biggest_head->Next;
        result_stack->push(result_head);
    }
    return std::make_pair(biggest_head, result_head);
}

bool CarryRemainders(std::stack<LinkedListNode<int>*>* result_stack) {
    auto remainder = false;
    while (!result_stack->empty()) {
        auto current = result_stack->top();
        result_stack->pop();
        current->Value += remainder;
        remainder = current->Value >= 10;
        current->Value %= 10;
    }
    return remainder;
}

void AddNodeWithOne(LinkedListNode<int>* head) {
    auto new_node = new LinkedListNode<int>();
    new_node->Value = 1;
    new_node->Next = head->Next;
    head->Next = new_node;
}

void SumListsOfEqualLength(const LinkedListNode<int>* first, const LinkedListNode<int>* second,
                           LinkedListNode<int>* result_it,
                           std::stack<LinkedListNode<int>*>* result_stack) {
    while (first != nullptr) {
        result_it->Next = new LinkedListNode<int>();
        result_it = result_it->Next;
        result_it->Value = first->Value + second->Value;
        first = first->Next;
        second = second->Next;
        result_stack->push(result_it);
    }
}
#
LinkedListNode<int> PadList(LinkedListNode<int>* list, size_t count) {
    if (count == 0) {
        return *list;
    }
    auto new_head = new LinkedListNode<int>();
    auto new_it = new_head;
    new_head->Value = 0;
    for (size_t i = 1; i < count; i++) {
        new_it->Next = new LinkedListNode<int>();
        new_it->Next->Value = 0;
        new_it = new_it->Next;
    }

    new_it->Next = list;
    return *new_head;
}

LinkedListNode<int> SumLists(LinkedListNode<int>& first, LinkedListNode<int>& second) {
    size_t first_length = Length(first); // 3
    size_t second_length = Length(second); // 6
    LinkedListNode<int> result{}; // {}->
    LinkedListNode<int>* result_it = &result; // {}
    auto [biggest_head, smallest_head] = first_length > second_length
                                             ? std::make_pair(&first, &second)
                                             : std::make_pair(&second, &first);
    long difference{static_cast<long>(first_length) - static_cast<long>(second_length)}; //3
    std::stack<LinkedListNode<int>*> result_stack{};
    auto padded_list = PadList(smallest_head, abs(difference));
    SumListsOfEqualLength(biggest_head, &padded_list, result_it, &result_stack);
    auto remainder = CarryRemainders(&result_stack);
    if (remainder) {
        AddNodeWithOne(&result);
    }
    return *result.Next;
}