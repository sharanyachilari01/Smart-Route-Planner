#include "Graph.h"
#include <queue>

void Graph::addCity(const string& city, bool silent) {
    if (adjList.find(city) == adjList.end()) {
        adjList[city] = vector<pair<string, int>>();
        if (!silent) cout << "City '" << city << "' added successfully.\n";
    } else {
        if (!silent) cout << "City '" << city << "' already exists.\n";
    }
}

void Graph::removeCity(const string& city) {
    if (adjList.find(city) != adjList.end()) {
        // Remove all roads pointing to this city
        for (auto& pair_item : adjList) {
            auto& edges = pair_item.second;
            for (auto it = edges.begin(); it != edges.end(); ) {
                if (it->first == city) {
                    it = edges.erase(it);
                } else {
                    ++it;
                }
            }
        }
        adjList.erase(city); // Remove the city itself
        cout << "City '" << city << "' removed successfully.\n";
    } else {
        cout << "City '" << city << "' not found.\n";
    }
}

void Graph::addRoad(const string& city1, const string& city2, int distance, bool silent) {
    if (adjList.find(city1) == adjList.end() || adjList.find(city2) == adjList.end()) {
        if (!silent) cout << "Error: Both cities must exist before adding a road.\n";
        return;
    }
    // Checking if road already exists
    for (const auto& edge : adjList[city1]) {
        if (edge.first == city2) {
            if (!silent) cout << "Road between '" << city1 << "' and '" << city2 << "' already exists.\n";
            return;
        }
    }
    
    // Add road for both directions (Undirected Graph)
    adjList[city1].push_back({city2, distance});
    adjList[city2].push_back({city1, distance}); 
    
    if (!silent) cout << "Road added between '" << city1 << "' and '" << city2 << "' with distance " << distance << " km.\n";
}

void Graph::removeRoad(const string& city1, const string& city2) {
    if (adjList.find(city1) == adjList.end() || adjList.find(city2) == adjList.end()) {
        cout << "Error: One or both cities do not exist.\n";
        return;
    }
    
    // Helper lambda to remove an edge in one direction
    auto removeEdge = [&](const string& u, const string& v) {
        auto& edges = adjList[u];
        for (auto it = edges.begin(); it != edges.end(); ++it) {
            if (it->first == v) {
                edges.erase(it);
                return true;
            }
        }
        return false;
    };
    
    bool found = removeEdge(city1, city2);
    removeEdge(city2, city1);
    
    if (found) {
        cout << "Road between '" << city1 << "' and '" << city2 << "' removed successfully.\n";
    } else {
        cout << "Road between '" << city1 << "' and '" << city2 << "' not found.\n";
    }
}

void Graph::displayNetwork() const {
    if (adjList.empty()) {
        cout << "The network is empty.\n";
        return;
    }
    cout << "\n--- Road Network ---\n";
    for (const auto& pair : adjList) {
        cout << "[" << pair.first << "] connects to:\n";
        if (pair.second.empty()) {
            cout << "  (No roads)\n";
        }
        for (const auto& edge : pair.second) {
            cout << "  -> " << edge.first << " (" << edge.second << " km)\n";
        }
    }
}

bool Graph::searchCity(const string& city) const {
    if (adjList.find(city) != adjList.end()) {
        cout << "City '" << city << "' exists in the network.\n";
        return true;
    }
    cout << "City '" << city << "' not found.\n";
    return false;
}

int Graph::getConnectedComponents() const {
    unordered_map<string, bool> visited;
    for (const auto& pair : adjList) {
        visited[pair.first] = false;
    }
    
    int components = 0;
    for (const auto& pair : adjList) {
        if (!visited[pair.first]) {
            components++;
            // BFS traversal to mark all cities in this component
            queue<string> q;
            q.push(pair.first);
            visited[pair.first] = true;
            
            while (!q.empty()) {
                string curr = q.front();
                q.pop();
                for (const auto& edge : adjList.at(curr)) {
                    if (!visited[edge.first]) {
                        visited[edge.first] = true;
                        q.push(edge.first);
                    }
                }
            }
        }
    }
    return components;
}

void Graph::displayStatistics() const {
    int totalCities = adjList.size();
    int totalRoads = 0;
    for (const auto& pair : adjList) {
        totalRoads += pair.second.size();
    }
    totalRoads /= 2; // Graph is undirected
    
    cout << "\n--- Network Statistics ---\n";
    cout << "Total Cities: " << totalCities << "\n";
    cout << "Total Roads: " << totalRoads << "\n";
    cout << "Connected Components: " << getConnectedComponents() << "\n";
}

const unordered_map<string, vector<pair<string, int>>>& Graph::getAdjList() const {
    return adjList;
}

void Graph::clear() {
    adjList.clear();
}
