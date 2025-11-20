#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
// Global pointers
struct node *newnode = NULL,*top = NULL,*temp = NULL;
// Function prototypes
void push();
void pop();
void display();
int ele;
int main() {
    int ch;
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
void push() 
{
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL)
	{
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d", &ele);
    newnode->data = ele;
    newnode->next = top;
    top = newnode;
}
void pop() 
{
    if (top == NULL) 
	{
        printf("Stack is empty!\n");
        return;
    }
    temp = top;
    ele = top->data;
    printf("Deleted element is %d\n", ele);
    top = top->next;
    free(temp);
}
void display() 
{
    if (top == NULL)
	 {
        printf("Stack is empty!\n");
        return;
    }
    printf("The stack elements are:\n");
    temp = top;
    while (temp != NULL)
	 {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
