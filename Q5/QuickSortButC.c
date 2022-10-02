/*!*************************************************************************
****
\file       QuickSortButC.c
\author     Wong Qi En 
\par        SIT email: 2101737@sit.singaporetech.edu.sg
\par        Course: RSE2203
\par        Assignment 1, Q5
\date       30-09-2022
\brief
    This file contains the code for a Quick Sort algorithm in C.
    The functions include:
    - swap
        swaps two elements
    - position
        finds the position of the pivot
    - quickSort
        function that calls itself recursively to sort the given array
    - printArray
        prints all the elements in an array
****************************************************************************
*/

#include <stdio.h>
#include <stdlib.h>

/*!
@function   swap
@abstract   swaps two elements 
@param      int *a - element on the left
@param      int *b - element on the right
@returns    int
*/

// function to swap elements
int swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

/*!
@function   position
@abstract   finds the position of the pivot, before comparing itself with elements in the array
@abstract   if element is smaller than pivot, swap smaller element with greater element
@abstract   if element is greater than pivot, swap greater element with pivot 
@param      int array[] - takes in an unsorted array in function main 
@param      int low - first element in array
@param      int high - last element in array 
@returns    int
*/

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


/*!
@function   quickSort
@abstract   calls itself recursively to sort the array
@param      int array[] - takes in an unsorted array in function main 
@param      int low - first element in array
@param      int high - last element in array 
@returns    int
*/

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


/*!
@function   printArray
@abstract   prints elements in the array to std output
@param      int array[] - takes in an array
@param      size - takes in the size of the array
@returns    void
*/

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