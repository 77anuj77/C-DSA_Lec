#include<stdio.h>
#include<stdlib.h>

int smallest_possitive_integer(int arr[],int size){
    int missing=1;
    int i=0;
    while(i<size){
        if(arr[i]<=0){
            i++;
            continue;
        }
        else if (arr[i]==missing){
            missing=missing+1;
        }
        else{
            return missing;
        }
        i++;
    }
    return missing;

}

int main(){
    int arr[] = {-4, -2, 0, 1, 2, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    smallest_possitive_integer(arr, size);
    printf("The smallest possitive integer in this array is: %d ", smallest_possitive_integer(arr, size));
    return 0;
}
