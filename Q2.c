/**************************************************************************
****
\file       Q2.c
\author     Muhd Syafiq Bin Idros
\par        SIT email: 2102814@sit.singaporetech.edu.sg
\par        Course: RSE2203
\par        Assignment 1, Q2
\date       01-10-2022
\brief
    This file contains the code for a programme that will take an algebric input
    and check if the parathensis,curly braces,braces are balanced. Where for every
    opening bracket there is a closing bracket and for a pair of brackets the closing
    bracket must come after the opening bracket.

    The functions include:
    - pushone, pushtwo, pushthree
        Pushes the character in a stack & increments the top index.
    - pop
        Removes the character in a stack & decrements the top index.
    - isEmpty
        Checks if the top index for the stacks if it is -1.
****************************************************************************
***/

#include <stdio.h>
#include <string.h>
 
//Defining data structure
struct Stack1{ //handles {}
    int top;
    int array[100];
} st1;
 
struct Stack2{ //handles []
    int top;
    int array[100];
} st2;
 
struct Stack3{ // handles ()
    int top;
    int array[100];
} st3;
 
//Functions
void pushone(int num1){ //Adds an element to the stack and increments top index
    st1.array[st1.top + 1] = num1;
    st1.top++;
}
 
void pushtwo(int num2){
    st2.array[st2.top + 1] = num2;
    st2.top++;
}
 
void pushthree(int num3){
    st3.array[st3.top + 1] = num3;
    st3.top++;
}
 
int pop(int ntype){//Removes top element from the stack and decreases top index
    if (ntype == 1){
        st1.top = st1.top - 1;
        return st1.array[st1.top + 1];
    } else if (ntype == 2){
        st2.top = st2.top - 1;
        return st2.array[st2.top + 1];
    } else if (ntype == 3){
        st3.top = st3.top - 1;
        return st3.array[st3.top + 1];
    }
}
 
//Checks is the stack is empty or not
int isEmpty(){
    if((st1.top == -1) && (st2.top == -1) && (st3.top == -1))
        return 1;
    else
        return 0;
}
 
int main()                      //The main block
{
    char inputVar[100];
   
    //Initialize the top indexes to start at -1
    st1.top = -1;
    st2.top = -1;
    st3.top = -1;
   
    printf("Enter the sequence of braces: \n");
    fgets(inputVar,100,stdin); //reads the input and stores it in a variable
    int inputVarlength = strlen(inputVar); //calculates the length of a given string
   
    for(int i = 0; i < inputVarlength; i++){
        if(inputVar[i] == '{')
            pushone(inputVar[i]);
        else if(inputVar[i] ==  '}')
            pop(1);
        else if(inputVar[i] == '[')
            pushtwo(inputVar[i]);
        else if(inputVar[i] == ']')
            pop(2);
        else if(inputVar[i] == '(')
            pushthree(inputVar[i]);
        else if(inputVar[i] == ')')
            pop(3);
        else
            continue;
    }
   
isEmpty()?printf("It is Legal !"):printf("It is not Legal !");
    return 0;
}
