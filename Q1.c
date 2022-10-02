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
	// Data structure to represent a stack
	Node* head = NULL;
	// Function Definition: Utility function to check if the stack is empty or not
	int SEmpty() {
    if (head == NULL)
        return 1;

    return 0;
}
		
	// Function Definition:
	void push(int data) {

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

	// Function Definition: Utility function to pop a top element from the stack if the stack is not empty
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
	//Function Definition:
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
	//Function Defintion: 
	void print_stack() {
		Node* curr = head;
		printf("\nThe elements in the stack are: ");
	while (curr != NULL)
    {
        printf(" %d ", curr->data);
        curr = curr->next;
    }
	}

	//Function Definition:
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
	//Function Definition:
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
	//Function Definition:
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
	//Function Definition:
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
	//Function Definition:
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
	//Function Definition:
	int isSize(Queue * ref)
	{
		return ref->size;
	}
	//Function Definition:
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
	//Function Definition:
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
		printf(" Size : %d", isSize(q));
		printf("\n Dequeue Node : %d", dequeue(q));
		printf("\n Dequeue Node : %d", dequeue(q));
		printf("\n Dequeue Node : %d", dequeue(q));
		printQdata(q);
		printf(" Size : %d\n", isSize(q));
		push(1);		
		push(2);
		push(4.5);
		push(5);
		stack_size();
		pop();
		pop();
		pop();
		pop();
		stack_size();

		print_stack();

		if (SEmpty()) 
			printf("\nThe stack is empty\n");
		else 
			printf("\nThe stack is not empty\n");
		return 0;

	}