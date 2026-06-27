#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <utility>

using namespace std;

class Graph {
private:
    // Adjacency list: City Name -> vector of <Neighbor City, Distance>
    unordered_map<string, vector<pair<string, int>>> adjList;

public:
    void addCity(const string& city, bool silent = false);
    void removeCity(const string& city);
    void addRoad(const string& city1, const string& city2, int distance, bool silent = false);
    void removeRoad(const string& city1, const string& city2);
    void displayNetwork() const;
    bool searchCity(const string& city) const;
    void displayStatistics() const;
    int getConnectedComponents() const;

    // Getters for RouteFinder and FileManager
    const unordered_map<string, vector<pair<string, int>>>& getAdjList() const;
    void clear();
};

#endif // GRAPH_H
