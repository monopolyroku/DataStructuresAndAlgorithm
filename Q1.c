/*!*****************************************************************************
 \file    Q1.c
 \author  Calvin Khor Zhen Loong
 \par     SIT email: 2102535@sit.singaporetech.edu.sg
 \par     Course: RSE2203
 \par     Assignment 1, Q1
 \par     Source file for Doubly Linked List Implementation for queue and stack ADT
 \date    10/2/2022

 \brief
  This source file represents the implementation (of functions) that are used for standard queue operations to implement stack ADT
  

*/
    
    
    
    #include <stdio.h>
	#include <stdlib.h>

	// Data structure for DLL Node
	typedef struct Node
	{
		int data;
		struct Node * next;
		struct Node * prev;
	}Node;
	// Data structure to represent  a queue
	typedef struct Queue
	{
		struct Node * front;
		struct Node * rear;
		int size;
	}Queue;

	Node* head = NULL;
	/* Function Definition: This function is used to check if the stack is empty
       parameters: none
       return: int 1 or 0 depending on the output result
    */
	int SEmpty() {
    if (head == NULL)
        return 1;

    return 0;
}	
	/* Function Definition: This function creates a temp node to store the new data ,if head node is NULL,
                            makes the temp node the head node
                            else makes the next of the temp node as head node
                            prev of the head node as temp and prev of the temp node as NULL. 
                            For the function of pushing an element into a stack
        parameters: int data
        return: void
    */
	void push(int data) {
        //creates a new temp 
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    
    if (SEmpty())
    {
        temp->data = data;
        temp->prev = NULL;
        temp->next = NULL;
        head = temp;
    }
    else
    {   temp->data = data;
        temp->next = head;
        head->prev = temp;
        temp->prev = NULL;
        head = temp;
    }
	
	printf("Push %d into stack\n", head -> data);
}
	/* Function Definition: This function creates a temp node and stores the head in the temp node.
                            Make head as the head's next node then make the head's previous as NULL
                            delete temp node to free memory
                            if there is only 1 node in the list, create a temp node, store the head node, then make head node NULL and delete temp
        parameters: none
        return: none
    */
	void pop() {

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    if (head->next == NULL && head->prev == NULL)
    {
        temp = head;
        head = NULL;
		free(head);
		printf("Pop %d out of stack\n", temp -> data);	
    }
	else
    	{   temp = head;
       	 head = head->next;
       	 head->prev = NULL;
       	 free(temp);
    	}
	
}
	/*Function Definition: This function initializes a count = 0, runs through a while loop, does a count++, and moves curr
                            to the next element until curr!= NULL. Then prints the stack size to terminal
      parameters: none
      return: none
    */
	void stack_size()
	{
    	int count = 0;
	 	Node* curr = head;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    printf("Stack Size: %d\n",count);
	}
	/*Function Defintion: This function runs through a while loop, prints the current element and then moves to next
                         until curr!= NULL. 
      parameters: none
      return: none
     */
	void print_stack() {
		Node* curr = head;
		printf("\nThe elements in the stack are: ");
	while (curr != NULL)
    {
        printf(" %d ", curr->data);
        curr = curr->next;
    }
	}
	/*Function Definition: This function takes in the data and address of the prev node, and 
                            if the ref == NULL, return NULL
                            else 
                            stores data to data, make next NULL and make prev to prev then return ref.
    parameter: int data, Node * prev
    return: ref
    */
	Node * getNode(int data, Node * prev)
	{
		Node * ref = (Node * ) malloc(sizeof(Node));
		if (ref == NULL)
		{
			return NULL;
		}
		ref->data = data;
		ref->next = NULL;
		ref->prev = prev;
		return ref;
	}
	/*Function Definition: This function creates a queue initializing both fron and rear as NULL
      parameters: none
      return: ref
    */
	Queue * getQueue()
	{
		Queue * ref = (Queue * ) malloc(sizeof(Queue));
		if (ref == NULL)
		{
			return NULL;
		}
		ref->front = NULL;
		ref->rear = NULL;
		return ref;
	}
	/*Function Definition: This function is used to at an element at the rear of a queue. data will be added in the new node
                            and will pass it to the next pointer of the rear node.
      parameters: ref, int data
      return: none
    */
	void enqueue(Queue * ref, int data)
	{
		Node * node = getNode(data, ref->rear);
		if (ref->front == NULL)
		{
			ref->front = node;
			ref->size = 1;
		}
		else
		{
			ref->rear->next = node;
			ref->size = ref->size + 1;
		}
		ref->rear = node;
	}
	/*Function Definition: This function is used to check if the queue is empty.
      parameters: ref
      return: int 1 or 0
    */
	int isEmpty(Queue * ref)
	{
		if (ref->size == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	/*Function Definition: This function is used to check look at the front element of the queue
      parameters: ref
      return: ref->front->data
    */
	int peek(Queue * ref)
	{
		if (isEmpty(ref) == 1)
		{
			printf("\n Empty Queue");
			// When stack is empty
			return -1;
		}
		else
		{
			return ref->front->data;
		}
	}
	/*Function Definition: This function is used to get the size of the queue
      parameters: ref
      return: ref-> size
    */
	int Size(Queue * ref)
	{
		return ref->size;
	}
	/*Function Definition: This function is used to delete an element from the front of the queue
      parmeters: ref
      return: data stored in the deleted node
    */
	int dequeue(Queue * ref)

	{
		if (isEmpty(ref) == 1)
		{
			return -1;
		}
		else
		{
			int data = peek(ref);
			Node * temp = ref->front;
			if (ref->front == ref->rear)
			{
				ref->rear = NULL;
				ref->front = NULL;
			}
			else
			{
				ref->front = ref->front->next;
				ref->front->prev = NULL;
			}
			ref->size--;
			return data;
		}
	}
	/*Function Definition: This function is used to print the data in the queue
      parameters: ref
      return: none
    */
	void printQdata(Queue * ref)
	{
		Node * node = ref->front;
		printf("\n Queue Element\n");
		while (node != NULL)
		{
			printf(" %d", node->data);
			node = node->next;
		}
		printf("\n");
	}



	int main()
	{
		Queue * q = getQueue();

		//test case to queue 49 elements 		
		for( int x = 1 ; x <50 ; x++)
			enqueue(q,x);

		printQdata(q);
		printf(" Size : %d", Size(q));
		printf("\n Dequeue Node : %d", dequeue(q));
		printf("\n Dequeue Node : %d", dequeue(q));
		printf("\n Dequeue Node : %d", dequeue(q));
		printQdata(q);
		printf(" Size : %d\n", Size(q));
		push(1);		
        pop();
		stack_size();		
        push(2);
		push(4.5);
		push(5);

		stack_size();

		print_stack();

		if (SEmpty()) 
			printf("\nThe stack is empty\n");
		else 
			printf("\nThe stack is not empty\n");
		return 0;

	}