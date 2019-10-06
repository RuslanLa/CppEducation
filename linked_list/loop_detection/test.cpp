#define CATCH_CONFIG_MAIN
#include <memory>
#include "catch.hpp"
#include "detect_loop.h"

TEST_CASE("Doesn't have loop") {
    LinkedListNode<int> head = MakeList({1, 2, 3, 4, 5, 6, 7, 8});
    REQUIRE(!DetectLoop(head));
}


LinkedListNode<int>* kth(const LinkedListNode<int>& head, size_t k) {
    auto it = &head;
    auto count = 1;
    while (it != nullptr && count < k) {
        ++count;
        it = it->Next;
    }
    return const_cast<LinkedListNode<int>*>(it);
}

TEST_CASE("With loop") {
    LinkedListNode<int> head = MakeList({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16});
    LinkedListNode<int> second_part = MakeList({17, 18, 19, 20});
    kth(head, 16)->Next = &second_part;
    kth(second_part, 4)->Next = kth(head, 16);
    REQUIRE(DetectLoop(head)->Value == 16);
}
