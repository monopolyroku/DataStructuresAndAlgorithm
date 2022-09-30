#include <stdio.h>
#include <stdlib.h>

// function to swap elements
int swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// function to find position of pivot
int position(int array[], int low, int high) {
  // find rightmost element and set as pivot
  int pivot = array[high];
  // the pointer element greater than pivot
  int i = low - 1;
  // go down the array and compare elements with pivot 
  for (int u = low; u < high; u++) {
    if (pivot > array[u]) {  
     // if element smaller than pivot is found
     // swap smaller element with greater element
      i++;
      swap(&array[i], &array[u]);
    }
  }
  // swap greater element with pivot 
  swap(&array[i+1], &array[high]);
  // return partition point
  return (i+1);
  }


// function that calls itself recursively
int quickSort(int array[], int low, int high) {
  if (low < high) {
    // assign position of elements smaller and larger respectively and assign them to pivot_location
    int pivotLocation = position(array, low, high);
    // recursive call on leftside
    quickSort(array, low, pivotLocation - 1);
    // recursive call on rightside 
    quickSort(array, pivotLocation + 1, high);
  }
}

// function to print elements in array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
   printf("%d ", array[i]); 
  }
}

  
int main(void) {
  int array[] = {4,5,3,1,4,2};
  int arrLen = sizeof(array) / sizeof(array[0]);
  
  printf("Unsorted array:\n");
  printArray(array, arrLen);
  // use quickSort algorithm to sort elements in array
  quickSort(array, 0, arrLen);
  printf("\nSorted array:\n");
  printArray(array, arrLen);
}