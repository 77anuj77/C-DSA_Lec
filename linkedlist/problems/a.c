#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int rollNo;
    char name[50];
    int age;
    struct node *next;
};

struct node *createNode(int rollNo, char name[], int age){
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->rollNo = rollNo;
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = NULL;
    return newNode;
}

void display(struct node *head){
    struct node *temp = head;
    while (temp != NULL){
        printf("Roll No : %d\n",temp->rollNo);
        printf("Name    : %s\n",temp->name);
        printf("Age     : %d\n",temp->age);
        printf("-------------------\n");
        temp = temp->next;
    }
}

void freeList(struct node *head)
{
    struct node *temp;

    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    struct node *n1;
    struct node *n2;
    struct node *n3;

    n1 = createNode(1, "Anuj", 20);
    n2 = createNode(2, "Rahul", 21);
    n3 = createNode(3, "Amit", 19);

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    display(n1);
    freeList(n1);
    return 0;
}