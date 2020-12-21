#ifndef _GSTACK_H
#define _GSTACK_H

#define TRUE 1
#define FALSE 0


/*----------------------------------------------------------------------------------------------------------------
A structure used to create stack objects 
contains a pointer to a data structure "Top"
----------------------------------------------------------------------------------------------------------------*/
typedef struct {
	struct data *top;
}Stack;

/*-----------------------------------------------------------------------------------------------------------------
 Function:CreateStack is used to create new stack objects
 Return  :a pointer to a Stack structure
 argument: NONE
-----------------------------------------------------------------------------------------------------------------*/
Stack * CreateStack(void);


/*------------------------------------------------------------------------------------------------------------------
Function:Push is used to store the passed data into a given stack
Return  :NONE
Argument:stackpre:a pointer to a stack object
         ElementSize: the size of the data to be stored in Bytes
		 PushData: a void pointer to the data to be stored in the stack
-------------------------------------------------------------------------------------------------------------------*/
void push(Stack *stackptr, char ElementSize,void *PushData);


/*--------------------------------------------------------------------------------------------------------------------
		//CAUTION : THE CALLE HAS TO USE THE "FREE" FUNCTON TO FREE THE ALLOCATED MEMORY SPACE AFTER STORING IT IN A SUITABLE VARIABLE TO AVOID MEMORY LEAKS

Funtion : pop is used to pop data with a given size from the stack 
Return  :a void pointer to a dynamically allocated memory space that holds the popped data
Argument:stackptr: a pointer to stack object
         ElementSize:the size of the needed data to be popped off the stack in bytes
---------------------------------------------------------------------------------------------------------------------*/
void *pop(Stack *stackptr , char ElementSize);



/*--------------------------------------------------------------------------------------------------------------------------
Functiton:StackDestroy is used to clear all the data stored in a given stack object 
Return   :void
Argument :pointer to Stack object
----------------------------------------------------------------------------------------------------------------------------*/
void StackDestroy(Stack *stackptr);

#endif