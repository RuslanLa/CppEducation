#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "make_zero_matrix.h"

TEST_CASE("Matrix making zero") {
    {
        Matrix<int> input{
            {1, 2, 3, 4},
            {3, 4, 0, 4},
            {3, 4, 8, 4},
            {3, 4, 8, 4},
        };

        Matrix<int> expected {
            {1, 2, 0, 4},
            {0, 0, 0, 0},
            {3, 4, 0, 4},
            {3, 4, 0, 4},
        };
        MakeZeroMatrix(&input);
        REQUIRE(input == expected);
    }

    {
        Matrix<int> input{
            {0, 2, 3, 4},
            {3, 4, 0, 4},
            {3, 0, 8, 4},
            {3, 4, 8, 4},
        };

        Matrix<int> expected {
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 4},
        };

        MakeZeroMatrix(&input);
        REQUIRE(input == expected);
    }

        {
        Matrix<int> input{
            {1, 2, 3, 4},
            {3, 4, 1, 4},
            {3, 1, 8, 4},
            {3, 4, 8, 4},
        };

        Matrix<int> expected = input;

        MakeZeroMatrix(&input);
        REQUIRE(input == expected);
    }
}
