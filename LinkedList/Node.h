#ifndef CPPEDUCATION_NODE_H
#define CPPEDUCATION_NODE_H

#include <vector>
#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next = nullptr;
    explicit Node(std::vector<T>&& vector);
    explicit Node(T&& value);
    ~Node();
    Node(Node<T>& node);
    Node(Node<T>&& node) noexcept;

    Node<T>* getLast();

    Node<T>& operator = (Node<T>&& anotherNode) noexcept;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, Node<T>& a){
    out<<a.data;
    if(a.next != nullptr){
        out << ", " << *a.next;
    }
    return out;
}

template <typename T>
Node<T>::Node(std::vector<T> &&vector) {
    if(vector.size() == 0){
        throw "Cannot initialize node from empty vector";
    }
    this->data = vector.at(0);
    auto prev = this;
    for(auto it = ++vector.begin(); it != vector.end(); it++ ){
        auto next = new Node<T>(std::move(*it));
        prev->next = next;
        prev = prev->next;
    }
    prev->next = nullptr;
}

template <typename T>
Node<T>::Node(T&& value):data(std::move(value)) {}

template <typename T>
Node<T>::Node(Node<T>&& anotherNode) noexcept:data(std::move(anotherNode.data)),next(std::move(anotherNode.next)) {}


template <typename T>
Node<T>::Node(Node<T>& node) {
    std::swap(data, node.data);
    std::swap(next, node.next);
}

template <typename T>
Node<T>& Node<T>::operator = (Node<T>&& anotherNode) noexcept {
    this->next = std::move(anotherNode.next);
    this->data = std::move(anotherNode.data);
    return *this;
}


template<typename T>
Node<T>::~Node() {
   std::cout << "destructor has been called for node " << data << std::endl;
   if(this->next!= nullptr) {
     //  delete this->next;
   }
}

template <typename T>
Node<T>* Node<T>::getLast() {
    if (this->next == nullptr) {
        return this;
    }
    return this->next->getLast();
}

#endif //CPPEDUCATION_NODE_H