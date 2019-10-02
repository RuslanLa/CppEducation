#define CATCH_CONFIG_MAIN
#include <memory>
#include "catch.hpp"
#include "list_partition.h"

TEST_CASE("Simple") {
    LinkedListNode<int> head = MakeList({12, 3, 39, 11, 8, 7, 5, -3, 1000});
    auto new_head = Partition(&head, 10);
    LinkedListNode<int> expected = MakeList({3, 8, 7, 5, -3, 1000, 11, 39, 12});
    REQUIRE(*new_head == expected);
}

TEST_CASE("Only less") {
    LinkedListNode<int> head = MakeList({5, 8, 10, 11, 3, 12});
    auto new_head = Partition(&head, 12);
    LinkedListNode<int> expected = MakeList({5, 8, 10, 11, 3, 12});
    REQUIRE(*new_head == expected);
}

TEST_CASE("Only greater") {
    LinkedListNode<int> head = MakeList({13, 14, 15, 16});
    auto new_head = Partition(&head, 12);
    LinkedListNode<int> expected = MakeList({16, 15, 14, 13});
    REQUIRE(*new_head == expected);
}
