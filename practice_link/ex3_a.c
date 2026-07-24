#include<stdio.h>
#include<stdlib.h>

struct Student {
    char name[50];
    int roll_no;
    int age;
    struct Student* next;
};
// new student node
struct Student* createStudent(char* name, int roll_no, int age) {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    strcpy(newNode->name, name);
    newNode->roll_no = roll_no;
    newNode->age = age;
    newNode->next = NULL; // Default next pointer to NULL
    return newNode;
}

void insertatend(struct Student* head, struct Student* newNode){
    if (head == NULL){
        head = newNode;
    }
    else{
        struct Student* temp = head;
        while (temp->next !=NULL){
            temp = temp->next;
        }
        temp-> next= newNode;
    }
}

void displayList(struct Student* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Student* temp = head;
    while (temp != NULL) {
        printf("Name: %s | Roll No: %d | Age: %d\n", temp->name, temp->roll_no, temp->age);
        temp = temp->next;
    }
}

int main() {
    // Create 3 students
    struct Student* n1 = createStudent("Alice", 101, 20);
    struct Student* n2 = createStudent("Bob", 102, 21);
    struct Student* n3 = createStudent("Charlie", 103, 22);

    // Link them in order
    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    // Display the list
    printf("Linked List of 3 Students:\n");
    displayList(n1);

    return 0;
}