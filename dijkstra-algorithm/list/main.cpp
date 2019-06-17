#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <limits>
#include <list>
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
void dijkstra (std::vector<std::list<T>>& graph, int start, int nr_of_vertices){
    std::vector<T> totalCost;
    std::vector<bool> visitedNodes;

    for (auto i = 0; i < graph.size(); ++i){
        totalCost.push_back(std::numeric_limits<T>::max());
        visitedNodes.push_back(false);
    }

    totalCost[start] = 0;

    typename std::vector<std::list<T>>::iterator adjacency_list_it;

    for (auto i = 0; i < (graph.size() - 1); ++i){
        int new_smallest = minDistance(totalCost, visitedNodes);
        visitedNodes[new_smallest] = true;
    
        adjacency_list_it = graph.begin();
        std::advance(adjacency_list_it, new_smallest);
        typename std::list<T>::iterator weights_it;
        std::list<T>& weights_ptr = *adjacency_list_it;

        for (auto j = 0, weights_it = weights_ptr.begin(); j < graph.size(), weights_it != weights_ptr.end(); ++j, ++weights_it){
            if (!visitedNodes[j] && *weights_it && totalCost[new_smallest] != std::numeric_limits<T>::max()){
                T alt_path = totalCost[new_smallest] + *weights_it;
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

template <typename T>
void printWeights (std::vector<std::list<T>> adjacency_list){
    typename std::vector<std::list<T>>::iterator adjacency_list_it;
    int index = 1;
    for (adjacency_list_it = adjacency_list.begin(); adjacency_list_it != adjacency_list.end(); ++ adjacency_list_it){
        std::cout << index << " : ";
        typename std::list<T>::iterator weights_it;

        std::list<T>& weights_ptr = *adjacency_list_it;

        for (weights_it = weights_ptr.begin(); weights_it != weights_ptr.end(); ++weights_it){
            std::cout << *weights_it << " ";
        }
        index++;
        std::cout << std::endl;
    }
}

int main(){
    int nr_of_vertices = 0;
    std::vector<std::list<int>> adjacency_list;
    std::list<int> weights;

    std::ifstream dataFile("data1.txt");
    if (dataFile.good()){
        dataFile >> nr_of_vertices;
        for (auto i = 0; i < nr_of_vertices; ++i){
            for (auto j = 0; j < nr_of_vertices; ++j){
                int temp = 0;
                dataFile >> temp;
                weights.emplace_back(temp);
            }
            adjacency_list.emplace_back(weights);
            weights.erase(weights.begin(), weights.end());
        }
    }

    auto start = std::chrono::steady_clock::now();
    dijkstra(adjacency_list, 0, nr_of_vertices);
    auto end = std::chrono::steady_clock::now();
    std::cout << std::endl;
    std::cout << "Czas w mikrosekundach: " << std::chrono::duration_cast<std::chrono::microseconds>(end-start).count() << std::endl;
}