#include <iostream>
#include <vector>
#include <limits>
#include <fstream>
#include <chrono>

/* wartość zero wczytana z pliku data.txt oznacza brak polaczenia wierzcholkow */

template <typename T>
void isNegative(std::vector<std::vector<T>>& graph, std::vector<T>& totalCost){
    for (auto i = 0; i < graph.size(); ++i){
        for (auto j = 0; j < graph.size(); ++j){
            if (graph[i][j] && totalCost[i] + graph[i][j] < totalCost[j] && totalCost[i] != std::numeric_limits<int>::max()){
                std::cout << "negative cycle" << std::endl;
            }
        }
    }
}

template <typename T>
void bellmanFord(std::vector<std::vector<T>>& graph, int start, int& nr_of_vertices){
    std::vector<T> visitedNodes;
    std::vector<T> totalCost;

    for (auto i = 0; i < graph.size(); ++i){
        totalCost.push_back(std::numeric_limits<T>::max());
    }

    totalCost[start] = 0;

    for (auto i = 0; i < (graph.size() - 1); ++i){
        for (auto j = 0; j < graph.size(); ++j){
            for (auto k = 0; k < graph.size(); ++k){
                if (graph[j][k] && totalCost[j] + graph[j][k] < totalCost[k] && totalCost[j] != std::numeric_limits<int>::max()){
                    totalCost[k] = totalCost[j] + graph[j][k];
                }
            }
            visitedNodes.push_back(j);
        }
    }

    isNegative(graph, totalCost);

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
        for (int i = 0; i < nr_of_vertices; ++i){
            for (int j = 0; j < nr_of_vertices; ++j){
                dataFile >> adjacency_matrix[i][j];
            }
        }
    }

    auto start = std::chrono::steady_clock::now();
    bellmanFord(adjacency_matrix, 0, nr_of_vertices);
    auto end = std::chrono::steady_clock::now();
    std::cout << std::endl;
    std::cout << "Czas w mikrosekundach: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << std::endl;
}