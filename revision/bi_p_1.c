#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int biwordsearch(char words[], char target[], int size){
    int low =0, high=size-1, mid;
    int found=0;
    int index;
    while (low<=high){
        mid=(low+high)/2;
        int cmp = strcmp(words[mid], target);
        if (cmp){
            found =1;
            index= mid;
            break;
        }
        else if (cmp>0){
            high=mid-1;
        }
        else{
            low =mid+1;
        }
    }
    printf("The target word is at index %d", index);
}
int main(){
    char target[20];
    char *words[] = {
        "apple", "banana", "cherry", "grape", "orange", "peach"
    };
    int size= (sizeof(words)/sizeof(words[0]));
    printf("Enter the Target: ");
    scanf("%s" ,&target );
    biwordsearch(words, target, size);
}