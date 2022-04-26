//  main.cpp
//  problem 1
//  Created by Михаил Сурмач on 05.04.2022.

#include <iostream>

struct List{
    int x;
    List* next;
};

List* input() {
    List* previous;
    int key;
    List* sub_list = new List;
    std::cin >> sub_list -> x;
    if (sub_list -> x != 0){
        previous = sub_list;
        while (static_cast<void>(std::cin >> key), key != 0){
            List* sub_sub_list = new List;
            sub_sub_list -> x = key;
            previous -> next = sub_sub_list;
            previous = sub_sub_list;
        }
    }
    else
        sub_list -> next = nullptr;
    return (sub_list);
}

void print_list(List *spisok){
   List *p = spisok;
   while (p){
      std::cout << p -> x << std::endl;
      p = p -> next;
   }
}

void add_first_element(List *spisok, int a){
   List *element = new List;
   element -> x = a;
   element -> next = spisok;
   spisok = element;
}

void clear_list(List *spisok){
   List *p = spisok;
   List *t;
   while (p -> next != nullptr){
      t = p;
      p = p -> next;
      delete t;
   }
}

void add_certain_element(List *spisok, int a){
   List *p = new List;
   p -> x = a;

   if (spisok -> x == 0){
      p -> next = 0;
      spisok = p;
      return;
   }

   List *t = spisok;
   if (t -> x >= p -> x){
      p -> next = t;
      spisok = p;
      return;
   }

   List *t1 = t -> next;
   while (t1){
      if (t -> x < p -> x && p -> x <= t1 -> x){ 
         t -> next = p;
         p -> next = t1;
         return;
      }
      t = t1;
      t1 = t1 -> next;
   }
   t -> next = p; 
   p -> next = 0;
}

void remove_certain_element(List *spisok, int a){
   if(spisok == 0){
      return;
   }
   List *t = spisok;
   if(t -> x == a){
      spisok = t -> next;
      delete t;
      return;
   }
   List *t1 = t -> next;
   while(t1){
      if(t1 -> x == a){
         t -> next = t1 -> next;
         delete t1;
         return;
      }
      t = t1;
      t1 = t1 -> next;
   }
}

int main(){
    List *spisok = input();
    int a;
    std::cin >> a;
    add_first_element(spisok, a);
    std::cout << std::endl;
    print_list(spisok);
    int key;
    std::cin >> key;
    remove_certain_element(spisok, key);
    std::cout << std::endl;
    print_list(spisok);
    return 0;
}
