
#include <forward_list>
#include <iostream>
#include <algorithm>
#include <iterator>
#include "LinkedListUtils.h"


void insertSum(std::forward_list<int>& result, std::forward_list<int>::iterator& iterator, int first, int second, int& remainder) {
    auto sum = first + second + remainder;
    remainder = sum / 10;
    result.insert_after(iterator, sum % 10);
    ++iterator;
}

std::forward_list<int> sumReverseOrdered(std::forward_list<int>& first, std::forward_list<int>& second){
    auto firstIt = first.begin();
    auto secondIt = second.begin();
    std::forward_list<int> result;
    auto insertIndex = result.before_begin();
    int remainder {0};
    while(firstIt != first.end() || secondIt != second.end()){
        auto firstValue = firstIt != first.end() ? *firstIt : 0;
        auto secondValue = secondIt != second.end() ? *secondIt : 0;
        insertSum(result, insertIndex, firstValue, secondValue, remainder);
        if(firstIt != first.end()){
            firstIt++;
        }

        if(secondIt != second.end()){
            secondIt++;
        }
    }
    return result;
}

void sumForward(std::forward_list<int>::iterator first, std::forward_list<int>::iterator firstEnd, std::forward_list<int>::iterator second, std::forward_list<int>::iterator secondEnd,
        std::forward_list<int>& result, int & carry) {
    if(first == firstEnd && second == secondEnd){
        return;
    }
    sumForward(first == firstEnd ? first : std::next(first, 1), firstEnd, second == secondEnd ? second : std::next(second, 1), secondEnd, result, carry);
    auto firstValue = first == firstEnd ? 0 : *first;
    auto secondValue = second == secondEnd ? 0 : *second;
    auto sum = firstValue + secondValue + carry;
    carry = sum / 10;
    result.push_front(sum%10);
}

int length(std::forward_list<int>& list){
    int count = 0;
    for(auto it = list.begin(); it != list.end(); it++){
        count++;
    }
    return count;
}

int determineBigAndSmall(std::forward_list<int>& big, std::forward_list<int>& small){
    auto bigLength = length(big);
    auto smallLength = length(small);
    if(bigLength < smallLength){
        std::swap(big, small);
    }

    return abs(bigLength - smallLength);
}

std::forward_list<int>::iterator padBig(std::forward_list<int>& first, std::forward_list<int>& result, int padding){
    auto resultIt = result.before_begin();
    auto bigIt = first.begin();
    for(auto bigIt = first.begin(); padding > 0; padding--, bigIt++) {
        resultIt = result.insert_after(resultIt, *bigIt);
    }
    return resultIt;
}

std::forward_list<int> sumForward(std::forward_list<int>& first, std::forward_list<int>& second){
    auto carry = 0;
    std::forward_list<int> result;
    auto padding = determineBigAndSmall(first, second);
    auto bigPaddedIt = padding == 0 ? first.begin() : std::next(first.begin(), padding);
    sumForward(bigPaddedIt, first.end(), second.begin(), second.end(), result, carry);
    auto prev = padBig(first, result, padding);
    if(carry){
        if(padding != 0){
            *prev = *prev + carry;
        }
        else {
            result.push_front(carry);
        }
    }
    return result;
}

int main(){
    std::forward_list<int> first {7, 1, 6};
    std::forward_list<int> second {5, 9, 2, 4};
    auto sum = sumReverseOrdered(first, second);
    std::cout << sum << std::endl;

    sum = sumForward(first, second);
    std::cout<< sum << std::endl;
    second = {5, 9, 2};
    sum = sumForward(first, second);
    std::cout<< sum << std::endl;

}
