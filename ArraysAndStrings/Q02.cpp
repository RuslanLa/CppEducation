#include <string>
#include "Q02.h"
#include <map>
#include <algorithm>
#include <iostream>

/*
 * Given two strings, write a method to decide if one is a permutation of the other.
 * */
void setToZeroIfEmpty(std::map<char, int32_t>& map, char character) {
    auto existingPosition = map.find(character);
    if (existingPosition == map.end()) {
        map[character] = 0;
    }
}

std::map<char, int32_t> buildCharactersBag(const std::string& value){
    std::map<char, int32_t> charactersBag;
    for(auto character:value){
        setToZeroIfEmpty(charactersBag, character);
        charactersBag[character]++;
    }
    return charactersBag;
}

void reduceCharactersCount(std::map<char, int32_t>& charactersBag, const std::string& value) {
    for (auto character: value) {
        setToZeroIfEmpty(charactersBag, character);
        charactersBag[character]--;
    }
}

bool isPermutation(const std::string& first, const std::string& second) {
    if (first.size() != second.size()) {
        return false;
    }

    auto charactersBag = buildCharactersBag(first);
    reduceCharactersCount(charactersBag, second);
    return std::all_of(charactersBag.begin(), charactersBag.end(), [](auto entry) { return entry.second == 0; });
}

int main() {
    std::cout << "isPermutation for aba baa" << " " << isPermutation("aba", "baa")  << std::endl;
    std::cout << "isPermutation for abba baa" << " " << isPermutation("abba", "baa")  << std::endl;
    std::cout << "isPermutation for baa abba" << " " << isPermutation("baa", "abba")  << std::endl;
    std::cout << "isPermutation for bac abb" << " " << isPermutation("bac", "abba")  << std::endl;
    std::cout << "isPermutation for cabd adbc" << " " << isPermutation("cabd", "adbc")  << std::endl;

    return 0;
}