#define CATCH_CONFIG_MAIN
#include <memory>
#include "catch.hpp"
#include "delete_middle_node.h"

TEST_CASE("With custom LinkedList node") {
    LinkedListNode<int> head = MakeList({1, 2, 3, 4, 5, 6, 7, 8, 9});
    DeleteMiddleNode(head.Next->Next->Next);
    LinkedListNode<int> expected = MakeList({1, 2, 3, 5, 6, 7, 8, 9});
    REQUIRE(head == expected);
}
