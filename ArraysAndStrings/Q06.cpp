#include <string>
#include <vector>
#include <charconv>
#include <iostream>
using namespace std;


bool tryWriteToResult(string& result, int32_t count, char character, int32_t& position){
    auto countView =  to_string(count);
    if(countView.size() + position >= result.size() - 1){
        return false;
    }
    result.insert(position, countView);
    position += countView.size();
    result[position] = character;
    position += 1;
    return true;
}

string compress(const string& original){
    if(original.size() <= 3){
        return original;
    }

    auto result = string(original.size(), ' ');
    int32_t count = 1;
    int32_t resultIndex = 0;
    char prev = original[0];
    for(auto i = 1; i< original.size(); i++){
        if(original[i] == prev) {
            count++;
            continue;
        }
        auto countView =  to_string(count);
        if(!tryWriteToResult(result, count, prev, resultIndex)){
            return original;
        }
        prev = original[i];
        count = 1;
    }
    if(!tryWriteToResult(result, count, prev, resultIndex) || resultIndex == original.size()){
        return original;
    }
    result.resize(resultIndex);
    return result;
}


void print(const string& input){
    cout << "result for " << input << " is " << compress(input) << endl;
}

int main(){
    print("aabcccccaaa");
    print("aab");
}

