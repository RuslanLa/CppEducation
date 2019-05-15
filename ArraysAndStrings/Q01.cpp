#include "TreeTest.h"
#include <string>
#include <vector>
#include <iostream>

/*
 * Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?
 * */
std::vector<bool> createSet(){
    std::vector<bool> characters(128);
    std::fill(characters.begin(), characters.end(), false);
    return characters;
}

bool isUnique(const std::string& input){
    auto characters = createSet();
    for(auto& character: input){
        size_t index = character - 'a';
        if(characters[index]){
            return false;
        }
        characters[index] = true;
    }
    return true;
}

int main() {
    std::cout << "is unique for zxcasdfgqwertymn" << " " << isUnique("zxcasdfgqwertymn")  << std::endl;
    std::cout << "is unique for zxcasdfgqwertymnzx" << " " << isUnique("zxcasdfgqwertymnzx")  << std::endl;
    return 0;
}