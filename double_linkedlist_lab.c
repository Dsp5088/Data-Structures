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
int count = 0, i;

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
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) 
	{
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    if (first == NULL) 
	{
        first = last = newnode;
    }
	 else 
	{
        last->next = newnode;
        newnode->prev = last;
        last = newnode;
    }
    count++;
}

void DF() 
{
    if (first == NULL)
	 {
        printf("List is empty\n");
        return;
    }
    struct node *temp = first;
    printf("Forward linked list: ");
    while (temp != NULL) 
	{
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void DB() 
{
    if (last == NULL) 
	{
        printf("List is empty!\n");
        return;
    }
    struct node *temp = last;
    printf("Backward linked list: ");
    while (temp != NULL) 
	{
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void insert()
 {
    int pos, x;
    printf("Enter position to insert (1-%d): ", count + 1);
    scanf("%d", &pos);
    printf("Enter data: ");
    scanf("%d", &x);

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) 
	{
        printf("Memory allocation failed!\n");
        return;
    }
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (pos < 1 || pos > count + 1) 
	{
        printf("Invalid position!\n");
        free(newnode);
        return;
    }

    if (pos == 1) 
	{ 
        newnode->next = first;
        if (first != NULL)
		 {
            first->prev = newnode;
        }
        first = newnode;
        if (last == NULL) 
		{
            last = newnode;
        }
    } else if (pos == count + 1)
	 { 
        last->next = newnode;
        newnode->prev = last;
        last = newnode;
    } else { 
        struct node *temp = first;
        for (i = 1; i < pos - 1; i++)
		 {
            temp = temp->next;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != NULL) 
		{
            temp->next->prev = newnode;
        }
        temp->next = newnode;
    }
    count++;
}

void D()
 {
    int pos;
    printf("Enter position to delete (1-%d): ", count);
    scanf("%d", &pos);

    if (pos < 1 || pos > count) 
	{
        printf("Invalid position!\n");
        return;
    }

    struct node *temp = first;
    if (pos == 1) 
	{ 
        first = first->next;
        if (first != NULL) 
		{
            first->prev = NULL;
        }
        if (first == NULL)
		 { 
            last = NULL;
        }
        free(temp);
    }
	 else if (pos == count) 
	 { 
        temp = last;
        last = last->prev;
        if (last != NULL) 
		{
            last->next = NULL;
        }
        free(temp);
    } 
	else 
	{ 
        for (i = 1; i < pos; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
    count--;
}
