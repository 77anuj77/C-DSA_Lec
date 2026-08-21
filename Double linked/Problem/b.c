#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char pan[11];
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(char pan[])
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    strcpy(newNode->pan, pan);

    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Function to insert a node at the end
struct Node *insertEnd(struct Node *head, char pan[])
{
    struct Node *newNode;
    struct Node *temp;

    newNode = createNode(pan);

    if (newNode == NULL)
    {
        return head;
    }

    // If list is empty
    if (head == NULL)
    {
        return newNode;
    }

    temp = head;

    // Move to last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Link new node at the end
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Function to insert a node at the beginning
struct Node *insertBeginning(struct Node *head, char pan[])
{
    struct Node *newNode;

    newNode = createNode(pan);

    if (newNode == NULL)
    {
        return head;
    }

    // If list is empty
    if (head == NULL)
    {
        return newNode;
    }

    // Link new node before current head
    newNode->next = head;
    head->prev = newNode;

    // Make new node the head
    head = newNode;

    return head;
}

// Function to display the list
void display(struct Node *head)
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%s", temp->pan);

        if (temp->next != NULL)
        {
            printf(" -> ");
        }

        temp = temp->next;
    }

    printf(" -> NULL\n");
}

// Main function
int main()
{
    struct Node *head = NULL;
    char pan[11];
    int i;

    // Create list of first 4 employees
    printf("Enter PAN numbers of 4 employees:\n");

    for (i = 1; i <= 4; i++)
    {
        printf("Enter PAN of employee %d: ", i);
        scanf("%10s", pan);

        head = insertEnd(head, pan);
    }

    // Display list before insertion
    printf("\nPAN list before inserting 5th employee:\n");
    display(head);

    // Input 5th employee PAN
    printf("\nEnter PAN of 5th employee: ");
    scanf("%10s", pan);

    // Insert 5th employee at beginning
    head = insertBeginning(head, pan);

    // Display list after insertion
    printf("\nPAN list after inserting 5th employee at beginning:\n");
    display(head);

    return 0;
}