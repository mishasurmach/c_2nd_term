//  main.cpp
//  money
//  Created by Михаил Сурмач on 12.04.2022.

#include <iostream>
using namespace std;

void input(int n, int *coins){
    for (int i = 0; i < n; i++){
        cin >> coins[i];
    }
}

void algorithm(int number_of_coins, int sum, int *coins){
    int z = 0;
    for (int i = number_of_coins - 1; i >= 0; i--){
        while (sum >= coins[i]){
            sum = sum - coins[i];
            z++;
        }
    }
    cout << z;
}

int main() {
    int number_of_coins;
    cout << "Input number of nominals!" << endl;
    cin >> number_of_coins;
    int *coins = new int[number_of_coins];
    cout << "Enter coins!" << endl;
    input(number_of_coins, coins);
    cout << "Enter sum!" << endl;
    int sum;
    cin >> sum;
    algorithm(number_of_coins, sum, coins);
    return 0;
}
