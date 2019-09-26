#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "check_is_unique.h"

TEST_CASE("UNIQUE WITH SET") {
  REQUIRE(!CheckIsUniqueWithSet("AAA!"));
  REQUIRE(CheckIsUniqueWithSet("ABCDs!_"));
}

TEST_CASE("UNIQUE WITH BIT SET") {
    REQUIRE(!CheckIsUniqueWithBitset("AAA"));
    REQUIRE(CheckIsUniqueWithBitset("ABCDS"));
}
