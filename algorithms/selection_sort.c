/*
 * Selection Sort Algorithm Implementation
 *
 * Selection sort is a simple sorting algorithm that works by:
 * 1. Finding the minimum element from the unsorted part of the array
 * 2. Swapping it with the element at the beginning of the unsorted part
 * 3. Moving the boundary of the unsorted part one element to the right
 *
 * Time Complexity:
 * - Best Case: O(n^2)
 * - Average Case: O(n^2)
 * - Worst Case: O(n^2)
 *
 * Space Complexity: O(1) - only requires a single additional memory space for
 * swapping
 */

#include <stdio.h>

void swap(int *a, int *b);
void selectionSort(int arr[], int n);
void printArray(int arr[], int size);

int main() {
  int arr[] = {44, 16, 1, 32, 92, 33, 21, 88, 56, 90, 39, 55};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: \n");
  printArray(arr, n);

  selectionSort(arr, n);

  printf("Sorted array: \n");
  printArray(arr, n);

  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int arr[], int n) {
  int i, j, min_idx;

  // One by one move boundary of unsorted subarray
  for (i = 0; i < n - 1; i++) {
    // Find the minimum element in unsorted array
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }

    // Swap the found minimum element with the first element
    // Only swap if the minimum element is not already at position i
    if (min_idx != i) {
      swap(&arr[min_idx], &arr[i]);
    }
  }
}

void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
