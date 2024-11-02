#include <stdio.h>
#include <stdbool.h>
int tree[10]; 

void root(int val) {
    if (tree[0] != '\0') {
        printf("The tree already has a root node.\n");
    } else {
        tree[0] = val;
    }
}

void left_node(int val, int parent) {
    int place = parent * 2 + 1; 
    if (tree[parent] == '\0') {
        printf("Can't set left child at %d\n", place);
    } else {
        tree[place] = val;
    }
}

void right_node(int val, int parent) {
    int place = parent * 2 + 2;  
    if (tree[parent] == '\0') {
        printf("Can't set right child at %d\n", place);
    } else {
        tree[place] = val;
    }
}

void printtree() {
    for (int i = 0; i<10; i++) {
        if (tree[i]!='\0') {
            printf("node %d: %d \n", i,tree[i]);  
        } //else {
           // printf("-");  
       // }
    }
}

int main() {
  int p;
  int val;
  int parent;
  root(5);

  while(true)
  {
      printf("Enter Function to perform\n 1. insertion at left node \n 2. insertion at right node \n");
      scanf("%d",&p);
      printf("Specify parent: \n");
      scanf("%d",&parent);
      printf("Enter Value: \n");
      scanf("%d",&val);

  
    switch(p){
      case 1:  
        left_node(val, parent);
        break;
      case 2:
        right_node(val, parent);
        break;
      default: 
        printf("Not defined");
        break;
     }
     //right_node('C', 0);      
     //left_node('D', 1);       
     //right_node('E', 2);      
      printf("\n------------------\n");
      printtree();
      printf("\n------------------\n");
  }
    return 1;
}


