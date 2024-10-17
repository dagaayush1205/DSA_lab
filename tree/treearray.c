#include <stdio.h>

char tree[10]; 

void root(char val) {
    if (tree[0] != '\0') {
        printf("The tree already has a root node.\n");
    } else {
        tree[0] = val;
    }
}

void left_node(char val, int parent) {
    int place = parent * 2 + 1; 
    if (tree[parent] == '\0') {
        printf("Can't set left child at %d", place);
    } else {
        tree[place] = val;
    }
}

void right_node(char val, int parent) {
    int place = parent * 2 + 2;  
    if (tree[parent] == '\0') {
        printf("Can't set right child at %d", place);
    } else {
        tree[place] = val;
    }
}

void printtree() {
    for (int i = 0; i<10; i++) {
        if (tree[i]!='\0') {
            printf("%c ", tree[i]);  
        } else {
            printf("-");  
        }
    }
}

int main() {
    root('A');              
    left_node('B', 0);       
    right_node('C', 0);      
    left_node('D', 1);       
    right_node('E', 2);      
    printtree();             
    return 0;
}


