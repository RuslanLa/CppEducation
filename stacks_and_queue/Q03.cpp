#include "SetOfStacks.h"
#include <iostream>
#include "utils.h"
int main() {
    SetOfStacks<int> stack (3, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
    stack.push(0);
    print(stack);
    SetOfStacks<int> secondStack (3, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
    secondStack.push(0);

    std::cout << secondStack.popAt(0) <<std::endl;
    print(stack);

}