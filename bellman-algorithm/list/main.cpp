#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include <chrono>
#include <fstream>

/* wartość zero wczytana z pliku data.txt oznacza brak polaczenia wierzcholkow */

template <typename T>
void isNegative(std::vector<std::list<T>>& graph, std::vector<T>& totalCost){
    typename std::vector<std::list<T>>::iterator adjacency_list_it;

    for (auto j = 0, adjacency_list_it = graph.begin(); j < graph.size(), adjacency_list_it != graph.end(); ++j, ++adjacency_list_it){
        typename std::list<T>::iterator weights_it;
        std::list<T>& weights_ptr = *adjacency_list_it;
        for (auto k = 0, weights_it = weights_ptr.begin(); k < graph.size(), weights_it != weights_ptr.end(); ++k, ++weights_it){
            if (*weights_it && totalCost[j] + *weights_it < totalCost[k] && totalCost[j] != std::numeric_limits<int>::max()){
                std::cout << "negative cycle" << std::endl;
            }
        }
    }
}

template <typename T>
void bellmanFord(std::vector<std::list<T>>& graph, int start, int& nr_of_vertices){
    std::vector<T> visitedNodes;
    std::vector<T> totalCost;

    for (auto i = 0; i < graph.size(); ++i){
        totalCost.push_back(std::numeric_limits<T>::max());
    }

    totalCost[start] = 0;

    typename std::vector<std::list<T>>::iterator adjacency_list_it;
    typename std::list<T>::iterator weights_it;

    for (auto i = 0; i < (graph.size() - 1); ++i){
        for (auto j = 0, adjacency_list_it = graph.begin(); j < graph.size(), adjacency_list_it != graph.end(); ++j, ++adjacency_list_it){
            std::list<T>& weights_ptr = *adjacency_list_it;
            for (auto k = 0, weights_it = weights_ptr.begin(); k < graph.size(), weights_it != weights_ptr.end(); ++k, ++weights_it){
                if (*weights_it && totalCost[j] + *weights_it < totalCost[k] && totalCost[j] != std::numeric_limits<int>::max()){
                    totalCost[k] = totalCost[j] + *weights_it;
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
    std::vector<std::list<int>> adjacency_list;
    std::list<int> weights;

    std::ifstream dataFile("data1.txt");
    if (dataFile.good()){
        dataFile >> nr_of_vertices;
        for (int i = 0; i < nr_of_vertices; ++i){
            for (int j = 0; j < nr_of_vertices; ++j){
                int temp = 0;
                dataFile >> temp;
                weights.push_back(temp);
            }
            adjacency_list.emplace_back(weights);
            weights.erase(weights.begin(), weights.end());
        }
    }

    auto start = std::chrono::steady_clock::now();
    bellmanFord(adjacency_list, 0, nr_of_vertices);
    auto end = std::chrono::steady_clock::now();
    std::cout << std::endl;
    std::cout << "Czas w mikrosekundach: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << std::endl;
}