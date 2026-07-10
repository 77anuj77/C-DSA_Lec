#include <stdio.h>
#include <string.h>
#include <ctype.h>

void countWordOccurrence(char str[]) {
    char words[100][50];
    int count[100];
    int n = 0;

    char *token = strtok(str, " ,.!?;:\n");

    while (token != NULL) {
        int found = 0;

        // Convert word to lowercase
        for (int i = 0; token[i] != '\0'; i++) {
            token[i] = tolower(token[i]);
        }

        // Check if word already exists
        for (int i = 0; i < n; i++) {
            if (strcmp(words[i], token) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }

        // If word is new, store it
        if (found == 0) {
            strcpy(words[n], token);
            count[n] = 1;
            n++;
        }

        token = strtok(NULL, " ,.!?;:\n");
    }

    printf("\nWord Occurrence:\n");
    for (int i = 0; i < n; i++) {
        printf("%s --> %d\n", words[i], count[i]);
    }
}

int main() {
    char arr[500];

    printf("Enter text: ");
    fgets(arr, sizeof(arr), stdin);

    countWordOccurrence(arr);

    return 0;
}