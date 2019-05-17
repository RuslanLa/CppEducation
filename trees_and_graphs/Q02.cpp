#include <iostream>
#include "Tree.h"
#include <vector>


template <typename T>
BinaryTreeNode<T> buildMinHeight(const std::vector<T>& data, size_t from, size_t to) {
    size_t middleIndex {(to + from)/2};
    T middleValue { data.at(middleIndex) };
    auto head {BinaryTreeNode<T> {middleValue}};
    if(from == to){
        return head;
    }
    if(middleIndex != from) {
        head.insertNode(buildMinHeight(data, from, middleIndex - 1), Location::Left);
    }
    if(middleIndex != to){
        head.insertNode(buildMinHeight(data, middleIndex+1, to), Location::Right);
    }
    return head;
}

template <typename T>
BinaryTreeNode<T> buildMinHeight(const std::vector<T>& data){
    auto head {buildMinHeight(data, 0, data.size()-1)};
    return head;
}

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