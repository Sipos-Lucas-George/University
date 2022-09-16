#include <iostream>
#include "Graph.h"
#include <fstream>
#include <exception>
#include <random>

Graph readFile(const std::string& file) {
    std::ifstream f(file, std::ios::in);
    if (!f.is_open()) {
        throw std::exception();
    }
    int nrNodes, nrArcs;
    f >> nrNodes >> nrArcs;
    Graph G(nrNodes);
    for (int i = 0; i < nrArcs; ++i) {
        int v1, v2, cost;
        f >> v1 >> v2 >> cost;
        G.addArc(v1, v2, cost);
    }
    f.close();
    return G;
}

Graph generateGraph(int nrNodes, int nrArcs) {
    Graph G(nrNodes);
    int v1, v2, cost;
    for (int i = 0; i < nrArcs; ++i) {
        v1 = rand() % nrNodes;
        v2 = rand() % nrNodes;
        cost = rand() % 300;
        if (G.isArc(v1, v2)) {
            --i;
        }
        else {
            G.addArc(v1, v2, cost);
        }
    }
    return G;
}
Graph getGraph() {
    std::cout << "How do you want to initialise the graph:\n1 - generate\n2 - read from file\n>";
    int cmd;
    std::cin >> cmd;
    if (cmd == 1) {
        std::cout << "Please enter number of nodes: ";
        int nrNodes, nrArcs;
        std::cin >> nrNodes;
        std::cout << "Please enter number of arcs: ";
        std::cin >> nrArcs;
        Graph g = generateGraph(nrNodes, nrArcs);
        return g;
    } else if (cmd == 2) {
        std::cout << "Enter file name: ";
        std::string file;
        std::cin >> file;
        Graph g = readFile(file);
        return g;
    } else {
        std::cout << "Invalid option.";
        throw std::exception();
    }
}

void printMenu(Graph& G) {
    std::cout << "Graph Operations\n"
                 "1. Get the number of nodes\n"
                 "2. Print the set of nodes\n"
                 "3. Check if there is an arc between 2 nodes\n"
                 "4. Inbound degree of a node\n"
                 "5. Outbound degree of a node\n"
                 "6. The outbound arcs of a node\n"
                 "7. The inbound arcs of a node\n"
                 "8. Get the cost of an arc\n"
                 "9. Modify the cost of an arc\n"
                 "10. Add arc\n"
                 "11. Remove arc\n"
                 "12. Add node\n"
                 "13. Remove node\n"
                 "14. Backward BFS\n"
                 "15. Ford's algorithm\n"
                 "16. DAG - topological sort / highest cost path between 2 given vertices\n"
                 "17. Find all Hamiltonian cycles\n"
                 "18. Save graph to file\n"
                 "19. Print graph\n"
                 "0. Exit\n";
    int cmd;
    std::cout << "Command: ";
    std::cin >> cmd;
    switch (cmd) {
        case 1:
            std::cout << G.nrNodes() << '\n';
            break;
        case 2: {
            auto p = G.setOfNodes();
            for (auto i = p.first; i != p.second; ++i) {
                std::cout << i->first << ' ';
            }
            std::cout << '\n';
            break;
        }
        case 3: {
            int v1, v2;
            std::cout << "Nodes: ";
            std::cin >> v1 >> v2;
            std::cout << G.isArc(v1, v2) << '\n';
            break;
        }
        case 4: {
            int v1;
            std::cout << "Node: ";
            std::cin >> v1;
            std::cout << G.inDegree(v1) << '\n';
            break;
        }
        case 5: {
            int v1;
            std::cout << "Node: ";
            std::cin >> v1;
            std::cout << G.outDegree(v1) << '\n';
            break;
        }
        case 6: {
            int v1;
            std::cout << "Node: ";
            std::cin >> v1;
            auto p = G.outboundArc(v1);
            for (auto i = p.first; i != p.second; ++i) {
                std::cout << *i << '\n';
            }
            break;
        }
        case 7: {
            int v1;
            std::cout << "Node: ";
            std::cin >> v1;
            auto p = G.inboundArc(v1);
            for (auto i = p.first; i != p.second; ++i) {
                std::cout << *i << '\n';
            }
            break;
        }
        case 8: {
            try {
                int v1, v2;
                std::cout << "Arc: ";
                std::cin >> v1 >> v2;
                std::cout << G.getCost(v1, v2) << '\n';
            }
            catch (std::exception& e) {
                std::cout << "ERROR!!!\n";
            }
            break;
        }
        case 9: {
            try {
                int v1, v2, cost;
                std::cout << "Arc: ";
                std::cin >> v1 >> v2;
                std::cout << "Cost: ";
                std::cin >> cost;
                G.changeCost(v1, v2, cost);
            }
            catch (std::exception& e) {
                std::cout << "ERROR!!!\n";
            }
            break;
        }
        case 10: {
            try {
                int v1, v2, cost;
                std::cout << "Arc: ";
                std::cin >> v1 >> v2;
                std::cout << "Cost: ";
                std::cin >> cost;
                G.addArc(v1, v2, cost);
            }
            catch (std::exception& e) {
                std::cout << "ERROR!!!\n";
            }
            break;
        }
        case 11: {
            try {
                int v1, v2;
                std::cout << "Arc: ";
                std::cin >> v1 >> v2;
                G.removeArc(v1, v2);
            }
            catch (std::exception& e) {
                std::cout << "ERROR!!!\n";
            }
            break;
        }
        case 12: {
            try {
                int v1;
                std::cout << "Node: ";
                std::cin >> v1;
                G.addNode(v1);
            }
            catch (std::exception& e) {
                std::cout << "ERROR!!!\n";
            }
            break;
        }
        case 13: {
            try {
                int v1;
                std::cout << "Node: ";
                std::cin >> v1;
                G.removeNode(v1);
            }
            catch (std::exception& e) {
                std::cout << "ERROR!!!\n";
            }
            break;
        }
        case 14: {
            int v1, v2;
            std::cout << "Start: ";
            std::cin >> v1;
            std::cout << "End: ";
            std::cin >> v2;
            if (v1 == v2) {
                std::cout << v1 << "\n\n";
                break;
            }
            std::vector<int> result = G.shortestPathBackwarkdBFS(v1, v2);
            if (result.empty())
                std::cout << "There is no such path!!!\n";
            else {
                for (auto i : result)
                    std::cout << i << " ";
                std::cout << "\n\n";
            }
            break;
        }
        case 15: {
            int v1, v2;
            std::cout << "Start: ";
            std::cin >> v1;
            std::cout << "End: ";
            std::cin >> v2;
            if (v1 == v2) {
                std::cout << v1 << "\n\n";
                break;
            }
            try {
                std::pair<int,std::map<int, int>> result = G.shortestWeightedPath(v1, v2);
                std::vector<int> path;
                while (v2 != NULL) {
                    path.insert(path.begin(), v2);
                    v2 = result.second[v2];
                }
                std::cout << "Shortest path: " << v1 << ' ';
                for (auto element : path) {
                    std::cout << element << ' ';
                }
                std::cout << "\nLenght: " << result.first << std::endl;
            }
            catch (std::exception& e) {
                std::cout << "Graph contains negative cycles\n";
            }
            break;
        }
        case 16: {
            try {
                std::vector<int> topOrder = G.topologicalSort();
                for (int i = 0; i < topOrder.size(); i++)
                    std::cout << topOrder[i] << " ";
                std::cout << std::endl;
                int v1, v2;
                std::cout << "Choose your vertices:\n" << "Start: ";
                std::cin >> v1;
                std::cout << "End: ";
                std::cin >> v2;
                std::vector<int> costs = G.highestCostPathWithTopologicalSort(topOrder, v1);
                std::cout << "Highest cost path from " << v1 << " to " << v2 << " is: ";
                std::cout << costs[v2] << "\n\n";
            }
            catch (std::exception& e) {
                std::cout << e.what();
            }
            break;
        }
        case 17: {
            G.hamiltonianCycle();
            break;
        }
        case 18: {
            std::string fileName;
            std::cout << "File name: ";
            std::cin >> fileName;
            std::cout << "The copy of the graph is saved to " << fileName << "...\n";
            std::ofstream graphCopy(fileName);
            graphCopy << G.toString();
            graphCopy.close();
            break;
        }
        case 19: {
            std::cout << G.toString() << '\n';
            break;
        }
        case 0:
            throw std::exception();
        default:
            std::cout << "Invalid command\n";
            break;
    }
}

int main() {
    Graph G = Graph(0);
    try {
        G = getGraph();
    } catch (std::exception& e) {
        std::cout << "Invalid data. Terminating program.\n";
        return -1;
    }
    while (true) {
        try {
            printMenu(G);
        } catch (std::exception& e) {
            return 0;
        }
    }
}
