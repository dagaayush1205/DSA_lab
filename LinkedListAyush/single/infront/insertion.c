#include <stdio.h>
#include <stdlib.h>
struct Node{
  int data;
  struct Node* next;
};

struct Node* newNode(int data) {
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data=data;
  temp->next=NULL;
  return temp;
}
void insertbegin(struct Node **HEAD, int val)
{
  struct Node* temp = newNode(val);
  temp -> next = *HEAD;
  *HEAD = temp;

}

void display(struct Node *HEAD){
  struct Node* current = HEAD;
  while(current != NULL)
  {
    printf("%d ",current->data);
    current = current -> next;
  }
}
int main()
{
  int t;
  struct Node* HEAD = NULL;
  while(1>0){
    printf("\nEnter the number ");
    scanf("%d",&t);
    insertbegin(&HEAD,t);
    display(HEAD);
  }
}
