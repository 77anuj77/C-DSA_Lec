#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, key,i;
    int *ptr;
    int low, mid, high;
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
    scanf("%d", &key);
    int found=0;
    low = 0;
    high = n-1;
    while (low <= high){
        mid = (low + high)/2;
        if(key==ptr[mid]){
            found=1;
            break;;
        }
        else if (key< ptr[mid]){
            high=mid-1;
        }
        else {
            low = mid + 1;
        }
    }
    if (found==0){
        printf("Element Not Found");
    }
    else{
        printf("Element is at index %d", mid);
    }
    return 0;

}
