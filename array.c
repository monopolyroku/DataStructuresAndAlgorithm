/*!*************************************************************************
****
\file       main.c
\author     Teo Xin Yi
\par        SIT email: 2102226@sit.singaporetech.edu.sg
\par        Course: RSE2203
\par        Assignment 1, Q3
\date       27-09-2022
\brief
    This file contains the code for an array-based implementation of the
    array list ADT that achieves O(1) time for insertion and removals at
    front and at the end of the array list. It uses the idea of 2's complement.
    The functions include:
    - insert_front
        Insert element at the front of the array.
    - insert_back
        Insert element at the back of the array.
    - remove_front
        Remove the front element in the array.
    - remove_back
        Remove the back element in the array.
    - display
        Displays the array elements.
****************************************************************************
***/
#include <stdio.h>
#include <stdbool.h>

/*!*************************************************************************
****
\brief
	A struct that contains the array elements, start/front position of the
    first array element, rear/back position of the last array element, and
    the array size.
****************************************************************************
***/
typedef struct Array {
    // based on the max size of unsigned char
    int data[256];
    // front position: first element in the array
    // unsigned char because we don't want negative as array index does not
    // contain negative, so by using 2's complement, it will "change" the
    // first position of the array element, which is usually 0, to be negative
    // then based on that negative position, the subscript will calculate
    // the exact position to be the index
    unsigned char fpos;
    // back position: last element in the array
    unsigned char bpos;
    // size_t: shows size of type (which will not be -ve)
    size_t size;
} Array;

/*!*************************************************************************
****
\brief
	A function to insert array elements from the front.

\param array
	The pointer to the array struct.

\param val
	The value to be inserted to the array.
****************************************************************************
***/
void insert_front(Array *array, int val) {
    // fpos and bpos will be the same when inserting the first element
    if(array->data[array->fpos] == 0) {
        array->fpos = array->bpos = 0;
    }
    // when there exists an element in the array, fpos will shift leftwards
    // by a space due to the decrement, which will make fpos become -ve, but
    // since it is unsigned char, fpos/index will move to the back of the
    // array address and store that position as the first element
    else if(array->data[array->fpos] != 0) {
        array->fpos--;
    }
    array->size++;
    // assigning the value to the first element in the array
    array->data[array->fpos] = val;
}

/*!*************************************************************************
****
\brief
	A function to insert array elements from the back.

\param array
	The pointer to the array struct.

\param val
	The value to be inserted to the array.
****************************************************************************
***/
void insert_back(Array *array, int val) {
    if(array->data[array->fpos] == 0) {
        array->fpos = array->bpos = 0;
    }
    // when there exists an element in the array, fpos will shift to the right
    // due to the increment and store that address as the last element
    else if(array->data[array->fpos] != 0) {
        array->bpos++;
    }
    array->size++;
    array->data[array->bpos] = val;
}

/*!*************************************************************************
****
\brief
	A function to remove array elements from the front.

\param array
	The pointer to the array struct.
****************************************************************************
***/
void remove_front(Array *array) {
    if(array->size != 0) {
        array->fpos++;
        array->size--;
    }
}

/*!*************************************************************************
****
\brief
	A function to remove array elements from the back.

\param array
	The pointer to the array struct.
****************************************************************************
***/
void remove_back(Array *array) {
    if(array->size != 0) {
        array->bpos--;
        array->size--;
    }
}

/*!*************************************************************************
****
\brief
	A function to display the array elements.

\param array
	The pointer to the array struct.
****************************************************************************
***/
void display(Array *array) {
    printf("Display array elements:\n");
    if(array->size != 0) {
        for(size_t i=0; i<array->size; ++i) {
            // Need to convert fpos data type to unsigned char so that it can
            // calculate the exact index of the element that it is printing.
            printf("%d ", array->data[(unsigned char)(array->fpos+i)]);
        }
    }
    else {
        printf("Array is empty!\n");
    }
    printf("\n");
    // number of elements in the array
    printf("Size of array: %ld\n\n", array->size);
}

int main(void) {
    // Initialising the array struct
    Array arr;
    for(int i=0; i<256; ++i) {
        arr.data[i] = 0;
    }
    arr.size = 0;
    arr.fpos = 0;
    arr.bpos = 0;

    printf("---------------------\n");
    printf("Test for insert front\n");
    printf("---------------------\n");
    insert_front(&arr, 20);
    display(&arr);
    insert_front(&arr, 3);
    display(&arr);
    insert_front(&arr, 5);
    display(&arr);
    insert_front(&arr, 32);
    display(&arr);

    printf("---------------------\n");
    printf("Test for insert back\n");
    printf("---------------------\n");
    insert_back(&arr, 10);
    display(&arr);
    insert_back(&arr, 4);
    display(&arr);
    insert_back(&arr, 13);
    display(&arr);
    insert_back(&arr, 66);
    display(&arr);

    printf("---------------------\n");
    printf("Test for remove front\n");
    printf("---------------------\n");
    remove_front(&arr);
    display(&arr);

    printf("---------------------\n");
    printf("Test for remove back\n");
    printf("---------------------\n");
    remove_back(&arr);
    display(&arr);

    return 0;
}
