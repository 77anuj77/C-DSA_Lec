// it only works on sorted array set low=0, high =n-1, find mid=low+high/2
//compare the key with arr[mid], if equal element found.
// if key is smaller, search the left half
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int n, i, key;
    int low, high, mid, found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    ptr = (int *)calloc(n, sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d numbers in sorted order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    printf("Your given sorted numbers are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }

    printf("\nEnter the number you want to search for: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (ptr[mid] == key) {
            found = 1;
            printf("Element %d found at position %d\n", key, mid + 1);
            break;
        } else if (key < ptr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (found == 0) {
        printf("Element does not exist\n");
    }

    free(ptr);

    return 0;
}