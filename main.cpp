#include <iostream>
#include <limits>
#include "Graph.h"
#include "RouteFinder.h"
#include "FileManager.h"

using namespace std;

void displayMenu() {
    cout << "\n=============================================\n";
    cout << "   Smart Route Planner using Graph Algorithms\n";
    cout << "=============================================\n";
    cout << "1. Add City\n";
    cout << "2. Remove City\n";
    cout << "3. Add Road\n";
    cout << "4. Remove Road\n";
    cout << "5. Display Road Network\n";
    cout << "6. Search City\n";
    cout << "7. Find Shortest Path (Dijkstra's Algorithm)\n";
    cout << "8. BFS Traversal\n";
    cout << "9. DFS Traversal\n";
    cout << "10. Display Statistics\n";
    cout << "11. Save Graph to File\n";
    cout << "12. Load Graph from File\n";
    cout << "13. Exit\n";
    cout << "=============================================\n";
    cout << "Enter your choice: ";
}

int main() {
    Graph graph;
    int choice;
    string city1, city2, filename;
    int distance;

    // Load sample data if exists
    // FileManager::loadGraph(graph, "sample_data.txt");

    while (true) {
        displayMenu();
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear newline

        switch (choice) {
            case 1:
                cout << "Enter city name: ";
                getline(cin, city1);
                graph.addCity(city1);
                break;
            case 2:
                cout << "Enter city name to remove: ";
                getline(cin, city1);
                graph.removeCity(city1);
                break;
            case 3:
                cout << "Enter first city: ";
                getline(cin, city1);
                cout << "Enter second city: ";
                getline(cin, city2);
                cout << "Enter distance (in km): ";
                if (!(cin >> distance) || distance <= 0) {
                    cout << "Invalid distance. Must be a positive integer.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } else {
                    graph.addRoad(city1, city2, distance);
                }
                break;
            case 4:
                cout << "Enter first city: ";
                getline(cin, city1);
                cout << "Enter second city: ";
                getline(cin, city2);
                graph.removeRoad(city1, city2);
                break;
            case 5:
                graph.displayNetwork();
                break;
            case 6:
                cout << "Enter city name to search: ";
                getline(cin, city1);
                graph.searchCity(city1);
                break;
            case 7:
                cout << "Enter start city: ";
                getline(cin, city1);
                cout << "Enter destination city: ";
                getline(cin, city2);
                RouteFinder::findShortestPath(graph, city1, city2);
                break;
            case 8:
                cout << "Enter start city for BFS: ";
                getline(cin, city1);
                RouteFinder::bfsTraversal(graph, city1);
                break;
            case 9:
                cout << "Enter start city for DFS: ";
                getline(cin, city1);
                RouteFinder::dfsTraversal(graph, city1);
                break;
            case 10:
                graph.displayStatistics();
                break;
            case 11:
                cout << "Enter filename to save (e.g., data.txt): ";
                getline(cin, filename);
                FileManager::saveGraph(graph, filename);
                break;
            case 12:
                cout << "Enter filename to load (e.g., data.txt): ";
                getline(cin, filename);
                FileManager::loadGraph(graph, filename);
                break;
            case 13:
                cout << "Exiting Smart Route Planner. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please select a number between 1 and 13.\n";
        }
    }
    return 0;
}
