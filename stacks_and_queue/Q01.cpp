#include <iostream>
#include "StackMin.h"

int main(){
    StackMin<int> stack = {1, 3, 3, 2, 2, 2, 4, 55, 6};
    stack.push(0);
    while (!stack.empty()) {
        std::cout << "min is " << stack.getMin() << " top is " << stack.pop() << std::endl;
    }
}