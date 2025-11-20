#include<stdio.h> 
#include<stdlib.h> 

struct queue
{ 
 int data; 
 struct queue *next; 
}; 
typedef struct queue QUEUE;  
void enque(); 
void deque(); 
void display();
QUEUE *front=NULL,*rear=NULL; 

void enque() 
{ 
 QUEUE *new=(QUEUE*)malloc(sizeof(QUEUE)); 
 printf("Enter data to insert:"); 
 scanf("%d",&new->data); 
 new->next=NULL;  
 if(front==NULL) 
 {
 	front=rear=new; 
 }
 else 
 { 
  rear->next=new; 
  rear=new; 
 } 
} 

void deque() 
{ 
 if(front==NULL) 
 printf("Queue is empty!\n"); 
 else 
 { 
  QUEUE *temp=front; 
  if(front==rear) 
  front=rear=NULL; 
  else 
  front=front->next; 
  printf("%d is removed from queue\n",temp->data); 
  free(temp); 
 } 
} 

void display() 
{ 
 if(front==NULL) 
 printf("Queue is empty.\n"); 
 else 
 { 
  QUEUE *temp=front; 
  while(temp!=rear) 
  { 
   printf("%d\t",temp->data); 
   temp=temp->next; 
  } 
  printf("%d\n",temp->data); 
 } 
} 

int main() 
{ 
 int ch; 
  while(1)
 { 
  printf("1.ENQUE\n2.DEQUE\n3.Display\n"); 
  printf("Enter your choice:"); 
  scanf("%d",&ch); 
  switch(ch) 
  { 
   case 1:enque(); break; 
   case 2:deque(); break;  
   case 3:display(); break; 
   default:exit(0); 
  }
 
 }
} 
