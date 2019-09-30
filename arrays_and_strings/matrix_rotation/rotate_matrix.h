#pragma once
#include "matrix.h"

size_t CalculateLevelsCount (size_t dimension) {
    return dimension/2;
}

void Rotate(Matrix<int>* matrix) {
    auto dimensions = matrix->Rows();
    auto levels_count = CalculateLevelsCount(dimensions);
    for (size_t current_level = 0; current_level < levels_count; current_level++) {
        for (size_t i = 0; i < dimensions - 1 - current_level * 2; i++) {
            auto& top_left = matrix->at(current_level, current_level + i);
            auto& top_right = matrix->at(current_level + i, dimensions - 1 - current_level);
            auto& bottom_left = matrix->at(dimensions - 1 - current_level - i, current_level);
            auto& bottom_right =
                matrix->at(dimensions - 1 - current_level, dimensions - 1 - current_level - i);
            std::swap(top_left, top_right);
            std::swap(top_left, bottom_right);
            std::swap(bottom_left, top_left);
        }
    }
}