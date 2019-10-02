#define CATCH_CONFIG_MAIN
#include <memory>
#include "catch.hpp"
#include "remove_duplicates.h"

TEST_CASE("Without additional memory") {
    std::forward_list<int> input {1, 2, 3, 4, 2, 3, 5, 4};
    RemoveDuplicatesWithoutAdditionalMemory(&input);
    std::forward_list<int> expected {1, 2, 3, 4, 5};
    REQUIRE(input == expected);
}

TEST_CASE("With additional memory") {
    std::forward_list<int> input {1, 2, 3, 4, 2, 3, 5, 4};
    RemoveDuplicatesWithAdditionalMemory(&input);
    std::forward_list<int> expected {1, 2, 3, 4, 5};
    REQUIRE(input == expected);
}

TEST_CASE("With simple custom linked list") {
    LinkedListNode<int> head = MakeList({1, 2, 3, 4, 2, 3, 5, 4});
    RemoveDuplicatesWithSimpleLinkedListNode(&head);
    LinkedListNode<int> expected = MakeList({1, 2, 3, 4, 5});
    REQUIRE(head == expected);
}