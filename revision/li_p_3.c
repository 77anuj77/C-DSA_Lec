#include<stdio.h>
#include<stdlib.h>
int missing_smallest_possitive(int arr[], int size){
    int found;
    int i=1;
    for (i=1; i<size+1; i++){
        found=0;
        for (int j=0; j<size;j++){
            if (arr[j]==i){
                found=1;
                break;
            }
        }
        if (found==0){
            return i;
        }
    }
    return size +1;
    
}
int main(){
    int arr[]={ -1,3,4,6,7};
    int size= sizeof(arr)/sizeof(arr[0]);
    printf("thte smallest positive number is: %d", missing_smallest_possitive(arr, size));
    return 0;
}