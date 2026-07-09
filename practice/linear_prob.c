// find the smallest positive integer missing from an unsorted array of integer
// write a finction int findMissinfInteger(int arr[], in size)
//int put array: {-2, 1,3,4,6,2}
// the finction should return the smallest positive integer tha is missig from the array. if the number no integer is missing, the finction should return the next positive integer after the maximum in the array
#include <stdio.h>

int findMissingInteger(int arr[], int size) {
    int i, j, found;

    for (i = 1; i <= size + 1; i++) {
        found = 0;

        for (j = 0; j < size; j++) {
            if (arr[j] == i) {
                found = 1;
                break;
            }
        }

        if (found == 0) {
            return i;
        }
    }

    return size + 1;
}

int main() {
    int arr[] = {-2, 1, 3, 4, 6, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    int missing = findMissingInteger(arr, size);

    printf("Smallest missing positive integer is: %d\n", missing);

    return 0;
}