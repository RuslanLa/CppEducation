#ifndef CPPEDUCATION_TREE_H
#define CPPEDUCATION_TREE_H

#include <memory>
#include <vector>
#include <functional>

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

    void insertNode(T &&value, Location location){
        if(location == Location::Left){
            left = std::make_unique<BinaryTreeNode<T>>(value);
        }
        else{
            right = std::make_unique<BinaryTreeNode<T>>(value);
        }
    }
    BinaryTreeNode& getLeft() const {
        return *this->left;
    }

    BinaryTreeNode& getRight() const {
        return *this->right;
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
#endif //CPPEDUCATION_TREE_H
