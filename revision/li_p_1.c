#include<stdio.h>
#include<stdlib.h>
#include<ctype.h> 
#include<string.h>
int word_occourence(char str[]){
    int n=0;
    char word[20][100];
    int count[100];
    char *token= strtok(str, ",!");
    while(token!=NULL){
        int found=0;
        for (int i=0; token[i]!='\0'; i++){
            token[i]= tolower(token[i]);
        }
        for (int i = 0; i < n; i++) {
            if (strcmp(word[i], token) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            strcpy(word[n], token);
            count[n] = 1;
            n++;
        }
        token=strtok(NULL, ",!");
    }
    for (int i=0; i<n; i++){
        printf("word: %s--> %d ", word[n], count[i]);
    }
}


int main(){
    char str[500];
    fgets(str, sizeof(str), stdin);
    word_occourence(str);
    return 0;
}