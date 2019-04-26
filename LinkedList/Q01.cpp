/*
 * Remove Dups! Write code to remove duplicates from an unsorted linked list.
 * */
#include <forward_list>
#include <set>
#include <iostream>
#include "LinkedListUtils.h"
#include <functional>
#include <string>
#include <iterator>


template <typename T>
void removeDuplicatesWithBuffer(std::forward_list<T>& list){
    std::set<T> nodesSet {};
    auto it = list.begin();
    auto prev = it;
    while(it!=list.end()) {
        auto existing = nodesSet.find(*it);
        if (existing == nodesSet.end()) {
            nodesSet.insert(*it);
            prev = it;
            it++;
            continue;
        }

        it = list.erase_after(prev);
    }
}

template <typename T>
void removeDuplicatesWithoutBuffer(std::forward_list<T>& list){
    auto itSlow = list.begin();
    for(; itSlow != list.end(); itSlow++){
        auto prev = itSlow;
        auto itFast = std::next(itSlow);
        while (itFast != list.end()){
            if(*itSlow == *itFast){
                itFast = list.erase_after(prev);
                continue;
            }
            prev = itFast;
            itFast++;
        }
    }
}


void test(const std::function<void (std::forward_list<int32_t>&)>& removeFunc, const std::string& methodName){
    std::forward_list<int32_t > values {1, 2, 3, 3, 4, 4, 5, 6, 6, 7, 7, 8 };
    std::cout << "before duplicates removing " << values << std::endl;
    removeFunc(values);
    std::cout << "after removing " << methodName << " " << values << std::endl;
}

int main(){
    test(removeDuplicatesWithBuffer<int32_t>, "with buffer");
    test(removeDuplicatesWithoutBuffer<int32_t>, "without buffer");
}