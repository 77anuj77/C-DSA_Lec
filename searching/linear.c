#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int n, i, key, found = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    ptr = (int *)calloc(n, sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    printf("Enter the number you want to find: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++) {
        if (ptr[i] == key) {
            printf("Element %d found at position %d\n", key, i + 1);
            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("%d is not present in the given array\n", key);
    }

    free(ptr);

    return 0;
}