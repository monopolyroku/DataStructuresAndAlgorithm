#include <stdio.h>
#include <stdlib.h>

int merge(int array[], int p, int q, int r) { 

  // Length of subarray
  int n1 = q - p + 1;
  int n2 = r - q;
  // Initialise two sub arrays
  int sub1[n1], sub2[n2];
  for (int i = 0; i < n1; i++) {
    sub1[i] = array[p + i];
  }
  for (int u = 0; u < n2; u++) {
    sub2[u] = array[q + 1 + u];
  }
  
  // Maintains current index of n1
  int i = 0;
  // Maintains current index of n2
  int j = 0;
  // Maintains the current index of the first element in combined array
  int k = p;

  // Before reaching end of sub1 or sub2, take larger elements and place
  // them in sorted combined array
  while (i < n1 && j < n2) {
    if (sub1[i] <= sub2[j]) {
      array[k] = sub1[i];
      i++;
    } else {
      array[k] = sub2[j];
      j++;
    }
    k++;
  }

  // WHen we run out of elements in sub1 or sub2
  // pick up remaining elements and put in combined array
  while (i < n1) {
    array[k] = sub1[i];
    i++;
    k++;
  }
  while (j < n2) {
    array[k] = sub2[j];
    j++;
    k++;
  }
}

// function to print elements in array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
   printf("%d ", array[i]); 
  }
}

void mergeSort(int array[], int left, int right) {
  if (left < right) {
    // let m be the point where array is divded 
    int mid = (left + right) / 2;
    // Sorts first half
    mergeSort(array, left, mid);
    // Sorts second half 
    mergeSort(array, mid + 1, right);
    // Merges into combined sorted array
    merge(array, left, mid, right);
  }
}

int main(void) {
  int array[] = {4,5,3,1,4,2,6};
  int arrLen = sizeof(array) / sizeof(array[0]);
  printf("Unsorted array:\n");
  printArray(array, arrLen);
  mergeSort(array, 0, arrLen-1);
  printf("\nSorted array:\n");
  printArray(array, arrLen);
}