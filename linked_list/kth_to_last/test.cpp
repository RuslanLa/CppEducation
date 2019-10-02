#define CATCH_CONFIG_MAIN
#include <memory>
#include "catch.hpp"
#include "find_kth_to_last.h"

TEST_CASE("Find kth") {
    LinkedListNode<int> head = MakeList({1, 2, 3, 4, 2, 3, 5, 4});
    REQUIRE(FindKthToLast(&head, 3)->Value == 3);
    REQUIRE(FindKthToLast(&head, 2)->Value == 5);
    REQUIRE(FindKthToLast(&head, 1)->Value == 4);
    REQUIRE(FindKthToLast(&head, 8)->Value == 1);
}
TEST_CASE("Find kth with forward list") {
    std::forward_list<int> head = {1, 2, 3, 4, 2, 3, 5, 4};
    REQUIRE(FindKthToLast(head, 3).value() == 3);
    REQUIRE(FindKthToLast(head, 2).value() == 5);
    REQUIRE(FindKthToLast(head, 1).value() == 4);
    REQUIRE(FindKthToLast(head, 8).value() == 1);
}
