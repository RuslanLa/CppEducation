#ifndef CPPEDUCATION_GRAPHNODE_H
#define CPPEDUCATION_GRAPHNODE_H

#include <string>
#include <vector>

template <typename T>
struct GraphNode {
    explicit GraphNode(std::string name):name(name){
    }
    std::string name;
    std::vector<GraphNode<T>*> relatedNodes {};
};


#endif //CPPEDUCATION_GRAPHNODE_H
