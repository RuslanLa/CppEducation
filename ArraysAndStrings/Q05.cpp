#include <string>
#include <iostream>
using namespace std;


enum class Mode{
    Skip,
    Replace
};


Mode getMode(string& first, string& second){
    Mode changeMode = Mode::Replace;
    if(first.size() != second.size()){
        changeMode = Mode::Skip;
    }
    if(first.size() < second.size()){
        swap(first, second);
    }
    return changeMode;
}

bool isOneEditAway(const string& first, const string& second, Mode mode){
    int32_t firstIndex = 0;
    int32_t secondIndex = 0;
    bool isEdited = false;
    while (secondIndex < second.size()){
        if(first[firstIndex] == second[secondIndex]){
            firstIndex++;
            secondIndex++;
            continue;
        }
        if(isEdited){
            return false;
        }
        isEdited = true;
        firstIndex++;
        if(mode == Mode::Replace){
            secondIndex++;
        }
    }
    return true;
}

bool isOneEditAway(string& first, string& second){
    Mode changeMode = getMode(first, second);
    return isOneEditAway(first, second, changeMode);
}

void printResult(string&& first, string&& second, bool expected){
    std::cout << "isOneEditAway for (" << first << ", " << second <<  ") (should be "<< expected << "): " << isOneEditAway(first, second) << endl;
}

int main(){
    printResult("pale", "ple", true);
    printResult("plea", "ple", true);
    printResult("pales", "pale", true);
    printResult("pale", "bale", true);
    printResult("pale", "bake", false);
}