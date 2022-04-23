//  main.cpp
//  commis_voyageur
//  Created by Михаил Сурмач on 15.04.2022.

#include <iostream>
#include <cmath>

bool detector(int *array, int number_of_cities){
    for (int i = 0; i < number_of_cities; i++) {
        if (array[i] == 0)
            return true;
    }
    return false;
}

void make_array(int number_of_cities, int *distances){
    for (int i = 0; i < number_of_cities; i++) {
        distances[i] = 0;
    }
    distances[0] = 1;
}

void input(int **cities, int number_of_cities){
    std::cout << "Enter number of cities and distances" << std::endl;
    for (int i = 0; i < number_of_cities; i++){
        for (int j = 0; j < number_of_cities; j++)
            std::cin >> cities[i][j];
    }
}

int find_nearest_city(int *array, int number_of_cities, int *distances) {
    int subd = 0, idx = 0;
    for (int i = 0; i < number_of_cities; i++) {
        if (distances[i] == 0) {
            idx = i;
            subd = array[i];
        }
    }
    for (int j = 1; j < number_of_cities; j++) {
        if (array[j] < subd && array[j] != 0) {
            if (distances[j] == 0) {
                idx = j;
                subd = array[j];
            }
        }
    }
    std::cout << idx + 1;
    distances[idx] = 1;
    return idx;
}



void algorithm(int** cities, int number_of_cities, int* distances, int city) {
    if (detector(distances, number_of_cities) == true){
        int key = find_nearest_city(cities[city], number_of_cities, distances);
        algorithm(cities, number_of_cities, distances, key);
    }
}


int main() {
    int number_of_cities;
    std::cout << "Enter number of cities: " << std::endl;
    std::cin >> number_of_cities;
    
    int **cities = new int*[number_of_cities];
    int *distances = new int[number_of_cities];
    for (int i = 0; i < number_of_cities; i++) {
        cities[i] = new int[number_of_cities];
    }
    
    make_array(number_of_cities, distances);
    input(cities, number_of_cities);

    std::cout << 1;
    algorithm(cities, number_of_cities, distances, 0);
    
    return 0;
}
