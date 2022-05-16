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

int height(node *root){
    if (root == nullptr)
        return NULL;
    
    int left_height = height(root -> left), right_height = height(root -> right);
    return std::max(left_height, right_height) + 1;
}

void make_space(int a, int b, int c){
    for (int i = 0; i < c - a + b; i++)
        std::cout << " ";
}

void defl(node *root, int level, int counter){
    int tree_height = height(root);

    if (root == nullptr){
        make_space(level, counter, tree_height);
        return;
    }
    if (level == 0){
        make_space(level, counter, tree_height);
        std::cout << root->digit;
    }
    else if (level > 0){
        defl(root -> left, level - 1, counter);
        make_space(level, counter, tree_height);
        defl(root -> right, level - 1, counter);
    }
}

void outreach(node *root){
    int root_height = height(root);
    for(int i = 0; i < root_height; i++){
        for(int j = 0; j < root_height - i; j++)
            std::cout << " ";
        defl(root, i, i);
        std::cout << std::endl;
    }
}

int main(){
    node *root = input();
    outreach(root);

    return 0;
}
