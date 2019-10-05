#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "sum_numbers_in_list.h"

TEST_CASE("Same length (reversed input)") {
    LinkedListNode<int> first = MakeList({7, 1, 6});
    LinkedListNode<int> second = MakeList({5, 9, 2});
    auto result = SumListsReversed(first, second);
    LinkedListNode<int> expected = MakeList({2, 1, 9});
    REQUIRE(result == expected);
}

TEST_CASE("Sum longer than arguments (reversed input)") {
    LinkedListNode<int> first = MakeList({7, 1, 6});
    LinkedListNode<int> second = MakeList({5, 9, 5});
    auto result = SumListsReversed(first, second);
    LinkedListNode<int> expected = MakeList({2, 1, 2, 1});
    REQUIRE(result == expected);
}

TEST_CASE("One shorter (reversed input)") {
    LinkedListNode<int> first = MakeList({7, 1, 6});
    LinkedListNode<int> second = MakeList({5, 9, 2, 4, 7, 2});
    auto result = SumListsReversed(first, second);
    LinkedListNode<int> expected = MakeList({2, 1, 9, 4, 7, 2});
    REQUIRE(result == expected);
}

TEST_CASE("Same length (not reversed input)") {
    LinkedListNode<int> first = MakeList({7, 1, 6});
    LinkedListNode<int> second = MakeList({5, 9, 2});
    auto result = SumLists(first, second);
    LinkedListNode<int> expected = MakeList({1, 3, 0, 8});
    REQUIRE(result == expected);
}

TEST_CASE("One shorter (not reversed input)") {
    LinkedListNode<int> first = MakeList({6, 1, 7});
    LinkedListNode<int> second = MakeList({2, 7, 4, 2, 9, 5});
    auto result = SumLists(first, second);
    LinkedListNode<int> expected = MakeList({2, 7, 4, 9, 1, 2});
    REQUIRE(result == expected);
}

TEST_CASE("Sum longer than arguments (not reversed input)") {
    LinkedListNode<int> first = MakeList({6, 1, 7});
    LinkedListNode<int> second = MakeList({4, 7, 4});
    auto result = SumLists(first, second);
    LinkedListNode<int> expected = MakeList({1, 0, 9, 1});
    REQUIRE(result == expected);
}

