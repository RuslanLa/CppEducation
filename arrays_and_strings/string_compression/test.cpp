#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "compress_string.h"
#include <string>

TEST_CASE("SMALL") {
    REQUIRE(Compress("").empty());
    REQUIRE(Compress("a") == "a");
    REQUIRE(Compress("aa") == "aa");
}

TEST_CASE("COMPRESSED") {
    std::string original {};
    original+= std::string(9, 'a');
    original+="caca";
    original+=std::string(40, 'b');
    REQUIRE(Compress(original)=="9a1c1a1c1a40b");
}

TEST_CASE("COMPRESSED_NOT_SMALLER") {
    REQUIRE(Compress("aabbcc") == "aabbcc");
    REQUIRE(Compress("aabcc") == "aabcc");
}