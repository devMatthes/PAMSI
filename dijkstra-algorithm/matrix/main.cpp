#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>
#include <chrono>

template <typename T>
int minDistance (std::vector<T>& totalCost, std::vector<bool>& visitedNodes){
    int min = std::numeric_limits<T>::max();
    int min_index;

    for (auto i = 0; i < totalCost.size(); ++i){
        if (visitedNodes[i] == false && totalCost[i] <= min){
            min = totalCost[i];
            min_index = i;
        }
    }
    return min_index;
}

template <typename T>
void dijkstra (std::vector<std::vector<T>>& graph, int start, int nr_of_vertices){
    std::vector<T> totalCost;
    std::vector<bool> visitedNodes;

    for (auto i = 0; i < graph.size(); ++i){
        totalCost.push_back(std::numeric_limits<T>::max());
        visitedNodes.push_back(false);
    }

    totalCost[start] = 0;

    for (auto i = 0; i < (graph.size() - 1); ++i){
        int new_smallest = minDistance(totalCost, visitedNodes);
        visitedNodes[new_smallest] = true;

        for (auto j = 0; j < graph.size(); ++j){
            if (!visitedNodes[j] && graph[new_smallest][j] && totalCost[new_smallest] != std::numeric_limits<T>::max()){
                T alt_path = totalCost[new_smallest] + graph[new_smallest][j];
                if (alt_path < totalCost[j]){
                    totalCost[j] = alt_path;
                }
            }
        }
    }

    for (auto i = 0; i < nr_of_vertices; ++i){
        std::cout << totalCost[i] << " " << i + 1 << std::endl;
    }
}

int main(){
    int nr_of_vertices = 0;
    std::vector<std::vector<int>> adjacency_matrix;

    std::ifstream dataFile("data1.txt");
    if (dataFile.good()){
        dataFile >> nr_of_vertices;
        adjacency_matrix.resize(nr_of_vertices, std::vector<int>(nr_of_vertices));
        for (auto i = 0; i < nr_of_vertices; ++i){
            for (auto j = 0; j < nr_of_vertices; ++j){
                dataFile >> adjacency_matrix[i][j];
            }
        }
    }

    auto start = std::chrono::steady_clock::now();
    dijkstra(adjacency_matrix, 0, nr_of_vertices);
    auto end = std::chrono::steady_clock::now();
    std::cout << std::endl;
    std::cout << "Czas w mikrosekundach: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << std::endl;
}