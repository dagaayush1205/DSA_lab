#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node* next;
};
struct Node* newNode(int val) {
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); //dynamic allocation for linked list
  temp -> data = val;
  temp -> next = NULL;
  return temp;
}
void insert(struct Node **HEAD, int val){
  struct Node* temp = newNode(val);
  temp -> next = *HEAD;
  *HEAD = temp;
}
void sampleCreation(struct Node **HEAD){
  insert(HEAD,5);
  insert(HEAD,10);
  insert(HEAD,15);
  insert(HEAD,20);
}
struct Node* DeleteFirstNode(struct Node* HEAD){
  if(HEAD == NULL)
    return NULL;
  struct Node * temp = HEAD;
  HEAD = HEAD -> next;
  free(temp);
  return HEAD;
}
void display(struct Node *HEAD){
  struct Node* current = HEAD;
  while(current != NULL){
    printf("%d ", current -> data);
    current = current-> next;
  }
}
int main(){
  struct Node* HEAD = NULL;
  sampleCreation(&HEAD);
  display(HEAD);
  HEAD = DeleteFirstNode(HEAD);
  HEAD = DeleteFirstNode(HEAD); 
  display(HEAD);


}
