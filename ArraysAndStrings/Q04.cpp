
#include <string>
#include <algorithm>
#include <map>
#include <memory>
#include <iostream>
#include <functional>

using namespace std;

/*
 * Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome.
 * A palindrome is a word or phrase that is the same forwards and backwards.
 * A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
 * */

typedef map<char, int32_t> characters_entries;
unique_ptr<characters_entries> buildCharactersMap(const string& input);
bool checkCharacterForPalindrome(unique_ptr<characters_entries>& entries);

bool isPalindromePermutation(const string& input){
    auto characters = buildCharactersMap(input);
    return checkCharacterForPalindrome(characters);
}


uint32_t  createBitVector(const string& input);
bool testForPalindrome(uint32_t bitVector);

bool isPalindromePermutationWithBitMask(const string& input){
    auto bits = createBitVector(input);
    return testForPalindrome(bits);
}

void runTest(const std::function<bool(const string&)>& predicate);

int main(){
    cout << "test with map based implementation" << endl;
    runTest(isPalindromePermutation);
    cout << "test with bit vector based implementation" << endl;
    runTest(isPalindromePermutationWithBitMask);
}

void runTest(const std::function<bool(const string&)>& predicate){
    cout << "isPalindromePermutation for Tact Coa (should be 1) :" << predicate("Tact Coa") << endl;
    cout << "isPalindromePermutation for Tacta Coa (should be 0):" << predicate("Tacta Coa") << endl;
    cout << "isPalindromePermutation for Tactad Coa (should be 0) :" << predicate("Tactad Coa") << endl;
    cout << "isPalindromePermutation for tactcoapapa (should be 1) :" << predicate("tactcoapapa") << endl;
}

void setToZeroIfEmpty(unique_ptr<characters_entries>& map, char character) {
    auto existingPosition = map->find(character);
    if (existingPosition == map->end()) {
        (*map)[character] = 0;
    }
}

void increment(unique_ptr<characters_entries>& map, char character){
    setToZeroIfEmpty(map, character);
    (*map)[character]++;
}

unique_ptr<characters_entries> buildCharactersMap(const string& input){
    auto map = make_unique<characters_entries>();
    for(auto character:input){
        if(character == ' '){
            continue;
        }
        increment(map, tolower(character));
    }
    return map;
}

bool checkCharacterForPalindrome(unique_ptr<characters_entries>& entries){
    auto oddFound = false;
    for(auto& entry : *entries){
        if(entry.second % 2 == 1){
            if(oddFound){
                return false;
            }

            oddFound = true;
        }
    }
    return true;
}


char getAlphabeticalOrder(char character){
    return tolower(character) - 'a';
}

void invertCharacter(char character, uint32_t& result){
    uint32_t characterOrder = getAlphabeticalOrder(character);
    result^=(uint32_t)1<<characterOrder;
}

uint32_t createBitVector(const string& input) {
    uint32_t result = 0;
    for (auto character : input) {
        if(character == ' '){
            continue;
        }
        invertCharacter(character, result);
    }
    return result;
}

bool testForPalindrome(uint32_t bitVector){
    return (uint32_t)(bitVector - 1 & bitVector) == 0;
}


