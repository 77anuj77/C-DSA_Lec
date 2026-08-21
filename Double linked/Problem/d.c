#include <stdio.h>
#include <stdlib.h>

struct Node {
    float height;
    struct Node *prev;
    struct Node *next;
};

// Create a new node
struct Node *createNode(float height) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newNode->height = height;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

// Insert node at the end
struct Node *insertEnd(struct Node *head, float height) {

    struct Node *newNode;
    struct Node *temp;

    newNode = createNode(height);

    if (newNode == NULL)
        return head;

    if (head == NULL)
        return newNode;

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

// Delete middle node
struct Node *deleteMiddle(struct Node *head) {

    struct Node *temp;
    int count = 0;
    int middle;
    int i;

    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    // Count nodes
    temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // Find middle position
    middle = (count + 1) / 2;

    temp = head;

    for (i = 1; i < middle; i++) {
        temp = temp->next;
    }

    // Connect previous node to next node
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    // Connect next node to previous node
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    // If only one node existed
    if (temp == head)
        head = temp->next;

    free(temp);

    return head;
}

// Delete node from beginning
struct Node *deleteBeginning(struct Node *head) {

    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);

    return head;
}

// Delete node from end
struct Node *deleteEnd(struct Node *head) {

    struct Node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    }
    else {
        // Only one node
        head = NULL;
    }

    free(temp);

    return head;
}

// Display list
void display(struct Node *head) {

    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%.2f  ", temp->height);
        temp = temp->next;
    }

    printf("\n");
}

int main() {

    struct Node *head = NULL;
    float height;
    int i;

    // Create list of 10 students
    printf("Enter heights of 10 students:\n");

    for (i = 1; i <= 10; i++) {
        printf("Student %d: ", i);
        scanf("%f", &height);

        head = insertEnd(head, height);
    }

    printf("\nOriginal List:\n");
    display(head);

    // (i) Delete middle node
    head = deleteMiddle(head);

    printf("\nAfter deleting middle node:\n");
    display(head);

    // (ii) Delete beginning node
    head = deleteBeginning(head);

    printf("\nAfter deleting beginning node:\n");
    display(head);

    // (iii) Delete end node
    head = deleteEnd(head);

    printf("\nAfter deleting end node:\n");
    display(head);

    return 0;
}