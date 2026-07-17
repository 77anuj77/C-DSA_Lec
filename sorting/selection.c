
// 25 12 22 11 64 
#include<stdio.h>
void selectionsort(int arr[], int n){
    int i,j, minindex, temp;
    for(i=0;i<n-1;i++){
        minindex=i;
        for (j=i+1; j<n; j++){
            if (arr[j]<arr[minindex]){
                minindex=j;
            }
        }

        temp= arr[minindex];
        arr[minindex]= arr[i];
        arr[i]= temp;

    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main(){
    int arr[]={25,12,22,11,64};
    int size= sizeof(arr)/sizeof(arr[0]);
    printf("Given array--> ");
    printArray(arr, size);
    printf("The sorted array with selection sort--> ");
    selectionsort(arr, size);
    printArray(arr, size);
    return 0;
}