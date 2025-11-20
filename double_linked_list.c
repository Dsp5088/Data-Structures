#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *first = NULL;
struct node *last = NULL;
int count = 0;

void create();
void DB();
void DF();
void insert();
void D();

int main() {
    int ch;
    while (1) 
	{
        printf("\n1. create\n2. DisplayForward\n3. DisplayBackward\n4. insert\n5. deletenode\n6. exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) 
		{
            case 1:create();break;
            case 2:DF();break;
            case 3:DB();break;
            case 4:insert();break;
            case 5:D();break;
            case 6:
                exit(0);
            default:printf("Invalid choice.\n");
        }
    }
    return 0;
}

void create()
{
	int d;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&d);
	newnode->data=d;
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
	struct node *temp=first;
	if(first==NULL)
	{
		printf("list is empty!");
		free(temp);
		return;
	}
	while(temp!=NULL)
	{
		printf("%d<->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");	
}

void DB()
{
	struct node *temp=last;
	if(last==NULL)
	{
		printf("list is empty!");
		free(temp);
		return;
	}
	while(temp!=NULL)
	{
		printf("%d<->",temp->data);
		temp=temp->prev;
	}
	printf("NULL\n");
}

void insert()
{
	int pos,x;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	printf("enter pos to insert(1-%d)",count+1);
	scanf("%d",&pos);
	printf("enter data:");
	scanf("%d",&x);
	newnode->data=x;
	newnode->next=NULL;
	newnode->prev=NULL;
	
	if(pos<1||pos>count+1)
	{
		printf("Invalid position!");
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
		else
		{
			first=last=newnode;
		}	
	}
	else if(pos==count+1)
	{
		last->next=newnode;
		newnode->prev=last;
		last=newnode;
	}
	else
	{
		struct node *temp=first;
		int i;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->next;
		}
		newnode->next=temp->next;
		newnode->prev=temp;
		if(temp->next!=NULL)
		{
			temp->next->prev=newnode;
		}
		temp->next=newnode;
	}
	count++;
}

void D()
{
	int pos;
	printf("enter postion to delete (1-%d)",count);
	scanf("%d",&pos);
	if(pos<1||pos>count)
	{
		printf("invalid chioce!");
		return;
	}
	if(pos==1)
	{
		first=first->next;
		if(first!=NULL)
		{
			first->prev=NULL;
		}
		else
		{
			first=last=NULL;
		}
	}
	else if(pos==count)
	{
		last=last->prev;
		last->next=NULL;
	}
	else
	{
		struct node *temp=first;
		int i;
		for(i=1;i<pos;i++)
		{
			temp=temp->next;
		}
		temp->prev->next=temp->next;
		if(temp->next!=NULL)
		{
			temp->next->prev=temp->prev;
		}
		free(temp);
	}
	count--;
	
	
}




























