#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "check_is_unique.h"

TEST_CASE("UNIQUE WITH SET") {
  REQUIRE(!CheckIsUniqueWithSet("aaa!"));
  REQUIRE(CheckIsUniqueWithSet("abcd!_"));
}
