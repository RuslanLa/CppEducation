#pragma once
#include <string>


std::string Compress(const std::string& original) {
    if (original.size() < 3) {
        return original;
    }
    std::string result{};
    size_t sequence_length = 1;
    char previous_character = original[0];

    for (auto character = original.begin()+1; character != original.end(); ++character) {
        if (*character != previous_character) {
            result += std::to_string(sequence_length);
            result += previous_character;
            sequence_length = 1;
            previous_character = *character;
            continue;
        }

        ++sequence_length;
    }
    result += std::to_string(sequence_length);
    result += previous_character;

    return result.size() < original.size() ? result : original;
}