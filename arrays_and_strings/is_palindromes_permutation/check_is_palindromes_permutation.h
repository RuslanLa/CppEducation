#pragma once

bool CheckIsPalindromesPermutations(std::string_view str) {
    std::bitset<128> characters{};
    for (char character : str) {
        if (character == ' ') {
            continue;
        }
        characters.flip(character);
    }

    return characters.count() <= 1;
}