#include <iostream>

struct node{
    int digit;
    node *right = nullptr, *left = nullptr;
};

void output(node *num){
    if (num){
        std::cout << "(";
        output(num -> left);
        std::cout << num -> digit;
        output(num -> right);
        std::cout << ")";
    }
}

node *input(){
    node *root = new node;
    std::cin >> root -> digit;

    if (root -> digit == 0){
        delete root;
        return nullptr;
    }

    int n = 1;
    node *num, *back;

    while (n != 0){
        std::cin >> n;

        if (n == 0){
            break;
        }

        num = root;
        back = num;
        while (num){
            if (n == num -> digit){
                break;
            }

            else if (n > num -> digit){
                back = num;
                num = num -> right;
            }

            else if (n < num -> digit){
                back = num;
                num = num -> left;
            }
        }

        if (n > back -> digit){
            back -> right = new node;
            back -> right -> digit = n;
        }

        if (n < back -> digit){
            back -> left = new node;
            back -> left -> digit = n;
        }
    }

    return root;
}

int main(){
    node *root = input();
    output(root);

    return 0;
}
