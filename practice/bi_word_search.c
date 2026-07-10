//given an array of woeds sorted in lexicographic (dictionar)order, perform a binary 
//to find the index of a target woed is not present
#include <stdio.h>
#include <string.h>

int binarySearchWord(char *words[], char *target, int size) {
    int low = 0;
    int high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        int cmp = strcmp(words[mid], target);

        if (cmp == 0) {
            return mid;
        } 
        else if (cmp > 0) {
            high = mid - 1;
        } 
        else {
            low = mid + 1;
        }
    }
    return -1;
}
int main() {
    char *words[] = {
        "apple", "banana", "cherry", "grape", "orange", "peach"
    };
    char *target = "grape";
    int size = sizeof(words) / sizeof(words[0]);
    int index = binarySearchWord(words, target, size);
    
    if (index != -1) {
        printf("Word \"%s\" found at index %d\n", target, index);
    } else {
        printf("Word \"%s\" not found\n", target);
    }
    return 0;
}