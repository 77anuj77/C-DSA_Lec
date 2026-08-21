#include <stdio.h>
#include <stdlib.h>

struct Node {
    unsigned long long aadhar;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(unsigned long long aadhar) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newNode->aadhar = aadhar;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Function to insert node at the end
struct Node *insertEnd(struct Node *head,
                       unsigned long long aadhar) {

    struct Node *newNode;
    struct Node *temp;

    newNode = createNode(aadhar);

    if (newNode == NULL)
        return head;

    // If list is empty
    if (head == NULL) {
        return newNode;
    }

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Function to insert node at 3rd position
struct Node *insertMiddle(struct Node *head,
                          unsigned long long aadhar) {

    struct Node *newNode;
    struct Node *temp;

    newNode = createNode(aadhar);

    if (newNode == NULL)
        return head;

    temp = head;

    // Move to 2nd node
    temp = temp->next;

    // Connect new node between 2nd and 3rd node
    newNode->next = temp->next;
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;

    return head;
}

// Function to display the list
void display(struct Node *head) {

    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("\nAadhar Numbers:\n");

    while (temp != NULL) {
        printf("%llu\n", temp->aadhar);
        temp = temp->next;
    }
}

int main() {

    struct Node *head = NULL;
    unsigned long long aadhar;
    int i;

    // Create list of 4 employees
    for (i = 1; i <= 4; i++) {

        printf("Enter Aadhar number of employee %d: ", i);
        scanf("%llu", &aadhar);

        head = insertEnd(head, aadhar);
    }

    // Input 5th employee
    printf("\nEnter Aadhar number of 5th employee: ");
    scanf("%llu", &aadhar);

    // Insert at 3rd position
    head = insertMiddle(head, aadhar);

    // Display final list
    display(head);

    return 0;
}