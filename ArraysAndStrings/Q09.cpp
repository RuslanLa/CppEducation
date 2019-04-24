#include <string>
#include <iostream>
using namespace std;

/*
 * String Rotation:Assumeyou have a method isSubstring, which checks ifoneword isa substring of another.
 * Given two strings, sl and s2, write code to check if s2 is a rotation of sl using only one call to isSubstring
 * (e.g., "waterbottle" is a rotation of"erbottlewat").
 */

bool isSubstring(const string& first, const string& second){
    return first.find(second) != string::npos;
}

bool isRotation(const string& first, const string& second){
    auto firstSize = first.size();
    auto secondSize = second.size();
    if(firstSize == 0 || secondSize != firstSize){
        return false;
    }
    string doubleFirst = first + first;
    return isSubstring(doubleFirst, second);
}

void test(const string& first, const string& second, bool expected){
    cout << "is rotation for "<< first <<" and "<< second << " should be " << expected << ": " << isRotation(first, second) << endl;
}

int main(){
    test("waterbottle", "erbottlewat", true);
    test("erbottlewat", "waterbottle", true);
    test("waterbottlea", "erbottlewat", false);
    test("waterbottde", "erbottlewat", false);
    test("eaterbottlw", "erbottlewat", false);
}
