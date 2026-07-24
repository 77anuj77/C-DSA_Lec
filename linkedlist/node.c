#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;

};
struct node *head=NULL;
struct node* createnode(int data){
    struct node *newnode;
    newnode = (struct  node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void insertatafront(int data){
    struct node *newnode=createnode(data);
    newnode->next= head;
    head=newnode;
}

void insertatend(int data){
    struct node *newnode=createnode(data);
    if (head==NULL){
        head=newnode;
        return;
    }
    struct node *temp =head;
    while (temp->next !=NULL){
        temp= temp-> next ;
    }
    temp -> next =newnode;
}

void insertatposition(int data, int position){
    struct node *newnode=createnode(data);
    if (position==1){
        newnode->next=head;
        return;
    }
    struct node *temp=head;
    int i;
    for (i=1;i< position-1 && temp !=NULL; i++){
        temp = temp->next;
    }
    if (temp==NULL){
        printf("Invalid Position!\n");
        free(newnode);
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void display(){
    struct node *temp=head;
    if (head==NULL){
        printf("Linked list is Empty.\n");
        return;
    }
    printf("linked list: ");
    while (temp!=NULL){
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    int choice, data, position;

    do {
        printf("\n-----Singly Linked List------\n");
        printf("1, Insert at Front\n");
        printf("2, Insert at End\n");
        printf("3, Insert at Position\n");
        printf("4, Display List\n");
        printf("5, Exit\n");

        printf("enter your choice : ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);

                insertatafront(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%D", &data);

                insertatend(data);
                break;
            case 3:
                printf("Enter Data: ");
                scanf("%d", &data);
                printf("Enter Position: ");
                scanf("%d", & position);
                insertatposition(data, position);
                break;

            case 4:
                display();
                break;
            case 5:
                printf("Program Terminated.\n");
                break;

            default:
                printf("Invalid Choice\n");
        }   
    }while (choice != 5);

    return 0;
}