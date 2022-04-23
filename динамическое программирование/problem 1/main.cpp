//  main.cpp
//  problem 1
//  Created by Михаил Сурмач on 19.04.2022.

#include <iostream>

void input(int &size, int *arr){
    std::cin >> size;
    for (int i = 0; i < size; i++)
        std::cin >> arr[i];
}

void algorithm(int size, int *arr, int *length){
    for (int i = 0; i < size; i++){
        length[i] = 1;
        for (int j = 0; j < i; j++){
            if (arr[j] < arr[i] & length[j] + 1 > length[i])
                length[i] = length[j] + 1;
        }
    }
}

int find_max(int *length, int size){
    int max = 0;
    for (int i = 0; i < size; i++){
        if (max < length[i])
            max = length[i];
    }
    return max;
}

int main() {
    int size, arr[100], length[100];
    input(size, arr);
    algorithm(size, arr, length);
    std::cout << find_max(length, size);
    return 0;
}
