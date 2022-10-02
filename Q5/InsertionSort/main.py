'''
@file       main.py
@author     Wong Qi En 
@par        SIT email: 2101737@sit.singaporetech.edu.sg
@par        Course: RSE2203
@par        Assignment 1, Q5
@date       30-09-2022
@brief
    This file contains the code for a Insertion Sort algorithm in python.
    The functions include:
    - insertionSort
        sorts the unsorted array using insertion sort algorithm
'''

#@function   insertionSort
#@abstract   examine each element in the array and compare to items on the left, if it meets the condition then swap
#@param      list_a - takes in an unsorted list in function main 
#@returns    list_a

def insertionSort(list_a):
  indexing_len = range(1, len(list_a))
  #sort values in indexing length created
  for i in indexing_len:
    valSort = list_a[i]
  # check if item on the left is greater than value to sort, and if i is greater than 0 
    while list_a[i-1] > valSort and i > 0:
      # if it meets the condition, then switch
      list_a[i], list_a[i-1] = list_a[i-1], list_a[i]
      # incrementally going down the list to sort it 
      i = i - 1

  return list_a

print(insertionSort([4,5,3,2,4,1]))