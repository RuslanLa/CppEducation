#include <iostream>
#include "Graph.h"

/**
 * Route Between Nodes: Given a directed graph, design an algorithm to find out whether there is a route between two nodes.
 */


template <typename TGraph>
TGraph createGraph(){
    TGraph graph {"0","1", "2", "3", "4", "5"};
    graph.bind(0, 1);
    graph.bind(0, 5);
    graph.bind(0, 4);
    graph.bind(1, 3);
    graph.bind(3, 4);
    return graph;
}

template <typename TGraph>
void test(TGraph& graph, int from, int to){
    std::cout << "presence of path from " << from << " to "<< to << " is " << (graph.existPath(from, to) ? "true" : "false") << std::endl;
}

int main(){
    auto directedGraph = createGraph<Graph<int>>();
    std::cout << "detecting pathes for a directed graph: "<<  directedGraph;
    test(directedGraph, 0, 3);
    test(directedGraph, 3, 1);
    test(directedGraph, 5, 5);


    auto indirectedGraph = createGraph<IndirectedGraph<int>>();
    std::cout << "detecting pathes for a indirected graph: "<<  indirectedGraph;
    test(indirectedGraph, 0, 3);
    test(indirectedGraph, 3, 1);
    test(indirectedGraph, 5, 5);
}