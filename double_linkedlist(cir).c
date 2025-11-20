#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};

struct node *first=NULL;
struct node *last=NULL;
int count =0,i;

void create();
void DB();
void DF();
void insert();
void D();

int main()
{
	int ch;
	while(1)
	{
		printf("\n1. create\n2. display forward\n3. displaybackward\n4. insert\n5. delete\n6. exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:create();break;
			case 2:DF();break;
			case 3:DB();break;
			case 4:insert();break;
			case 5:D();break;
			case 6:exit(0);
			default:printf("Invalid choice! try again.\n");
			
		}
	}
	return 0;
}

void create()
{
	struct node *newnode =(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory allocation failed!\n");
	}
	printf("Enter data: ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	if(first==NULL)
	{
		first=last=newnode;
	}
	else
	{
		last->next=newnode;
		newnode->prev=last;
		last=newnode;
	}
	count++;
}

void DF()
{
	if(first==NULL)
	{
		printf("List is empty\n");
		return;
	}
	struct node *temp=first;
	printf("Forward linked list: ");
	while(temp!=NULL)
	{
		printf("%d<->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}

void DB()
{
	if(last==NULL)
	{
		printf("List is empty!\n");
		return;
	}
	struct node* temp=last;
	printtf("Backward linked list: ");
	while(temp!=last)
	{
		printf("%d->",temp->data);
		temp=temp->prev;
	}
	printf("NULL\n");
}

void insert()
{
	int pos ,x;
	printf("Enter position to insert(1-%d):  ",count+1);
	scanf("%d",&pos);
	printf("Enter data: ");
	scanf("%d",&x);
	newnode->data=x;
	newnode->next=NULL;
	newnode->prev=NULL;
	
	if(pos<1||pos>count+1)
	{
		printf("Invalid position!\n");
		free(newnode);
		return;
	}
	
	if(pos==1)
	{
		newnode->next=first;
		if(first!=NULL)
		{
			first->prev=newnode;
			first=newnode;
		}
		if(last==NULL)
		{
			last=newnode;
		}
		else
		{
			struct node* temp=first;
			for(i=1;i<pos-1;i++)
			{
			   temp=temp->next;	
			}
			newnode->next=temp->next;
			temp->next=newnode;
			
			if(pos==count+1)
			{
				last=newnode;
				last->next=first;
			}
		}
	}
	count++;
}


