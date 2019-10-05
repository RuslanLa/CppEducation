#define CATCH_CONFIG_MAIN
#include <memory>
#include "catch.hpp"
#include "check_is_palindrome.h"

TEST_CASE("Not palindrome even length") {
    LinkedListNode<int> head = MakeList({1, 2, 3, 4, 2, 3, 5, 4});
    REQUIRE(!IsPalindrome(head));
}

TEST_CASE("Not palindrome odd length") {
    LinkedListNode<int> head = MakeList({1, 2, 3, 4, 2, 2, 3, 5, 4});
    REQUIRE(!IsPalindrome(head));
}

TEST_CASE("Palindrome with one node") {
    LinkedListNode<int> head = MakeList({1});
    REQUIRE(IsPalindrome(head));
}

TEST_CASE("Palindrome with even node") {
    LinkedListNode<int> head = MakeList({1, 2, 3, 3, 2, 1});
    REQUIRE(IsPalindrome(head));
}

TEST_CASE("Palindrome with odd node") {
    LinkedListNode<int> head = MakeList({1, 2, 3, 5, 3, 2, 1});
    REQUIRE(IsPalindrome(head));
}
