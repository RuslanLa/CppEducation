#ifndef CPPEDUCATION_LINKEDLISTUTILS_H
#define CPPEDUCATION_LINKEDLISTUTILS_H

#include <iostream>
#include <list>
#include "Node.h"
#include <forward_list>

template<typename T>
std::ostream& operator<<(std::ostream& out, std::forward_list<T> const& a)
{
    out << "[ ";

    for(auto x : a)
    {
        out << x << " ";
    }

    out << "]";
    return out;
}
int length(std::forward_list<int>& list){
    int count = 0;
    for(auto it = list.begin(); it != list.end(); it++){
        count++;
    }
    return count;
}

template <typename T>
size_t length(Node<T>* list) {
    size_t count = 0;
    Node<T>* node = list;
    while (node != nullptr) {
        count++;
        node = node->next;
    }
    return count;
}

#endif //CPPEDUCATION_LINKEDLISTUTILS_H
