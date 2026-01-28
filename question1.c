//Place your needed include statements here (This is roughly the equivelent of libraries in python)
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  //Place your solution code here

  size_t n = 0;

  printf("Enter number of elements: ");
  if (scanf("%zu", &n) != 1) {
    fprintf(stderr, "Invalid input for number of elements.\n");
    return 1;
  }

  // Edge case: 0 elements
  if (n == 0) {
    printf("No elements to store. Nothing to print.\n");
    return 0;
  }

  // Allocate memory for n integers
  int *arr = malloc(n * sizeof(int));
  if (arr == NULL) {
    fprintf(stderr, "Memory allocation failed.\n");
    return 1;
  }

  // Read integers
  for (size_t i = 0; i < n; i++) {
    printf("Enter integer %zu: ", i + 1);
    if (scanf("%d", &arr[i]) != 1) {
      fprintf(stderr, "Invalid integer input.\n");
      free(arr);   // avoid memory leak if something goes wrong
      arr = NULL;
      return 1;
    }
  }

  // Print in reverse order
  printf("Integers in reverse order:\n");
  for (size_t i = n; i-- > 0; ) {
    printf("%d", arr[i]);
    if (i != 0) printf(" ");
  }
  printf("\n");

  // Free memory
  free(arr);
  arr = NULL;

  return 0;
}

