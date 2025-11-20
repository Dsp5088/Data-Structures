#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int data;
	struct queue *next;
};
typedef struct queue QUEUE;
QUEUE *front=NULL,*rear=NULL;
void enq();
void deq();
void display();

int main()
{	
   int ch;
   while(1)
   {
   	printf("1.enq 2.deq 3.display 4.exit\n");
   	scanf("%d",&ch);
   	switch(ch)
   	{
   	   case 1:enq();break;
	   case 2:deq();break;
	   case 3:display();break;
	   default:exit(0);
	}
   }
}

void enq() 
{
	int ele;
	QUEUE *new=(QUEUE*)malloc(sizeof(QUEUE));
	printf("enter data:");
	scanf("%d",&ele);
	new->data=ele;
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
void deq()
{
	if(front==NULL)
	{
		printf("queue is empty!");
	}
	else
	{
		 QUEUE *temp=front;
		if(front==rear)
		{
			front=rear=NULL;
		}
		else
		{
			front=front->next;
			
		}
		printf("deleted element is %d\n",temp->data);
	    free(temp);
	}
	
}

void display()
{
	if(front==NULL)
	{
		printf("queue is empty!\n");
	}
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













	
