'''
@file       main.py
@author     Wong Qi En 
@par        SIT email: 2101737@sit.singaporetech.edu.sg
@par        Course: RSE2203
@par        Assignment 1, Q5
@date       30-09-2022
@brief
    This file contains the code for a Quick Sort algorithm in python.
    The functions include:
    - quickSort
        sorts the unsorted array using a Quick Sort algorithm

'''

#@function   quickSort
#@abstract   Initialises the rightmost element in the list as a pivot and sort items greater than the pivot and items lesser than the pivot
#@abstract   in two separate lists. After wards return the combined list of sorted elements.
#@param      seq - takes in an unsorted list in function main 
#@returns    list_a

def quickSort(seq):
  length = len(seq)
  if length <= 1:
    return seq
  else:    
    pivot = seq.pop()

  itemGreater = []
  itemLower = []

  for item in seq:
    if item > pivot:
      itemGreater.append(item)
    else:
      itemLower.append(item)

  return quickSort(itemLower) + [pivot] + quickSort(itemGreater)

print(quickSort([4,5,3,2,4,1]))
