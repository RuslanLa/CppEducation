#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "check_is_one_edit_away.h"

TEST_CASE("Simple") {
    REQUIRE(CheckIsOneEditAway("cato", "cat"));
    REQUIRE(CheckIsOneEditAway("cat", "cat"));
    REQUIRE(CheckIsOneEditAway("cat", "ocat"));
    REQUIRE(!CheckIsOneEditAway("catd", "ocat"));
    REQUIRE(!CheckIsOneEditAway("cat", "ocato"));
    REQUIRE(!CheckIsOneEditAway("cat", "cat      "));
}