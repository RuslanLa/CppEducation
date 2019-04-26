#include <forward_list>
#include <iterator>
#include <iostream>

/*
 * Return Kth to Last: Implement an algorithm to find the kth to last element of a singly linked list.
 */

template <typename  T>
auto nthLast(const std::forward_list<T>& list, int32_t n){
    auto fast = ++list.begin();
    for(auto i = 0; i < n; i++){
        fast++;
    }
    auto slow = list.begin();
    while (fast != list.end()){
        fast++;
        slow++;
    }
    return slow;
}

void test(const std::forward_list<int32_t> & list, int32_t n, int32_t expected){
    std::cout << n <<"th last should be: " << expected << " actual: " << *nthLast(list, n) << std::endl;
}

int main() {
    std::forward_list<int32_t> list{1, 2, 3, 4, 5,};
    test(list, 0, 5);
    test(list, 1, 4);
    test(list, 2, 3);
    test(list, 3, 2);
    test(list, 4, 1);
}