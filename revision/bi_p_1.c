#include <stdio.h>
#include <string.h>

int biwordsearch(char *words[], char *target[], int size)
{
    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int cmp = strcmp(words[mid], target);

        if (cmp == 0)
        {
            return mid;
        }
        else if (cmp > 0)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    char *target[20];

    char *words[] = {
        "apple",
        "banana",
        "cherry",
        "grape",
        "orange",
        "peach"
    };

    int size = sizeof(words) / sizeof(words[0]);

    printf("Enter target word: ");
    scanf("%s", target);

    int index = biwordsearch(words, target, size);

    if (index != -1)
        printf("The target word is at index %d\n", index);
    else
        printf("Word not found\n");

    return 0;
}