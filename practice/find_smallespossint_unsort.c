#include <stdio.h>

int findMissingInteger(int arr[], int size) {
    int found;

    // Check every positive integer from 1 to size+1
    for (int i = 1; i <= size + 1; i++) {
        found = 0;

        // Search for i in the array
        for (int j = 0; j < size; j++) {
            if (arr[j] == i) {
                found = 1;
                break;
            }
        }

        // If not found, return it
        if (found == 0) {
            return i;
        }
    }

    return size + 1;
}

int main() {
    int size;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d integers:\n", size);

    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int missing = findMissingInteger(arr, size);

    printf("Smallest missing positive integer = %d\n", missing);

    return 0;
}