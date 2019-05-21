#include "Tree.h"
#include <iostream>

/*
 * Check Balanced: Implement a function to check if a binary tree is balanced.
 * For the purposes of this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any node never differ by more than one.
 * */
struct TreeBalanceInfo {
    bool isBalanced;
    int depth;
};
const TreeBalanceInfo notBalancedInfo {false, 0};

template <typename T>
TreeBalanceInfo getBalancedInfo(BinaryTreeNode<T>& head){
    int leftDepth = 0;
    int rightDepth = 0;
    auto right { head.getRight() };
    auto left { head.getLeft() };
    if(left!= nullptr){
        auto leftInfo = getBalancedInfo(*left);
        if(!leftInfo.isBalanced){
            return notBalancedInfo;
        }
        leftDepth = leftInfo.depth;
    }

    if(right != nullptr){
        auto rightInfo = getBalancedInfo(*right);
        if(!rightInfo.isBalanced){
            return notBalancedInfo;
        }
        rightDepth = rightInfo.depth;
    }

    if(abs(leftDepth - rightDepth)>1){
        return notBalancedInfo;
    }

    return TreeBalanceInfo {true, (rightDepth > leftDepth ? rightDepth: leftDepth)+1 };
}

template <typename T>
bool isBalanced(BinaryTreeNode<T>& head){
    auto balanceInfo = getBalancedInfo(head);
    return balanceInfo.isBalanced;
}

BinaryTreeNode<int> buildNotBalanced(){
    BinaryTreeNode<int> head {1};
    head.insertNode( BinaryTreeNode<int> {2},  Location::Left);
    head.insertNode( BinaryTreeNode<int> {3},  Location::Right);
    head.getRight()->insertNode( BinaryTreeNode<int> {4},  Location::Left);
    head.getRight()->getLeft()->insertNode( BinaryTreeNode<int> {5},  Location::Left);
    return head;
}

int main(){
    std::vector<int> from {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 , 10, 11, 12, 13, 14, 15};
    auto node { buildMinHeight(from) };
    std::cout<< isBalanced(node) << std::endl;
    auto notBalanced {buildNotBalanced()};
    std::cout<< isBalanced(notBalanced) << std::endl;
}