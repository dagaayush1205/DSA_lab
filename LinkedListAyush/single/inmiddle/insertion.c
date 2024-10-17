#include <stdio.h>
#include <stdlib.h>

struct Node{
  int val;
  struct Node* next;
};

struct Node* newNode(int val){
  struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
  temp -> val = val;
  temp -> next = NULL;
  return temp;
}
void insert(struct Node **HEAD, int val, int posVal){
  struct Node *temp = newNode(val);
  struct Node *current = *HEAD;
  while(current -> val != posVal)
    current = current -> next;
  temp -> next = current -> next;
  current -> next = temp;
}
struct Node* insertbeginning(struct Node **HEAD,int val){
  struct Node *temp = newNode(val);
  temp -> next = *HEAD;
  *HEAD = temp;
}
void display(struct Node *HEAD){
  struct Node *current = HEAD;
  while(current != NULL){
    printf("%d ", current -> val);
    current = current -> next;
  }
  printf("\n");
}
int main(){
  struct Node *HEAD = NULL;
  insertbeginning(&HEAD,5);
  display(HEAD);
  insertbeginning(&HEAD,10); 
  display(HEAD);
  insertbeginning(&HEAD,15);
  display(HEAD); 
  insert(&HEAD, 12, 10);
  display(HEAD); 
}
