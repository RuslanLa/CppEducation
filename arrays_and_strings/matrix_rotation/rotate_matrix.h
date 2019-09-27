#pragma once
#include <vector>

size_t CalculateLevelsCount (size_t dimension) {
    return dimension/2;
}

int& at(std::vector<int>* matrix, size_t i, size_t j, size_t dimensions) {
    return matrix->at(i * dimensions + j);
}

void Rotate(std::vector<int>* matrix) {
    // TODO: use more suitable data structure to not compute dimensions in such weird way
    auto dimensions = sqrt(matrix->size());
    auto levels_count = CalculateLevelsCount(dimensions);
    for (size_t current_level = 0; current_level < levels_count; current_level++) {
        for (size_t i = 0; i < dimensions - 1 - current_level * 2; i++) {
            auto& top_left = at(matrix, current_level, current_level + i, dimensions);
            auto& top_right =
                at(matrix, current_level + i, dimensions - 1 - current_level, dimensions);
            auto& bottom_left =
                at(matrix, dimensions - 1 - current_level - i, current_level, dimensions);
            auto& bottom_right = at(matrix, dimensions - 1 - current_level,
                                    dimensions - 1 - current_level - i, dimensions);
            std::swap(top_left, top_right);
            std::swap(top_left, bottom_right);
            std::swap(bottom_left, top_left);
        }
    }
}