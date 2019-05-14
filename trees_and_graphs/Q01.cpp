#include "Tree.h"
#include <iostream>

int main(){
    std::cout << "regular tree traversal:"<<std::endl;
    Node<int> node {1};
    node.insertNodes({2, 3, 4, 5, 6});
    node.getNodes().back().insertNodes({7, 8, 9});
    std::function<void (int)> print = [](int value) {
        std::cout << value << std::endl;
    };
    traverse(node, print);

    BinaryTreeNode<int> binaryHead {4};
    binaryHead.insertNode(2, Location::Left);
    binaryHead.insertNode(6, Location::Right);
    binaryHead.getLeft().insertNode(1, Location::Left);
    binaryHead.getLeft().insertNode(3, Location::Right);
    binaryHead.getRight().insertNode(5, Location::Left);
    binaryHead.getRight().insertNode(7, Location::Right);
    std::cout << "binary tree in order:"<<std::endl;
    inOrderTraversal(&binaryHead, print);
    std::cout << "binary tree pre order:"<<std::endl;
    preOrderTraversal(&binaryHead, print);
    std::cout << "binary tree post order:"<<std::endl;
    postOrderTraversal(&binaryHead, print);
}