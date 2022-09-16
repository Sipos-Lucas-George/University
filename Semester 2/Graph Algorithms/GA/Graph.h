#pragma once

#include <map>
#include <utility>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <limits.h>

class Graph {
    private:
        std::map<int, std::vector<int>> outboundMap;
        std::map<int, std::vector<int>> inboundMap;
        std::map<std::pair<int, int>, int> costMap;
    public:
        // constructor
        explicit Graph(int nrVertices);

        // returns no nodes
        int nrNodes();

        // returns no arcs
        int nrArcs();

        // returns: true - if is node, false - otherwise
        bool isNode(int v);

        // returns: true - if is node, false - otherwise
        bool isArc(int v1, int v2);

        // returns the no inbound arcs
        int inDegree(int x);

        // returns the no outbound arcs
        int outDegree(int x);

        // returns a pair of 2 addresses reprezenting the beginning and the end of the vector 
        std::pair <std::vector<int>::iterator, std::vector<int>::iterator> inboundArc(int x);

        // returns a pair of 2 addresses reprezenting the beginning and the end of the vector
        std::pair <std::vector<int>::iterator, std::vector<int>::iterator> outboundArc(int x);

        // returns a pair of 2 addresses reprezenting the beginning and the of the map
        std::pair <std::map<int, std::vector<int>>::iterator , std::map<int, std::vector<int>>::iterator> setOfNodes();

        // changes the cost of an arc with a given value
        void changeCost(int x, int y, int val);

        // returns the cost of an arc
        int getCost(int x, int y);
        
        // adds an arc to the maps
        void addArc(int v1, int v2, int cost);

        // removes every information regarding a specific arc
        void removeArc(int x, int y);

        // adds a node to the maps
        void addNode(int val);

        // removes every information regarding a specific node
        void removeNode(int val);

        //finds a lowest length path between them, by using a backward bfs from the ending vertex
        std::vector<int> shortestPathBackwarkdBFS(int start, int end);

        //finds a lowest cost walk between the given vertices
        //or prints a message if there are negative cost cycles accessible from the starting vertex
        std::pair<int, std::map<int, int>> shortestWeightedPath(int start, int end);

        //verify if the corresponding graph is a DAG and performs a topological sorting of the activities 
        //using the algorithm based on predecessor counters (Kahn's algorithm)
        std::vector<int> topologicalSort();
        
        //highest cost path between two given vertices
        std::vector<int> highestCostPathWithTopologicalSort(std::vector<int> topOrder, int source);

        void displayCycle(int* path);

        bool isValid(int v, int k, int* path);

        bool cycleFound(int k, int* path);

        bool hamiltonianCycle();

        // print function
        std::string toString();

    private:
        
        //backward bfs
        std::map<int, int> backwardBFS(int end);
};
