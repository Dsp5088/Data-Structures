#include<stdio.h>
#include<stdlib.h>
#define size 5

void enq();
void deq();
void display();
int queue[size];
int front=-1,rear=-1,ele;
int main()
{
	int ch;
	while(1)
	{
		printf("\nQueue Operations\n");
		printf("1.Equeue\n2. Dequeue\n3. Display\n4. Exit\n");
		printf("Enter ur choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: enq();break;
			case 2: deq();break;
			case 3: display();break;
			case 4: exit(0);
			default: printf("Inavlid choice!\n");
			
		}
	}
	return 0;
}
void enq()
{
	if(rear==size-1)
	{
		printf("Queue is full\n");
	}
	else
	{
		printf("Enter the Element into the queue:");
		scanf("%d",&ele);
		if(front==-1)
		{
			front=0;
		}
		rear++;
		queue[rear]=ele;
	}
}

void deq()
{
    if(front==-1 || front>rear)
    {
    	printf("Queue is Empty!\n");
	}
	else
	{
		ele=queue[front];
		front++;
		printf("Delete element is %d\n",ele);
		
	}
}

void display()
{
	if(front==-1 || front>rear)
	{
		printf("Queue is empty\n");
	}
	else
	{
		int i;
		printf("Queue elements are: ");
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",queue[i]);
		}
		printf("\n");
	}
}

