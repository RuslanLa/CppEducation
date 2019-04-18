#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
/*
 * URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters
 */

int32_t calculateSpacesCount(string& input) {
    return (int32_t) count_if(input.begin(), input.end(), [](char character) {
        return character == ' ';
    });
}

void urlify(string& input, size_t readIndex, size_t writeIndex) {
    while (readIndex > 0) {
        if (input[readIndex] == ' ') {
            input[writeIndex - 2] = '%';
            input[writeIndex - 1] = '2';
            input[writeIndex] = '0';
            readIndex--;
            writeIndex -= 3;
        }
        if (writeIndex != readIndex) {
            input[writeIndex] = input[readIndex];
        }
        writeIndex--;
        readIndex--;
    }
}


string urlify(string& input) {
    int32_t spacesCount = calculateSpacesCount(input) / 3;
    int32_t readIndex = input.length() - spacesCount * 2 - 1;
    int32_t writeIndex = input.length() - 1;
    urlify(input, readIndex, writeIndex);
    return input;
}

int main() {
    string input = "Mr John Smith    ";
    cout << urlify(input);

    return 0;
}
