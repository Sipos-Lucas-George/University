#include "Graph.h"
#include <exception>
#include <iostream>

Graph::Graph(int nrVertices) {
    for (int i = 0; i < nrVertices; ++i) {
        inboundMap[i] = std::vector<int>();
        outboundMap[i] = std::vector<int>();
    }
}

int Graph::nrNodes() {
    return (int)(outboundMap.size());
}

int Graph::nrArcs() {
    return (int)(costMap.size());
}

bool Graph::isNode(int v) {
    return inboundMap.find(v) != inboundMap.end();
}

bool Graph::isArc(int v1, int v2) {
    return std::find(outboundMap[v1].begin(), outboundMap[v1].end(), v2) != outboundMap[v1].end();
}

int Graph::inDegree(int x) {
    return (int)(inboundMap[x].size());
}

int Graph::outDegree(int x) {
    return (int)(outboundMap[x].size());
}

std::pair <std::vector<int>::iterator, std::vector<int>::iterator> Graph::inboundArc(int x) {
    return std::make_pair(inboundMap[x].begin(), inboundMap[x].end());
}

std::pair<std::vector<int>::iterator, std::vector<int>::iterator> Graph::outboundArc(int x) {
    return std::make_pair(outboundMap[x].begin(), outboundMap[x].end());
}

std::pair<std::map<int, std::vector<int>>::iterator , std::map<int, std::vector<int>>::iterator> Graph::setOfNodes() {
    return std::make_pair(outboundMap.begin(), outboundMap.end());
}

void Graph::changeCost(int x, int y, int val) {
    if (!isArc(x, y)) {
        throw std::exception();
    }
    this->costMap[std::make_pair(x, y)] = val;
}

int Graph::getCost(int x, int y) {
    if (!isArc(x, y)) {
        throw std::exception();
    }
    return costMap[std::make_pair(x, y)];
}

void Graph::addArc(int v1, int v2, int cost) {
    if (!isNode(v1) || !isNode(v2) || isArc(v1, v2)) {
        throw std::exception();
    }
    costMap[std::make_pair(v1, v2)] = cost;
    outboundMap[v1].push_back(v2);
    inboundMap[v2].push_back(v1);
}

void Graph::removeArc(int x, int y) {
    if (!isArc(x, y)) {
        throw std::exception();
    }
    for (auto &elem : costMap) {
        if (y == elem.first.second && x == elem.first.first) {
            costMap.erase(elem.first);
            break;
        }
    }
    inboundMap[y].erase(std::find(inboundMap[y].begin(), inboundMap[y].end(), x));
    outboundMap[x].erase(std::find(outboundMap[x].begin(), outboundMap[x].end(), y));
}

void Graph::addNode(int val) {
    if (isNode(val)) {
        throw std::exception();
    }
    inboundMap[val] = std::vector<int>();
    outboundMap[val] = std::vector<int>();
}

void Graph::removeNode(int val) {
    if (!isNode(val)) {
        throw std::exception();
    }

    for (auto& elem : inboundMap[val])
        costMap.erase(costMap.find(std::make_pair(elem, val)));
    for (auto& elem : outboundMap[val])
        costMap.erase(costMap.find(std::make_pair(val, elem)));

    inboundMap.erase(inboundMap.find(val));
    outboundMap.erase(outboundMap.find(val));
}

std::map<int, int> Graph::backwardBFS(int end) {
    std::queue<int> queue;
    queue.push(end);
    std::map<int, int> distances;
    std::set<int> visited;
    visited.insert(end);
    distances[end] = 0;
    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();
        for (auto x : this->inboundMap[current]) {
            if (visited.count(x) == 0) {
                visited.insert(x);
                queue.push(x);
                distances[x] = distances[current] + 1;
            }
        }
    }
    return distances;
}

std::vector<int> Graph::shortestPathBackwarkdBFS(int start, int end) {
    std::map<int, int> dist = this->backwardBFS(end);
    std::vector<int> path;
    if (dist.count(start) == 0)
        return path;
    int current_vertex = start;
    while (current_vertex != end) {
        path.push_back(current_vertex);
            for (auto neighbour : this->outboundMap[current_vertex]) {
                if (dist.count(neighbour) != 0 && dist[neighbour] == dist[current_vertex] - 1) {
                    current_vertex = neighbour;
                    break;
            }
        }
    }
    path.push_back(end);
    return path;
}

std::pair<int, std::map<int, int>> Graph::shortestWeightedPath(int start, int end)
{
    int numberOfNodes = this->nrNodes();
    std::map<int, int> shortestPathStructure;
    std::map<int, int> lowestPathCost;
    for (int i = 0; i < numberOfNodes; ++i)
        lowestPathCost[i] = INT_MAX;
    shortestPathStructure[start] = -1;
    lowestPathCost[start] = 0;
    bool updated{};
    for (int i = 1; i <= numberOfNodes - 1; ++i) {
        updated = false;
        for (int j = 0; j < numberOfNodes; ++j) {
            for (int k = 0; k < this->outboundMap[j].size(); ++k) {
                int source = j;
                int destination = this->outboundMap[j][k];
                int weight = this->getCost(source, destination);
                if (lowestPathCost[source] != INT_MAX &&
                    lowestPathCost[source] + weight < lowestPathCost[destination]) 
                {
                    lowestPathCost[destination] = lowestPathCost[source] + weight;
                    shortestPathStructure[destination] = source;
                    updated = true;
                }
            }
        }
        if (updated == false)
            break;
    }
    for (int j = 0; j < numberOfNodes && updated == true; ++j) {
        for (int k = 0; k < this->outboundMap[j].size(); ++k) {
            int source = j;
            int destination = this->outboundMap[j][k];
            int weight = this->getCost(source, destination);
            if (lowestPathCost[source] != INT_MAX &&
                lowestPathCost[source] + weight < lowestPathCost[destination])
                throw std::exception();
        }
    }
    return std::make_pair(lowestPathCost[end], shortestPathStructure);
}

std::vector<int> Graph::topologicalSort()
{
    int numberOfNodes = this->nrNodes();
    std::vector<int> inDegree(numberOfNodes, 0);

    for (int i = 0; i < numberOfNodes; ++i) {
        inDegree[i] = this->inDegree(i);
    }

    std::queue<int> queue;
    for (int i = 0; i < numberOfNodes; i++)
        if (inDegree[i] == 0)
            queue.push(i);

    int cnt = 0;
    std::vector<int> topOrder;

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        topOrder.push_back(node);

        auto pair = this->outboundArc(node);
        for (auto itr = pair.first; itr != pair.second; itr++)
            if (--inDegree[*itr] == 0)
                queue.push(*itr);

        cnt++;
    }

    if (cnt != numberOfNodes) {
        throw std::exception("There exists a cycle in the graph!\n\n");
    }

    return topOrder;
}

std::vector<int> Graph::highestCostPathWithTopologicalSort(std::vector<int> topOrder, int source)
{
    int size = topOrder.size();
    std::stack<int> stack;
    std::vector<int> distances(size, INT_MIN);
    for (int i = 0; i < size; ++i) {
        stack.push(topOrder[size - i - 1]);
    }
    distances[source] = 0;

    while (!stack.empty()) {
        int node = stack.top();
        stack.pop();

        if (distances[node] != INT_MIN) {
            auto pair = this->outboundArc(node);
            for (auto i = pair.first; i != pair.second; ++i){
                if (distances[*i] < distances[node] + this->getCost(node, *i))
                    distances[*i] = distances[node] + this->getCost(node, *i);
            }
        }
    }
    return distances;
}

void Graph::displayCycle(int* path) {
    std::cout << "Cycle: ";

    for (int i = 0; i < this->nrNodes(); i++)
        std::cout << path[i] << " ";
    std::cout << path[0] << std::endl;      //print the first node again
}

bool Graph::isValid(int v, int k, int* path) {
    if (this->isArc(path[k-1], v) == 0)   //if there is no arc
        return false;

    for (int i = 0; i < k; ++i)   //if node is already taken, skip that
        if (path[i] == v)
            return false;
    return true;
}

bool Graph::cycleFound(int k, int* path) {
    if (k == this->nrNodes()) {             //when all nodes are in the path
        if (this->isArc(path[k - 1], path[0]) == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < this->nrNodes(); v++) {       //for all nodes except starting point
        if (isValid(v, k, path)) {                //if possible to add v in the path
            path[k] = v;
            if (cycleFound(k + 1, path) == true)
                return true;
            path[k] = -1;               //when k node will not in the solution
        }
    }
    return false;
}

bool Graph::hamiltonianCycle() {
    int* path = new int[this->nrNodes()];
    for (int i = 0; i < this->nrNodes(); ++i)
        path[i] = -1;
    path[0] = 0; //first vertex as 0

    if (cycleFound(1, path) == false) {
        std::cout << "Solution does not exist" << std::endl;
        return false;
    }

    displayCycle(path);
    delete[] path;
    return true;
}

std::string Graph::toString() {
    std::string str;
    str += std::to_string(nrNodes()) + " " + std::to_string(nrArcs()) + "\n";
    for (auto i: costMap) {
        str += std::to_string(i.first.first) + " " + std::to_string(i.first.second) + " " + std::to_string(i.second) + "\n";
    }
    return str;
}
