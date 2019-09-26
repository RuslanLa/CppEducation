#pragma once
#include <string_view>
#include <unordered_map>

// Check if the two strings have identical character counts.
//assuming that
bool CheckIsPermutation(const std::string_view first_str, const std::string_view second_str) {
    std::map<char, size_t> character_entrance{};
    for (auto character : first_str) {
        ++character_entrance[character];
    }

    for (auto character : second_str) {
        --character_entrance[character];
    }

    return std::all_of(character_entrance.begin(), character_entrance.end(),
                       [](auto entrance) { return entrance.second == 0; });
}