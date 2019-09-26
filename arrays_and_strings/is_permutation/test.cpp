#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "check_is_permutation.h"

TEST_CASE("Simple") {
    REQUIRE(CheckIsPermutation("abCdf", "Cdfba"));
    REQUIRE(!CheckIsPermutation("abCdf", "Fdfba"));
}