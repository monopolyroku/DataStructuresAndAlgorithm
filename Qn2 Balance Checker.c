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
 
//Adds an element to the stack and increments top index
void pushone(int num1){
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
 
//Removes top element from the stack and decreases top index
int popone(){
    st1.top = st1.top - 1;
        return st1.array[st1.top + 1];
}
 
int poptwo(){
    st2.top = st2.top - 1;
        return st2.array[st2.top + 1];
}
 
int popthree(){
    st3.top = st3.top - 1;
        return st3.array[st3.top + 1];
}
 
//Checks is the stack is empty or not
int isEmpty(){
    if((st1.top == -1) && (st2.top == -1) && (st3.top == -1))//DONT TOUCH
        return 1;
    else
        return 0;
}
 
//The main block
int main()
{
    char inputVar[100];
   
    //Initialize the top index to start at -1
    st1.top = -1;
    st2.top = -1;
    st3.top = -1;
   
    printf("Enter the sequence of braces: ");
    fgets(inputVar,100,stdin); //reads the input and stores it in a variable
    int inputVarlength = strlen(inputVar); //calculates the length of a given string
   
    for(int i = 0; i < inputVarlength; i++){
        if(inputVar[i] == '{')
            pushone(inputVar[i]);
        else if(inputVar[i] ==  '}')
            popone();
        else if(inputVar[i] == '[')
            pushtwo(inputVar[i]);
        else if(inputVar[i] == ']')
            poptwo();
        else if(inputVar[i] == '(')
            pushthree(inputVar[i]);
        else if(inputVar[i] == ')')
            popthree();
        else
            continue;
    }
   
isEmpty()?printf("It is Legal !"):printf("It is not Legal !");
    return 0;
}
