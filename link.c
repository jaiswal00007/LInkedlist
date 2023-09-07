#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // Include this header for getch() function

// Define a struct node
typedef struct node
{
    int data;
    struct node *next;
} Node;

void create(Node *);
void display(Node *);

int main()
{
    int choice;
    Node *head;
    head = (Node *)malloc(sizeof(Node));
    printf("\n----LINKEDLIST PROGRAM----\n");
    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit");
        printf("\nEnter Your Choice::");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:create(head);
            break;
            case 3:display(head);
            break;
            case 4:exit(0);
            break;
            default:printf("Enter Valid Choice!!");
            break;
        }
    }    
    while(choice!=4);
    return 0;// Added return statement to indicate successful program execution
}

void create(Node *list)
{
    char p;
    printf("\nEnter Data: ");
    scanf("%d", &list->data);
    list->next = (Node *)malloc(sizeof(Node));
    printf("Do you want to continue? (Y/N): ");
    p = getch(); // Use getch() to read a character
    if (p == 'Y' || p == 'y') // Use single quotes for characters
    {
        create(list->next);
    }
    else
    {
        list->next = NULL;
        getch();
    }
}

void display(Node *list)
{
    while (list != NULL)
    {
        printf("%d ", list->data);
        list = list->next;
    }
}
