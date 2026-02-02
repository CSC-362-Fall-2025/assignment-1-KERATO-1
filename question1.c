// Place your needed include statements here
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    (void)argc;
    (void)argv;

    int n = 0;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input for number of elements.\n");
        return 1;
    }

    if (n < 0) {
        fprintf(stderr, "Number of elements cannot be negative.\n");
        return 1;
    }

    if (n == 0) {
        printf("No elements to store. Nothing to print.\n");
        return 0;
    }

    // Allocate memory
    int *arr = malloc((size_t)n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Read integers
    for (int i = 0; i < n; i++) {
        printf("Enter integer %d: ", i + 1);
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid integer input.\n");
            free(arr);
            return 1;
        }
    }

    // Print in reverse
    printf("Integers in reverse order:\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d", arr[i]);
        if (i != 0) printf(" ");
    }
    printf("\n");

    // Free memory
    free(arr);

    return 0;
}

