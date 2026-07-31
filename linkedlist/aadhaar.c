#include <stdio.h>
#include <stdlib.h>

struct node {
    long long aadhar;
    struct node *next;
};

// Create a new node
struct node *createnode(long long aadhar)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->aadhar = aadhar;
    newnode->next = NULL;

    return newnode;
}
void display(struct node *head){
    struct node *temp;
    temp=head;
    printf("\nLinked List: ");
    while(temp!=NULL){
        printf("%lld ->", temp->aadhar);
        temp=temp->next;
    }
    printf("NULL\n");
}

void insertatthirdposition(struct node *head, long long addhar){
    struct node *newnode;
    struct node *temp;

    temp=head->next;

    newnode->next=temp->next;
    head->next =newnode;
    return head;
}





// Insert new node at 3rd position
void insertMiddle(struct node **head, long long aadhar)
{
    struct node *newNode = createnode(aadhar);
    struct node *temp = *head;

    // Move to 2nd node
    temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

// Display the linked list
void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%lld -> ", head->aadhar);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head, *n1, *n2, *n3, *n4;
    long long aadhar;

    // Input Aadhaar numbers
    printf("Enter Employee 1 Aadhaar Number: ");
    scanf("%lld", &aadhar);
    n1 = createnode(aadhar);

    printf("Enter Employee 2 Aadhaar Number: ");
    scanf("%lld", &aadhar);
    n2 = createnode(aadhar);

    printf("Enter Employee 3 Aadhaar Number: ");
    scanf("%lld", &aadhar);
    n3 = createnode(aadhar);

    printf("Enter Employee 4 Aadhaar Number: ");
    scanf("%lld", &aadhar);
    n4 = createnode(aadhar);

    // Link the nodes
    head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    // Display original list
    printf("\nOriginal List:\n");
    display(head);

    // Insert 5th employee
    printf("\nEnter Aadhaar Number of 5th Employee: ");
    scanf("%lld", &aadhar);

    insertatthirdnode(&head, aadhar);

    // Display updated list
    printf("\nList After Insertion:\n");
    display(head);

    return 0;
}




/*
// Function to create a new node
struct node *createNode(long long aadhar) {
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->aadhar = aadhar;
    newNode->next = NULL;

    return newNode;
}

// Insert at 3rd position
void insertMiddle(struct node **head, long long aadhar) {

    struct node *newNode = createNode(aadhar);

    // Move to 2nd node
    struct node *temp = *head;

    for (int i = 1; i < 2; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Display linked list
void display(struct node *head) {

    printf("\nLinked List:\n");

    while (head != NULL) {
        printf("%lld -> ", head->aadhar);
        head = head->next;
    }

    printf("NULL\n");
}

int main() {

    struct node *head = NULL;

    // Creating 4 employee nodes
    head = createNode(111122223333);

    head->next = createNode(222233334444);

    head->next->next = createNode(333344445555);

    head->next->next->next = createNode(444455556666);

    printf("Original List:\n");
    display(head);

    // Insert 5th employee at 3rd position
    insertMiddle(&head, 555566667777);

    printf("\nAfter Inserting at 3rd Position:\n");
    display(head);

    return 0;
}
*/