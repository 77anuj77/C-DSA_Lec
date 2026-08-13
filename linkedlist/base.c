#include<stdio.h>
struct node{
    long long aadhar;
    struct node *next;
};

struct node *createnewnode(long long aadhar){
    struct node *newnode;
    newnode= (struct node *)malloc(sizeof(struct node));

    newnode-> aadhar=aadhar;
    newnode-> next=NULL;

    return newnode;
}

void insertatmiddle(struct node *head, long long aadhar){
}



