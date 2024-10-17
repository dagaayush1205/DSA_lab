#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node* next;
  struct Node* prev;
};
struct Node* newNode(int val){
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp -> data = val;
  temp -> prev = NULL;
  temp -> next = NULL;
  return temp;
}
void insertionBeginning(struct Node** HEAD, int val){
  struct Node* temp = newNode(val);
  temp -> next = *HEAD;
  temp -> prev = NULL;
  *HEAD = temp;
}
void insert(struct Node** HEAD, int val, int posval){
  struct Node* temp = newNode(val);
  struct Node* current = *HEAD;
  struct Node* currentNext;
  while(current -> data != posval)
    current = current -> next;
  currentNext = current -> next;
  temp -> next = current -> next;
  temp -> prev = current;
  current -> next = temp;
}
void display(struct Node* HEAD)
{
  struct Node* temp = HEAD;
  while(temp != NULL){
    printf("%d ", temp -> data);
    temp = temp ->next;
  }
  printf("\n");
}
int main(){
  struct Node* HEAD = NULL; 
  insertionBeginning(&HEAD,20);
  display(HEAD);           
  insertionBeginning(&HEAD,15);
  display(HEAD);           
  insertionBeginning(&HEAD,10);
  display(HEAD);           
  insertionBeginning(&HEAD,5);
  display(HEAD);
  insert(&HEAD, 12, 10);   
  display(HEAD);           
}
