#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, key,i;
    int *ptr;
    printf("enter the number of element in the array:");
    scanf("%d", &n);
    ptr= (int*)calloc(n, sizeof(int));
    if (ptr==NULL){
        printf(" The memory allocation failed");
    }

    printf("enter the array element:");
    for (i=0; i<n; i++){
        scanf("%d",&ptr);
    }
    printf("enter the key:");
    scanf("%d", key);
    int flag=0;
    for(i=0;i<n;i++){
        if (ptr[i]==key){
            flag=1;
            break;
        }
    }
    if (flag==0){
        printf("Element Not Found");
    }
    else{
        printf("Element is at index %d", i);
    }
    return 0;
}