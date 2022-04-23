//  main.cpp
//  backpack problem
//  Created by Михаил Сурмач on 12.04.2022.

#include <iostream>
#include <algorithm>

struct item{
    int key;
    double weight, value, unit_value;
};

void input(item *items, int quantity){
    std::cout << "Enter values and weight and of items in the following format:" << std::endl << "12.3 14.5"
    << std::endl << "0.1 17.8" << std::endl << "..." << std::endl;
    for (int i = 0; i < quantity; i++){
        std::cin >> items[i].value;
        std::cin >> items[i].weight;
        items[i].key = i + 1;
        items[i].unit_value = items[i].value / items[i].weight;
    }
}

bool comparison(item x, item y){
    return x.unit_value > y.unit_value;
}

double algorithm(item *items, int quantity, int capacity){
    std::sort(items, items + quantity, comparison);
    double backpack = 0;
    for (int idx = 0; ((items[idx].weight <= capacity) & (idx < quantity)); idx++){
        backpack += items[idx].value;
        capacity -= items[idx].weight;
    }
    return backpack;
}

int main() {
    int capacity, quantity;
    std::cout << "Input backpack capacity and quantity of objects:" << std::endl;
    std::cin >> capacity >> quantity;
    item *items = new item[quantity];
    input(items, quantity);
    std::cout << std::endl << "Final value: " << algorithm(items, quantity, capacity);
    
    return 0;
}
