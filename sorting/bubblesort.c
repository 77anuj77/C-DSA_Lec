#include<stdio.h>
void bubblesort(int arr[], int n){
    int i, j, temp;
    for (i=0; i<n; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j]> arr[j+1]){
                temp=arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
}

void printarray(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[5];
    printf("Enter your array of 5 numbers");
    for(int i=0;i<5; i++ ){
        scanf("%d", &arr[i]);
    }

    printf("your given array:\n");
    printarray(arr, 5);
    bubblesort(arr, 5);
    printf("\nyour sorted array:\n");
    printarray(arr, 5);
}