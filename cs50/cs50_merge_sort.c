/*
 * Merge Sort Algorithm Implementation
 *
 * Merge sort is an efficient, stable, divide-and-conquer sorting algorithm.
 * It works by:
 * 1. Dividing the input array into two halves
 * 2. Recursively sorting the two halves
 * 3. Merging the sorted halves to produce the final sorted array
 *
 * Time Complexity:
 * - Best Case: O(n log n)
 * - Average Case: O(n log n)
 * - Worst Case: O(n log n)
 *
 * Space Complexity: O(n) - requires additional space for merging
 */

#include <stdio.h>
#include <stdlib.h> // For malloc and free

// Function prototypes
void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);
void printArray(int arr[], int size);

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: \n");
  printArray(arr, n);

  mergeSort(arr, 0, n - 1);

  printf("Sorted array: \n");
  printArray(arr, n);

  return 0;
}

// Merge two subarrays of arr[]
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1; // Size of left subarray
  int n2 = r - m;     // Size of right subarray

  // Create temporary arrays
  int *L = (int *)malloc(n1 * sizeof(int));
  int *R = (int *)malloc(n2 * sizeof(int));

  if (L == NULL || R == NULL) {
    printf("Memory allocation failed\n");
    if (L != NULL)
      free(L);
    if (R != NULL)
      free(R);
    return;
  }

  // Copy data to temporary arrays L[] and R[]
  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  // Merge the temporary arrays back into arr[l..r]
  i = 0; // Initial index of first subarray
  j = 0; // Initial index of second subarray
  k = l; // Initial index of merged subarray

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of L[], if any
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copy the remaining elements of R[], if any
  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }

  // Free the allocated memory
  free(L);
  free(R);
}

// Main function that sorts arr[l..r] using merge()
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // Find the middle point
    int m = l + (r - l) /
                    2; // Same as (l+r)/2 but avoids overflow for large l and r

    // Sort first and second halves
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted halves
    merge(arr, l, m, r);
  }
}

// Function to print an array
void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
