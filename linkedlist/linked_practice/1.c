#include<stdio.h>
#include<stdlib.h>

struct node{
    long long aadhar;
    struct node *next;
};

void display(struct node *head){
    struct node *temp=head;
    if (head==NULL){
        printf("the list has not enough node");
    }
    while (temp->next->next=NULL){
        temp =temp ->next;
    }
    free(temp->next);
    temp->next=NULL;
}

void reverseDisplay(struct node *head){
    if (head==NULL){
        printf("linked list is empty");
    }
    else{
        reverseDisplay(head->next);
        printf("%lld", head->next);
    }
}

struct node *createNode(long long aadhar){
    struct node *newNode;
    newNode=(struct node *)malloc(sizeof(struct node));
    newNode->aadhar=aadhar;
    newNode->next=NULL;
    return newNode;
};

void Length(struct node *head){
    int count= 0;
    struct node *temp=head;
    while(temp-> next !=NULL){
        temp=temp->next;
        count++;
    }
    printf("%d", count);
}

struct node *insertFront(struct node *head, long long aadhar){
    struct node *temp;
    struct node *newNode=createNode(aadhar);

    newNode->next=head;
    head=newNode;
    return head;
};

struct node *insetEnd(struct node *head, long long aadhar){
    if (head == NULL){
        printf("Empty creating the new node");
        return createNode(aadhar);
    }
    struct node *temp = head;
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    struct node *newNode = createNode(aadhar);
    temp -> next = newNode;
    return head;
};


struct node *insertPosition(struct node *head, long long aadhar, int pos){
    int i;
    struct node *newNode= createNode(aadhar);
    if (head==NULL || head->next==NULL){
        printf("Insertion not possible");
    }
    struct node *temp=head;
    for (i=0; i<=pos-1 && temp!=NULL; i++){
        temp=temp->next;
    }
    if (temp==NULL){
        return head;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    return newNode;
};

struct node *deleteFront(struct node *head){
    if(head == NULL){
        printf("the list is empty");
    }
    struct node *temp=head;
    head=temp->next;
    free(temp);
    return head;
};

struct node *deleteEND(struct node *head){
    if(head==NULL){
        printf("list is empty");
    }
    struct node *temp=head;
    while(temp->next->next !=NULL){
        temp=temp-> next;
    }
    free(temp->next);
    temp->next=NULL;
    return head;
};


struct node *deletePOS(struct node *head, int POS)
{
    if (head == NULL){
        printf("The list is empty\n");
        return NULL;
    }

    if (POS == 1){
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct node *temp = head;
    for (int i = 1; i < POS - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL){
        printf("Invalid position\n");
        return head;
    }

    struct node *del = temp->next;
    temp->next = del->next;

    free(del);

    return head;
}

int main()
{
    struct node *head = NULL;

    // Insert at front
    head = insertFront(head, 111111111111);
    head = insertFront(head, 222222222222);

    // Insert at end
    head = insertEnd(head, 333333333333);
    head = insertEnd(head, 444444444444);

    // Display
    printf("\nLinked List:\n");
    display(head);

    // Length
    Length(head);

    // Reverse display
    printf("\nReverse Linked List:\n");
    reverseDisplay(head);

    // Insert at position
    head = insertPosition(head, 555555555555, 3);

    printf("\n\nAfter insertion at position 3:\n");
    display(head);

    // Delete front
    head = deleteFront(head);

    printf("\nAfter deleting front:\n");
    display(head);

    // Delete end
    head = deleteEND(head);

    printf("\nAfter deleting end:\n");
    display(head);

    // Delete position
    head = deletePOS(head, 2);

    printf("\nAfter deleting position 2:\n");
    display(head);

    return 0;
}