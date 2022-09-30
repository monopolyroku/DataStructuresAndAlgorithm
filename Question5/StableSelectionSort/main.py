'''
@file       main.py
@author     Wong Qi En 
@par        SIT email: 2101737@sit.singaporetech.edu.sg
@par        Course: RSE2203
@par        Assignment 1, Q5
@date       30-09-2022
@brief
    This file contains the code for a Stable Selection Sort algorithm in python.
    The functions include:
    - stableSelectionSort
                sorts the unsorted array using a Stable Selection Sort algorithm

'''

#@function   stableSelectionSort
#@abstract   during each iteration, the smallest item from the unsorted partition will be moved to the sorted partition
#@abstract   as this is a stable variation, a sort key is added to ensure that the equilvalent elements retain their relative positions
#@param      list_a - takes in an unsorted list in function main 
#@returns    list_a

def stableSelectionSort(list_a):
    # Assume last value is the max
    indexing_len = range(0, len(list_a)-1)
    # each time code iterates, first element will be default min
    for i in indexing_len:
      min = i
      # iterate through elements to right of indexing len and replace when something smaller is found
      for j in range(i+1, len(list_a)):
        if list_a[j] < list_a[min]:
            min = j
          
      # if item lesser than default, then switch
      key = list_a[min]
      while min > i:
        list_a[min] = list_a[min - 1]
        min -= 1
      list_a[i] = key  
      
    return list_a

print(stableSelectionSort([4,5,3,2,4,1]))