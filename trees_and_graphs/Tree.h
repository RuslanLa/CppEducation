#ifndef CPPEDUCATION_TREE_H
#define CPPEDUCATION_TREE_H

#include <memory>
#include <vector>
#include <functional>
#include <iostream>
#include <queue>

/*
 * Minimal Tree: Given a sorted (increasing order) array with unique integer elements, write an algorithm to create a binary search tree with minimal height.
 */

template <typename T>
class ValueNode {
protected:
    T value;
public:
    const T &getValue() const {
        return value;
    }
    explicit ValueNode(T value):value(value){}
};


template <typename T>
class Node : public ValueNode<T> {
    std::vector<Node> nodes {};
public:
    explicit Node(T value):ValueNode<T>(value){}
    std::vector<Node>& getNodes() {
        return nodes;
    }

    void insertNode(T value) {
        this->nodes.push_back(Node{value});
    }

    void insertNodes(std::initializer_list<T> values) {
        for (auto& value : values) {
            this->insertNode(value);
        }
    }
};


enum class Location {
    Left,
    Right
};


template <typename T>
class BinaryTreeNode : public ValueNode<T> {
    std::unique_ptr<BinaryTreeNode<T>> left = nullptr;
    std::unique_ptr<BinaryTreeNode<T>> right = nullptr;
public:
    explicit BinaryTreeNode(T value):ValueNode<T>(value){}

    BinaryTreeNode(BinaryTreeNode<T>&& node) noexcept :ValueNode<T>(std::move(node.value)), left(std::move(node.left)), right(std::move(node.right)) {}

    void insertNode(T &&value, Location location){
        if(location == Location::Left){
            left = std::make_unique<BinaryTreeNode<T>>(std::move(value));
        }
        else{
            right = std::make_unique<BinaryTreeNode<T>>(std::move(value));
        }
    }
    void insertNode(BinaryTreeNode<T> &&node, Location location){
        if(location == Location::Left){
            left = std::make_unique<BinaryTreeNode<T>>(std::move(node));
        }
        else{
            right = std::make_unique<BinaryTreeNode<T>>(std::move(node));
        }
    }
    bool hasLeft() const {
        return this->left!= nullptr;
    }

    BinaryTreeNode& getLeft() const {
        return *this->left;
    }

    BinaryTreeNode& getRight() const {
        return *this->right;
    }
    bool hasRight() const {
        return this->right != nullptr;
    }
};

template <typename T>
void inOrderTraversal(BinaryTreeNode<T>* node, std::function<void (T)> callback){
    if(node != nullptr){
        inOrderTraversal(&(node->getLeft()), callback);
        callback(node->getValue());
        inOrderTraversal(&(node->getRight()), callback);
    }
}


template<typename T>
std::ostream& operator <<(std::ostream& os, BinaryTreeNode<T>& node){
    inOrderTraversal<T>(&node, [&os](T value){os<<"," <<value;});
    return os;
}

template <typename T>
void preOrderTraversal(BinaryTreeNode<T>* node, std::function<void (T)> callback){
    if(node != nullptr){
        callback(node->getValue());
        preOrderTraversal(&(node->getLeft()), callback);
        preOrderTraversal(&(node->getRight()), callback);
    }
}

template <typename T>
void postOrderTraversal(BinaryTreeNode<T>* node, std::function<void (T)> callback){
    if(node != nullptr){
        postOrderTraversal(&(node->getLeft()), callback);
        postOrderTraversal(&(node->getRight()), callback);
        callback(node->getValue());
    }
}

template <typename T>
void traverse(Node<T>& node, std::function<void (T)> callback){
    callback(node.getValue());
    for(auto& child : node.getNodes()){
        traverse(child, callback);
    }
}

template <typename T>
struct TraversingNodeInfo {
    const BinaryTreeNode<T> *node;
    int depth;
};

template <typename T>
int getMaxDepth(const BinaryTreeNode<T>& node){
    std::queue<TraversingNodeInfo<T>> traversingNodes {};
    traversingNodes.push(TraversingNodeInfo<T>{&node, 0});
    int maxDepth = 0;
    while (!traversingNodes.empty()){
        auto& current = traversingNodes.front();
        if(current.depth > maxDepth){
            maxDepth = current.depth;
        }
        if(current.node->hasLeft()){
            traversingNodes.push(TraversingNodeInfo<T>{&current.node->getLeft(), current.depth+1});
        }
        if(current.node->hasRight()){
            traversingNodes.push(TraversingNodeInfo<T>{&current.node->getRight(), current.depth+1});
        }
        traversingNodes.pop();
    }
    return maxDepth;
}
#endif //CPPEDUCATION_TREE_H
