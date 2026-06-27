#include "FileManager.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <set>

using namespace std;

bool FileManager::saveGraph(const Graph& graph, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cout << "Error: Could not open file for writing.\n";
        return false;
    }

    const auto& adjList = graph.getAdjList();
    
    // Save all cities
    outFile << "[CITIES]\n";
    for (const auto& pair : adjList) {
        outFile << pair.first << "\n";
    }

    // Save all edges
    outFile << "[ROADS]\n";
    set<pair<string, string>> savedEdges; // To avoid duplicate undirected edges
    
    for (const auto& cityPair : adjList) {
        string u = cityPair.first;
        for (const auto& edge : cityPair.second) {
            string v = edge.first;
            int weight = edge.second;
            
            // create an ordered pair to avoid saving both u->v and v->u
            std::pair<string, string> edgePair = (u < v) ? make_pair(u, v) : make_pair(v, u);
            if (savedEdges.find(edgePair) == savedEdges.end()) {
                outFile << u << "," << v << "," << weight << "\n";
                savedEdges.insert(edgePair);
            }
        }
    }
    
    outFile.close();
    cout << "Graph successfully saved to " << filename << "\n";
    return true;
}

bool FileManager::loadGraph(Graph& graph, const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Error: Could not open file for reading.\n";
        return false;
    }

    graph.clear();
    string line;
    enum Section { NONE, CITIES, ROADS } currentSection = NONE;

    while (getline(inFile, line)) {
        if (line.empty()) continue;
        if (line == "[CITIES]") {
            currentSection = CITIES;
            continue;
        } else if (line == "[ROADS]") {
            currentSection = ROADS;
            continue;
        }
        
        if (currentSection == CITIES) {
            graph.addCity(line, true); // silent mode true
        } else if (currentSection == ROADS) {
            stringstream ss(line);
            string u, v, weightStr;
            if (getline(ss, u, ',') && getline(ss, v, ',') && getline(ss, weightStr)) {
                int weight = stoi(weightStr);
                graph.addRoad(u, v, weight, true); // silent mode true
            }
        }
    }

    inFile.close();
    cout << "Graph successfully loaded from " << filename << "\n";
    return true;
}
