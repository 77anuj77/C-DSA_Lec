// 50 30 70 10 90 40 80
// 50 30 70 10 40 90 80 
// 50 30 70 10 40 80 90
// 30 50 70 10 40 80 90
// 30 10 70 50 40 80 90
// 30 10 40 50 70 80 90

#include <stdio.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main(void) {
    int arr[100];
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Please enter a size between 1 and 100.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nYour given array:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array in ascending order:\n");
    printArray(arr, n);

    return 0;
}