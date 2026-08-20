#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *createNode(int data){
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode ->data=data;
    newNode ->next= NULL;
    return newNode; 
}

struct Node *create(struct Node *head){
    int n,i, data;
    struct Node *newNode, *temp;
    head=NULL;

    printf("Enter the number of nodes:");
    scanf("%d", &n);

    for (i=1, i<n; i++){
        printf("Enter the data:");
        scanf("%d", &data);
        newNode = createNode;
        if (head==NULL){
            head=newNode;
            newNode->next=head;
        }
        else{
            temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next= head;
        }
        return head;
    }
}

struct Node *insertBegining(struct Node *head, int data){
    struct Node *newNode, *temp;
    newNode=create(data);
    if(head==NULL){
        head= newNode;
        newNode->next=head;
        return head;
    }
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newNode->next=head;
    temp->next=newNode;
    head=newNode;
    return head;
}

struct Node *insertEnd(struct Node *head, int data){
    struct Node *newNode, *temp;
    newNode=create(data);
    if (head==NULL){
        head=newNode;
        newNode->next=head;
        return head;
    }
    temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->next=head;
    return head;
}

struct Node *deleteBeginning(struct Node *head){
    struct Node *temp, *last;
    if(head==NULL){
        printf("the list is empty");
        return head;
    }
    //only one Node
    if (head->next==head){
        free(head);
        return NULL;
    }

    last=head;
    while(last->next!=head){
        last=last->next;
    }
    temp=head;
    head=head->next;
    last->next=head;
    free(temp);
    return NULL;
}

struct Node *deleteEnd(struct Node *head){
    struct Node *temp, *sec_last;
    if (head==NULL){
        printf("the list is empty");
    }
    //only one row
    if (head->next==head){
        free(head);
        return NULL;
    }

   temp=head;
    while(sec_last->next->next!=head){
       temp =temp->next;
    }

    free(temp->next);
    temp->next=head;
}

struct Node *reverse(struct Node *head){
    struct Node *prev, *cur, *nextNode, *last;

    if (head==NULL || head->next==head){
        return head;
    }

    prev=head;
    cur=head->next;
    while(cur!=head){
        nextNode=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nextNode;
    }
    //fixing cur head;
    head->next=prev;
    head=prev;

    return head;
}

struct Node *concatinate(struct Node *head1, struct Node *head2){
    struct Node *last1, *last2;

    if (head1==NULL){
        return head1;
    }
    if (head2==NULL){
        return head2;
    }

    last1=head1;
    while(last1!=head1){
        last1=last1->next;
    }
    last2=head2;
    while(last2!=head2){
        last2= last2->next;
    }
    last1->next=head2;
    last2->next=head1;
    return head1;

}

void Display(struct Node *head){
    struct Node *temp;
    temp=head;
    if (head==NULL){
        printf("The list is empty");
        return head;
    }
    while(temp!=NULL){
        printf("====== Data =======");
        printf("data: %d", temp->data);
        temp=temp->next;
    }
    printf("Execution Completed");
}

void displyRev(struct Node *head){
    if (head==NULL){
        return head;
    }
    if(head->next!=head)
        DisplyRev(head->next);
        printf("%d", head->data);
}

int main(){
    struct Node *head1=NULL;
    struct Node *head2=NULL;
    
}