#include "RouteFinder.h"
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

void RouteFinder::findShortestPath(const Graph& graph, const string& start, const string& end) {
    const auto& adjList = graph.getAdjList();
    if (adjList.find(start) == adjList.end() || adjList.find(end) == adjList.end()) {
        cout << "Error: Start or end city does not exist.\n";
        return;
    }

    unordered_map<string, int> distances;
    unordered_map<string, string> parent;
    
    // Initialize distances to infinity
    for (const auto& pair : adjList) {
        distances[pair.first] = numeric_limits<int>::max();
    }
    
    distances[start] = 0;
    
    // Min-heap storing {distance, city_name}
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int currentDist = pq.top().first;
        string currentCity = pq.top().second;
        pq.pop();
        
        // If we reached the destination, we can stop early
        if (currentCity == end) break;
        
        // If we found a longer path, ignore
        if (currentDist > distances[currentCity]) continue;
        
        for (const auto& edge : adjList.at(currentCity)) {
            string neighbor = edge.first;
            int weight = edge.second;
            
            if (distances[currentCity] + weight < distances[neighbor]) {
                distances[neighbor] = distances[currentCity] + weight;
                parent[neighbor] = currentCity;
                pq.push({distances[neighbor], neighbor});
            }
        }
    }
    
    if (distances[end] == numeric_limits<int>::max()) {
        cout << "No path exists between '" << start << "' and '" << end << "'.\n";
        return;
    }
    
    // Reconstruct path
    vector<string> path;
    string curr = end;
    while (curr != start) {
        path.push_back(curr);
        curr = parent[curr];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    
    cout << "\nShortest Path: ";
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i != path.size() - 1) cout << " -> ";
    }
    cout << "\nTotal Distance: " << distances[end] << " km\n";
}

void RouteFinder::bfsTraversal(const Graph& graph, const string& start) {
    const auto& adjList = graph.getAdjList();
    if (adjList.find(start) == adjList.end()) {
        cout << "City '" << start << "' not found.\n";
        return;
    }
    
    unordered_map<string, bool> visited;
    for (const auto& pair : adjList) visited[pair.first] = false;
    
    queue<string> q;
    q.push(start);
    visited[start] = true;
    
    cout << "BFS Traversal from '" << start << "': ";
    while (!q.empty()) {
        string curr = q.front();
        q.pop();
        cout << curr << " ";
        
        for (const auto& edge : adjList.at(curr)) {
            if (!visited[edge.first]) {
                visited[edge.first] = true;
                q.push(edge.first);
            }
        }
    }
    cout << "\n";
}

void RouteFinder::dfsTraversal(const Graph& graph, const string& start) {
    const auto& adjList = graph.getAdjList();
    if (adjList.find(start) == adjList.end()) {
        cout << "City '" << start << "' not found.\n";
        return;
    }
    
    unordered_map<string, bool> visited;
    for (const auto& pair : adjList) visited[pair.first] = false;
    
    stack<string> s;
    s.push(start);
    
    cout << "DFS Traversal from '" << start << "': ";
    while (!s.empty()) {
        string curr = s.top();
        s.pop();
        
        if (!visited[curr]) {
            cout << curr << " ";
            visited[curr] = true;
        }
        
        // Push neighbors to stack
        for (auto it = adjList.at(curr).rbegin(); it != adjList.at(curr).rend(); ++it) {
            if (!visited[it->first]) {
                s.push(it->first);
            }
        }
    }
    cout << "\n";
}
