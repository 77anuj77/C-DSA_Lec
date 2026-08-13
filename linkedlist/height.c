#include<stdio.h>

struct node{
    int height;
    struct node *next;
};

void newnode(int height){
    struct node *newnode;
    newnode=(struct node*)calloc(sizeof(struct node));

    newnode->height= height;
    newnode->next=NULL;
    
    return newnode;
}

void display(struct node *head){
    struct node *temp;
    temp=head;
    printf("\nLinked list");
    while(temp!=NULL){
        printf("%d", temp->height);
        temp=temp->next;
    }
    printf("NULL\n");
}
struct node* deleting_first_node(struct node *head){
    struct node *temp;
    if (head==NULL){
        printf("\nThe list is empty");
        return head;
    }
    temp=head;
    head=head->next;
    free(temp);

    printf("The first node is deletd successfully!!");
    return head;
};

struct node * delete_from_middle(struct node *head){
    struct node *temp, *prev;
    int i;
    if (head==NULL || head->next ==NULL){
        printf("\nDeletion not possible.");
        return head;
    }
    temp=head;
    for (i=0;i<5;i++){
        prev=temp;
        temp=temp->next;
    }
    prev->next =temp->next;
    free(temp);
    printf("\nThe deletion completed succesfully!!");
    return head;
}

struct node *delete_at_end(struct node *head){
    struct node *temp, *prev;
    int i;
    if (head==NULL){
        printf("\n The list is empty");
        return head;
    }
    if (head->next==NULL){
        free(head);
        return NULL;
    }
    temp= head;
    while (temp!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next= NULL;
    free(temp);
    printf("THE Deletion succesfull!!");
    return head;
}

int main(){
    struct node *head=NULL, *temp=NULL;
    int i,height;
    printf("Enter the height of 10 students: \n");
    for (i=0; i<=10; i++){
        printf("Enter the height of %d student", i);
        scanf("%d", &height);
        newnode(height);
    }
    }