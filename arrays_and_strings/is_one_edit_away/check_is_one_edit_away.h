#pragma once
#include <string_view>
// There are three types of edits that can be performed on strings: insert a character, remove a
// character, or replace a character.
// Given two strings, write a function to check if they are one edit (or zero edits) away.

bool CheckIsOneEditAway(std::string_view first, std::string_view second) {
    auto& bigger = first.size() > second.size() ? first : second;
    auto& smaller = first.size() > second.size() ? second : first;

    if (bigger.size() - 1 > smaller.size()) {
        return false;
    }
    auto bigger_position = bigger.begin();
    auto smaller_position = smaller.begin();
    auto difference_count = 0;
    auto allowed_differences = bigger.size() == smaller.size() ? 0 : 1;
    while (smaller_position != smaller.end()) {
        if (*smaller_position != *bigger_position) {
            ++difference_count;
        } else {
            ++smaller_position;
        }

        if (difference_count > allowed_differences) {
            return false;
        }

        ++bigger_position;
    }
    return true;
}