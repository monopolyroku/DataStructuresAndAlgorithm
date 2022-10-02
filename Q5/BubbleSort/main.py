'''
@file       main.py
@author     Wong Qi En 
@par        SIT email: 2101737@sit.singaporetech.edu.sg
@par        Course: RSE2203
@par        Assignment 1, Q5
@date       30-09-2022
@brief
    This file contains the code for a Bubble Sort algorithm in python.
    The functions include:
    - bubble
        sorts the unsorted array using bubble algorithm
'''

#@function   bubble
#@abstract   examine consecutive element pairs in the array with each other
#@abstract   if value is lower it will go to the left of the pair
#@abstract   if value is higher it will go to the right of the pair
#@param      list_a - takes in an unsorted list in function main 
#@returns    list_a

def bubble(list_a):
  index_len = len(list_a) - 1
  sorted = False

  while not sorted:
    sorted = True
    for i in range (0, index_len):
      #if item on the left is larger than right, then swap
      if list_a[i] > list_a[i+1]:
        sorted = False
        list_a[i], list_a[i+1] = list_a[i+1], list_a[i]
  return list_a

print(bubble([4,5,3,2,4,1]))