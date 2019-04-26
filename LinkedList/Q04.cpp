
#include <forward_list>
#include <cstdint>
#include <iostream>
#include "LinkedListUtils.h"

/*
 * Partition: Write code to partition a linked list around a value x,
 * such that all nodes less than x come before all nodes greater than or equal to x.
 * If xis contained within the list the values of x only need to be after the elements less than x (see below).
 * The partition element x can appear anywhere in the "right partition";
 * it does not need to appear between the left and right partitions.
 * */

template <typename T>
void partitionList(std::forward_list<T>& list, T value){
    auto it = list.begin();
    std::forward_list<T> greaterValues {};
    auto prev = it;
    while (it != list.end()){
        if(*it < value){
            prev = it;
            it++;
            continue;
        }

        greaterValues.push_front(*it);
        if(prev == it) {
            prev = ++it;
            list.pop_front();
        }
        else{
            it = list.erase_after(prev);
        }
    }
    list.merge(greaterValues);
}

int main(){
    std::forward_list<int32_t> list {3, 5, 8, 5, 10, 2, 1 };
    std::cout << "list before: " << list << std::endl;
    partitionList(list, 5);
    std::cout << "list after: " << list << std::endl;
}