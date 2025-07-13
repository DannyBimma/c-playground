/*
 * Copyright (c) 2025 DannyBimma. All Rights Reserved.
 * Bubble Sort Algorithm Implementation
 *
 * It works by repeatedly stepping through the list, comparing adjacent
 * elements, and swapping them if they are in the wrong order.
 *
 * Time Complexity:
 * - Best Case: O(n) - when array is already sorted
 * - Average Case: O(n^2)
 * - Worst Case: O(n^2)
 *
 * Space Complexity: O(1) - only requires a single additional memory space for
 * swapping
 */

#include <stdio.h>

static void int_swap(int *a, int *b);
void bubbleSort(int arr[], int n);
void printArray(int arr[], int size);

int main() {
  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original array: \n");
  printArray(arr, n);

  bubbleSort(arr, n);

  printf("Sorted array: \n");
  printArray(arr, n);

  return 0;
}

static void int_swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int arr[], int n) {
  int i, j;
  int swapped;

  for (i = 0; i < n - 1; i++) {
    swapped = 0;

    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        int_swap(&arr[j], &arr[j + 1]);
        swapped = 1;
      }
    }

    if (swapped == 0)
      break;
  }
}

void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
