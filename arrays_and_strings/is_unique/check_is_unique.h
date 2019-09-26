#pragma once
#include <string>
#include <unordered_set>
#include <algorithm>
// Implement an algorithm to determine if a string has all unique characters.
// What if you cannot use additional data structures?

// works for any ASCII characters using O(N) additional memory with O(n) time
// complexity
inline bool CheckIsUniqueWithSet(std::string_view str) {
    std::unordered_set<char> characters_bag{};
    return std::all_of(str.begin(), str.end(), [&characters_bag](const char character) {
        auto existing = characters_bag.find(character);
        if (existing != characters_bag.end()) {
            return false;
        }
        characters_bag.insert(character);
        return true;
    });
}


// works only for ENGLISH Upper case ASCII characters using O(1) memory and O(n) time complexity
inline bool CheckIsUniqueWithBitset(std::string_view str){
    std::bitset<26> characters_bag {};
    return std::all_of(str.begin(), str.end(), [&characters_bag](const char character) {
        auto position = character - 'A';
        if (characters_bag.test(position)) {
            return false;
        }
        characters_bag.flip(position);
        return true;
    });
}