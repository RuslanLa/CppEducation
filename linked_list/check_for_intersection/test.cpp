#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "get_intersection_node.h"

TEST_CASE("Two not intersecting list with the same length") {
    LinkedListNode<int> first = MakeList({1, 2, 3, 4, 2});
    LinkedListNode<int> second = MakeList({1, 2, 3, 4, 2});
    REQUIRE(GetIntersection(first, second) == nullptr);
}

TEST_CASE("Two not intersecting list with different length") {
    LinkedListNode<int> first = MakeList({1, 2, 3, 4, 2});
    LinkedListNode<int> second = MakeList({1, 2, 3, 4, 2, 6, 7});
    REQUIRE(!GetIntersection(first, second));
}

TEST_CASE("Two equal lists") {
    LinkedListNode<int> first = MakeList({1, 2, 3, 4, 2});
    REQUIRE(GetIntersection(first, first) == &first);
}

TEST_CASE("Two intersecting lists with different lengths") {
    LinkedListNode<int> first = MakeList({1, 2, 3, 4, 2});
    auto second = LinkedListNode<int>();
    LinkedListNode<int> node {};
    LinkedListNode<int> another {};
    second.Next = &node;
    second.Next->Next = &another;
    second.Next->Next->Next = first.Next->Next;
    REQUIRE(GetIntersection(first, second) == first.Next->Next);
}