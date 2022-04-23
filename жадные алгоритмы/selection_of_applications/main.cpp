//  main.cpp
//  selection_of_applications
//  Created by Михаил Сурмач on 12.04.2022.

#include <iostream>
#include <algorithm>

struct order{
    int key;
    float beginning_time, ending_time;
};

void input(order *orders, int number_of_orders){
    for (int i = 0; i < number_of_orders; i++){
        std::cin >> orders[i].beginning_time;
        std::cin >> orders[i].ending_time;
        orders[i].key = i + 1;
    }
    std::cout << std::endl;
}

bool comparison(order x, order y) {
    return x.ending_time < y.ending_time;
}

void algorithm(order *orders, int number_of_orders){
    std::sort(orders, orders + number_of_orders, comparison);
    int idx = 0;
    std::cout << orders[0].key << " ";
    for (int i = 0; i < number_of_orders - 1; i++){
        if (orders[idx].ending_time <= orders[i + 1].beginning_time){
            idx = i + 1;
            std::cout << orders[i + 1].key << " ";
        }
    }
}

int main() {
    std::cout << "Enter the number of orders and then the time of the beginning and time of the order of orders in each row." << std::endl << "For instance," << std::endl << "2" << std::endl << "15.30 17.30" << std::endl << "10.00 10.01" << std::endl;
    int number_of_orders;
    std::cin >> number_of_orders;
    order *orders = new order[number_of_orders];
    input(orders, number_of_orders);
    std::cout << "Numbers of acceptable requests: ";
    algorithm(orders, number_of_orders);
    delete[] orders;
    return 0;
}
