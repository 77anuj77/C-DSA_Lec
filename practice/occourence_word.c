// write a c program that takes a text as input and counts the occurence of each word. words are seperated by spaces punctuations.
// display each unique word along eith its count
#include <stdio.h>
#include <string.h>
void countwordoccourence(char brr[]){
    char *token;
    token = strtok(brr, " ");
    int i=1;
    while(token!=NULL){
        printf("%s -->%d\n", token, i);
        token =strtok(NULL, " ");
        i++;
    }
}
int main() {
    char arr[20];
    

    printf("Enter text: ");
    fgets(arr, sizeof(arr), stdin);

    printf("You entered: %s\n", arr);
    countwordoccourence(arr);
    

    return 0;
}

/*while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }*/