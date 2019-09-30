#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "check_is_rotation.h"
#include <string>

TEST_CASE("String rotation") {
    REQUIRE(IsRotation("abasfdf", "fdfabas"));
    REQUIRE(IsRotation("a", "a"));
    REQUIRE(IsRotation("ab", "ba"));
    REQUIRE(!IsRotation("abascdf", "fdfabas"));
    REQUIRE(!IsRotation("sabafdf", "fdfabas"));
}
