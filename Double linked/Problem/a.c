#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int rollNo;
    char name[50];
    int age;

    struct Node *prev;
    struct Node *next;
};

// Function to create a node
struct Node *createNode(int rollNo, char name[], int age)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newNode->rollNo = rollNo;
    strcpy(newNode->name, name);
    newNode->age = age;

    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Function to insert node at the end
struct Node *insertEnd(struct Node *head,
                       int rollNo, char name[], int age)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = createNode(rollNo, name, age);

    if (newNode == NULL)
        return head;

    // If list is empty
    if (head == NULL)
        return newNode;

    temp = head;

    // Move to last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Link new node
    temp->next = newNode;
    newNode->prev = temp;

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

    printf("\nStudent Details:\n");

    while (temp != NULL)
    {
        printf("\nRoll No : %d", temp->rollNo);
        printf("\nName    : %s", temp->name);
        printf("\nAge     : %d\n", temp->age);

        temp = temp->next;
    }
}

int main()
{
    struct Node *head = NULL;

    int rollNo, age;
    char name[50];
    int i;

    // Create list of 3 students
    for (i = 1; i <= 3; i++)
    {
        printf("\nEnter details of Student %d\n", i);

        printf("Roll No: ");
        scanf("%d", &rollNo);

        printf("Name: ");
        scanf(" %s", name);

        printf("Age: ");
        scanf("%d", &age);

        head = insertEnd(head, rollNo, name, age);
    }

    // Display the list
    display(head);

    return 0;
} 