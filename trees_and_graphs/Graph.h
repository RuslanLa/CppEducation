#ifndef CPPEDUCATION_GRAPH_H
#define CPPEDUCATION_GRAPH_H

#include "GraphNode.h"
#include <memory>
#include <vector>
#include <map>
#include <queue>
#include <set>

template <typename T>
struct GraphTraversalInformation {
    GraphTraversalInformation(int from , GraphNode<T>* node): visitedFromSide(from), node(node){}
    int visitedFromSide;
    GraphNode<T>* node;
};

template <typename T>
struct Graph {
protected:
    std::vector<GraphNode<T>> nodes{};
public:
    friend std::ostream &operator<<(std::ostream &os, Graph<T> &graph) {
        for (auto &node : graph.nodes) {
            std::cout << node.name << " -> ";
            for (auto relatedNode : node.relatedNodes) {
                std::cout << relatedNode->name << " ";
            }
            std::cout << std::endl;
        }
        return os;
    };

    Graph(std::initializer_list<std::string> names) {
        this->nodes = {};
        for (auto &name : names) {
            this->nodes.push_back(GraphNode<T>(name));
        }
    }
    virtual void bind(int from, int to) {
        this->nodes[from].relatedNodes.push_back(&nodes.at(to));
    }

    virtual bool existPath(int from, int to) {
        std::queue<GraphNode<T> *> nodesToVisit{};
        nodesToVisit.push(&this->nodes.at(from));
        std::set<GraphNode<T> *> visited{};
        visited.insert(&this->nodes.at(from));
        auto &toName = this->nodes.at(to).name;
        while (!nodesToVisit.empty()) {
            auto &node = nodesToVisit.front();
            for (auto related : node->relatedNodes) {
                if (related->name == toName) {
                    return true;
                }
                if (visited.find(related) == visited.end()) {
                    nodesToVisit.push(related);
                    visited.insert(related);
                }
            }
            nodesToVisit.pop();
        }
        return false;
    }
};

template <typename T>
class IndirectedGraph : public Graph<T> {
public:
    IndirectedGraph(const std::initializer_list<std::string> &names) : Graph<T>(names) {}

    virtual bool existPath(int from, int to) {
        std::map<GraphNode<T> *, int> visitedNodes{};
        std::queue<GraphTraversalInformation<T>> nodesToVisit{};
        nodesToVisit.push(GraphTraversalInformation(0, &(this->nodes.at(from))));
        nodesToVisit.push(GraphTraversalInformation(1, &(this->nodes.at(to))));
        while (!nodesToVisit.empty()) {
            GraphTraversalInformation<T> &nodeVisitInfo = nodesToVisit.front();
            auto existingNode = visitedNodes.find(nodeVisitInfo.node);
            if (existingNode != visitedNodes.end()) {
                if ((*existingNode).second != nodeVisitInfo.visitedFromSide) {
                    return true;
                }
            } else {
                visitedNodes[nodeVisitInfo.node] = nodeVisitInfo.visitedFromSide;
            }
            for (auto child : nodeVisitInfo.node->relatedNodes) {
                nodesToVisit.push(GraphTraversalInformation(nodeVisitInfo.visitedFromSide, child));
            }
            nodesToVisit.pop();
        }
        return false;
    }

    void bind(int from, int to) override {
        this->nodes[from].relatedNodes.push_back(&(this->nodes.at(to)));
        this->nodes[to].relatedNodes.push_back(&(this->nodes.at(from)));
    }
};


template <typename T>
std::ostream& operator << (std::ostream& os, Graph<T>& graph){
    for(auto& node : graph.nodes){
        std::cout << node.name << " -> ";
        for(auto relatedNode : node.relatedNodes){
            std::cout << relatedNode->name;
        }
        std::cout << std::endl;
    }
    return os;
}

#endif //CPPEDUCATION_GRAPH_H
