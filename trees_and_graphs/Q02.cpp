#include <iostream>
#include "Tree.h"
#include <vector>

int main(){
    std::vector<int> from {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 , 10, 11};
    auto node { buildMinHeight(from) };
    std::cout << node << std::endl;
    std::cout << " height is "<< getMaxDepth(node) << std::endl;
    from = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 , 10, 11, 12};
    auto secondNode = buildMinHeight(from);
    std::cout << secondNode;
    std::cout << " height is "<< getMaxDepth(secondNode) << std::endl;
    return 0;
}