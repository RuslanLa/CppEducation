#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "urlify_string.h"

TEST_CASE("Simple") {
    {
        std::string str = "av fdb sdsds0000";
        Urlify(&str);
        REQUIRE(str == "av%20fdb%20sdsds");
    }
    {
        std::string str = "";
        Urlify(&str);
        REQUIRE(str == "");
    }
    {
        std::string str = "a 00";
        Urlify(&str);
        REQUIRE(str == "a%20");
    }
    {
        std::string str = " a 0000";
        Urlify(&str);
        REQUIRE(str == "%20a%20");
    }
}