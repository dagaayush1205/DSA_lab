#include<stdio.h>
#include<stdlib.h>
#define maxsize 5
void insert();
void deletequeue();
void display();
int front=-1,rear=-1;
int queue[maxsize];
void main()
{
int choice;
while(choice!=4)
{
printf("MENU\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
printf("Enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
insert();
break;
case 2:
deletequeue();
break;
case 3:
display();
break;
case 4:
exit(0);
break;
default:
printf("Enter valid choice");
}
}
}
void insert()
{
int item;
printf("Enter the elements: ");
scanf("%d", &item);
if(rear==maxsize-1)
{
printf("Overflow");
return;
}
if(front == -1&&rear== -1)
{
front=0;
rear=0;
}
else
{
rear=rear+1;
}
queue[rear]=item;
printf("Value inserted");
}
void deletequeue()
{
int item;
if(front==-1 || front>rear)
{
printf("Underflow\n");
return;
}
else
{
item=queue[front];
if(front==rear)
{
front=-1;
rear=-1;
}
else
{
front=front+1;
}
printf("Value deleted");
}
}
void display()
{
int i;
if(rear==-1)
{
printf("Empty Queue");
}
else
{
for(i=front;i<=rear;i++)
{
printf("| %d |",queue[i]);
}
}
}
