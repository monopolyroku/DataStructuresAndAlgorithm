'''
@file       main.py
@author     Wong Qi En 
@par        SIT email: 2101737@sit.singaporetech.edu.sg
@par        Course: RSE2203
@par        Assignment 1, Q5
@date       30-09-2022
@brief
    This file contains the code for a Stable Quick Sort algorithm in python.
    The functions include:
    - quickSort
        sorts the unsorted array using a Quick Sort algorithm

'''

def quickSort(seq):
    length = len(seq)
    if length <= 1:
        return seq

    else:
        mid = length//2
        pivot = seq[mid]

        itemGreater = []
        itemLower = []
        for index, val in enumerate(seq):
            if index != mid:
                if val < pivot:
                    itemLower.append(val)
                elif val > pivot:
                    itemGreater.append(val)

                # if value is similar then position is considered
                else:
                    if index < mid:
                        itemLower.append(val)
                    else:
                        itemGreater.append(val)
        return quickSort(itemLower) + [pivot] + quickSort(itemGreater)

print(quickSort([4,5,3,2,4,1]))
