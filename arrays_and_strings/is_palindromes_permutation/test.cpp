#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "check_is_palindromes_permutation.h"

TEST_CASE("Simple") {
    REQUIRE(CheckIsPalindromesPermutations("taco cat"));
    REQUIRE(CheckIsPalindromesPermutations("tac cat"));
    REQUIRE(!CheckIsPalindromesPermutations("taco cat!"));
}