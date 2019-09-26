#pragma once
#include <string>


//Write a method to replace all spaces in a string with '%20'.
// You may assume that the string has sufficient space at the end to hold the additional characters,and that you are given the "true" length of the string.

inline void Urlify(std::string* str) {
    auto spaces_count = std::count(str->cbegin(), str->cend(), ' ');
    if (!spaces_count) {
        return;
    }

    auto last_valuable_character = str->end() - 1 - spaces_count*2;
    auto write_pointer = str->end() - 1;
    for (auto read_pointer = last_valuable_character; read_pointer >= str->begin();
    --read_pointer) {
        if (*read_pointer != ' ') {
            *write_pointer = *read_pointer;
            write_pointer--;
            continue;
        }
        *write_pointer = '0';
        --write_pointer;
        *write_pointer = '2';
        --write_pointer;
        *write_pointer = '%';
        --write_pointer;
    }
    return;
}