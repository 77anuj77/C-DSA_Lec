#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

//Bubble Sort
void bubbleSort(int arr[], int n){
    int i,j,temp;

    for(i=0;i<n-1;i++){
        for(j=0;j<=n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void selectionSort(int arr[], int n){
    int i,j,minIndex,temp;

    for(i=0;i<n;i++){
        minIndex=i;

        for(j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
        }

        temp=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
}

//Insertion Sort
void insertionSort(int arr[], int n)
{
    int i,key,j;

    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;

        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=key;
    }
}

int main(){
    int arr[SIZE];
    int arr1[SIZE];
    int arr2[SIZE];
    int arr3[SIZE];
    int i;

    clock_t start, end;
    double time_taken;

    //generate random numbers
    srand(time(NULL));

    for(i=0;i<SIZE;i++){
        arr[i]=rand();
    }

    //copy contents of arr[] to other arrays
    for(i=0;i<SIZE;i++){
        arr1[i]=arr[i];
        arr2[i]=arr[i];
        arr3[i]=arr[i];
    }

    //bubble sort timing
    start=clock();
    bubbleSort(arr1,SIZE);
    end=clock();

    time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Bubble sort time =%f seconds \n", time_taken);

    //Selection sort timing
    start=clock();
    selectionSort(arr2, SIZE);
    end=clock();

    time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Selection Sort Time = %f seconds \n", time_taken);

    //Insertion sort timing
    start=clock();
    insertionSort(arr3,SIZE);
    end=clock();

    time_taken=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Insertion sort time = %f seconds \n", time_taken);

    return 0;
}
