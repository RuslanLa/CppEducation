/*
 * Validate BST: Implement a function to check if a binary tree is a binary search tree.
 */


#include "Tree.h"
#include <iostream>


template <typename T>
bool isBinarySearchTree(BinaryTreeNode<T>* node, int min, int max){
    auto left {node->getLeft()};
    auto right {node->getRight()};

    auto leftIsBst = left == nullptr ? true : isBinarySearchTree(left, min, node->getValue());
    if(!leftIsBst){
        return false;
    }

    auto rigthIsBst = right == nullptr ? true : isBinarySearchTree(right, node->getValue(), max);
    if(!rigthIsBst) {
        return false;
    }

    return (left != nullptr ?  (left->getValue() <= node->getValue() && left->getValue() >= min) : true) && (right != nullptr ? (right->getValue() > node->getValue() && right->getValue() < max) : true);
}

template <typename T>
bool isBinarySearchTree(BinaryTreeNode<T>* node){
    return isBinarySearchTree(node, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

int main(){
    std::vector<int> from {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 , 10, 11, 12, 13, 14, 15};
    auto node { buildMinHeight(from) };
    std::cout << isBinarySearchTree(&node) << std::endl;

    std::vector<int> fromNotBinary {16, 1, 2, 3, 4, 5, 6, 7, 8, 9 , 10, 11, 12, 13, 14, 15};
    auto nodeNotBinary { buildMinHeight(fromNotBinary) };
    std::cout << isBinarySearchTree(&nodeNotBinary) << std::endl;

    BinaryTreeNode<int> head {5};
    head.insertNode(BinaryTreeNode<int> {1}, Location::Left);
    head.insertNode(BinaryTreeNode<int> {10}, Location::Right);
    head.getLeft()->insertNode(BinaryTreeNode<int> {6}, Location::Right);
    std::cout << isBinarySearchTree(&head) << std::endl;

}
