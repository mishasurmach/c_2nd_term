//  main.cpp
//  problem 2
//  Created by Михаил Сурмач on 19.04.2022.

#include <iostream>

void input(int &size, int *arr){
    std::cin >> size;
    for (int i = 0; i < size; i++)
        std::cin >> arr[i];
}

int algorithm(int size, int *arr, int *costs){
    if (size == 1)
        return 0;
    costs[0] = 0;
    costs[1] = abs(arr[1] - arr[0]);
    for (int i = 2; i < size; i++)
        costs[i] = std::min((abs(arr[i] - arr[i - 1]) + costs[i - 1]),
                            (3 * abs(arr[i] - arr[i - 2]) + costs[i - 2]));
    return costs[size - 1];
}

int main() {
    int arr[30000], costs[30000], size;
    input(size, arr);
    std::cout << algorithm(size, arr, costs);
    return 0;
}
