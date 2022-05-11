#include <iostream>

struct node{
  int digit, height;
  node *left, *right;
};

node* make_node(int digit){
  node* branch = new node;
  branch -> digit = digit;
  branch -> height = 1; 
  branch -> left = nullptr;
  branch -> right = nullptr;
  return branch;
}

int return_height(node *node){
  if (node == nullptr)
    return 0;
  else
    return node -> height;
}

int getdiff(node *N){
  if (N == nullptr)
    return 0;
  return return_height(N -> left) - return_height(N -> right);
}

node *rotation_to_right(node *right_node){
  node *left_node = right_node -> left;
  node *sub_node = left_node -> right;

  left_node -> right = right_node;
  right_node -> left = sub_node;

  right_node -> height = std::max(return_height(right_node -> left), return_height(right_node -> right)) + 1;
  left_node -> height = std::max(return_height(left_node -> left), return_height(left_node -> right)) + 1;

  return left_node;
}

node *rotation_to_left(node *left_node){
  node *right_node = left_node -> right;
  node *sub_node = right_node -> left;

  right_node -> left = left_node;
  left_node -> right = sub_node;

  left_node -> height = std::max(return_height(left_node -> left), return_height(left_node -> right)) + 1;
  right_node -> height = std::max(return_height(right_node -> left), return_height(right_node -> right)) + 1;

  return right_node;
}

node *insert(node* branch, int digit){
  if (branch == nullptr)
    return make_node(digit);

  if (digit == branch -> digit){
    return branch;    
  }
  else if (digit < branch -> digit){
    branch -> left = insert(branch -> left, digit);
  }
  else if (digit > branch -> digit){
    branch -> right = insert(branch -> right, digit);
  }

  branch -> height = std::max(return_height(branch -> left), return_height(branch -> right)) + 1;
  int diff = getdiff(branch);

  if (diff > 1){
      if (digit < branch -> left -> digit)
        return rotation_to_right(branch);
      if (digit > branch -> left -> digit){
        branch -> left = rotation_to_left(branch -> left);
        return rotation_to_right(branch);
      }
  }

  else if (diff < -1){
      if (digit > branch -> right -> digit)
        return rotation_to_left(branch);
    
      if (digit < branch -> right -> digit){
        branch -> right = rotation_to_right(branch -> right);
        return rotation_to_left(branch);
      }
  }
  return branch;
}

void input(node *&root){
    int n = 1;
    while (n != 0){
        std::cin >> n;
        if (n != 0)
          root = insert(root, n);
    }
}

void output(node *num){
    if (num){
        std::cout << "(";
        output(num -> left);
        std::cout << num -> digit;
        output(num -> right);
        std::cout << ")";
    }
}

int main(){
  node *root = nullptr;
  input(root);
  output(root);
  
  return 0;
}
