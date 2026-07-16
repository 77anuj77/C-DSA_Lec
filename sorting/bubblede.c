#include<stdio.h>
// Returns 1 if the array is already in descending order
// Otherwise returns 0
int health(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            return 0;
        }
    }

    return 1;
}
 
void bubblesort(int arr[], int n){
    int i, j, temp;
    for (i=0; i<n; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j]< arr[j+1]){
                temp=arr[j+1];
                arr[j+1]= arr[j];
                arr[j]= temp;
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
    int check;
    check=health(arr,5);
    if(check==1){
        printf("\nThe array is already in decs order");
    }
    else{
        bubblesort(arr, 5);
        printf("\nyour sorted array:\n");
        printarray(arr, 5);
    }
}