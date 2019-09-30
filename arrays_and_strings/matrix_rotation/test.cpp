#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "matrix.h"
#include "rotate_matrix.h"
#include <vector>


TEST_CASE("1X1") {
  Matrix<int> matrix {{1}};
  Rotate(&matrix);
  Matrix<int> expected {{1}};
  REQUIRE(matrix == expected);
}

TEST_CASE("2X2") {
  Matrix<int> matrix({{1, 2}, {3, 4}});
  Rotate(&matrix);
  Matrix<int> expected({{3, 1}, {4, 2}});
  REQUIRE(matrix == expected);
}

TEST_CASE("3X3") {
  Matrix<int> matrix {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  Rotate(&matrix);
  Matrix<int> expected {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};
  REQUIRE(matrix == expected);
}

TEST_CASE("5X5") {
  Matrix<int> matrix {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20},
                      {21, 22, 23, 24, 25}};
  Rotate(&matrix);
  Matrix<int> expected {{21, 16, 11, 6, 1}, {22, 17, 12, 7, 2}, {23, 18, 13, 8, 3}, {24, 19, 14, 9,
                             4}, {25, 20, 15, 10, 5}};
  REQUIRE(matrix == expected);
}

TEST_CASE("4X4") {
  Matrix<int> matrix {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16 }};
  Rotate(&matrix);
  Matrix<int> expected {{13, 9, 5, 1}, {14, 10, 6, 2}, {15, 11, 7, 3}, {16, 12, 8, 4 }};
  REQUIRE(matrix == expected);
}

