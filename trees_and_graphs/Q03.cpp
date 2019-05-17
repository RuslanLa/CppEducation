#include <iostream>
#include <list>
#include "Tree.h"

/*
 * List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes at each depth
 * (e.g., if you have a tree with depth D, you'll have D linked lists).
 * */
template <typename T>
using ListOfDepth = std::list<std::list<BinaryTreeNode<T>*>>;

template <typename T>
ListOfDepth<T> buildListOfDepth(const BinaryTreeNode<T>& node){
    ListOfDepth<T> resultList {};
    traverseInBreadth<T>(node, [&resultList](const BinaryTreeNode<T>* node){
        resultList.back().push_back(const_cast<BinaryTreeNode<T>*>(node));
    }, [&resultList](int){
        resultList.push_back(std::list<BinaryTreeNode<T>*>{});
    });
    return resultList;
}

template <typename T>
void print(ListOfDepth<T>& list){
    auto num = 0;
    for(auto& innerList: list){
        std::cout << "level "<<num << ": ";
        for(auto node: innerList){
            std::cout << node->getValue() << ", ";
        }
        std::cout << std::endl;
        ++num;
    }
}

int main(){
    std::vector<int> from {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 , 10, 11, 12, 13, 14, 15};
    auto node { buildMinHeight(from) };
    std::cout<<"list of depth for "<<node << std::endl;
    auto listOfDepth = buildListOfDepth(node);
    print(listOfDepth);
}