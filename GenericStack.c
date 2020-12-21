#include "gstack.h"
#include <stdio.h>
#include <stdlib.h>

/*----------------------------------------------------------------------------------------------------------------
A structure used to store the data contains a void pointer
to point to any type of data , while next of eacch node will 
point to the recently added data node
----------------------------------------------------------------------------------------------------------------*/
struct data{
	void *data_ptr;
	struct data* next;
};


/*-----------------------------------------------------------------------------------------------------------------
 Function:CreateStack is used to create new stack objects
 Return  :a pointer to a Stack structure
 argument: NONE
-----------------------------------------------------------------------------------------------------------------*/
Stack * CreateStack(void)
{
	//dynamiclly allocate space for a new stack object
	Stack *StackPtr=malloc(sizeof(Stack));
	
	//set the newly created stack's top pointer to NULL as it's still empty
	StackPtr->top=NULL;
	
	//return the address of the created stack 
	return StackPtr;
}


/*-----------------------------------------------------------------------------------------------------------------
Function : CreateNode is used to create a data container"a void pointer"
Return   :a pointer to a data structure
Arguments:A char represet the size of the varible intended to be saved in Bytes
-----------------------------------------------------------------------------------------------------------------*/
static struct data * CreateNode(char element_size){
	
	//dynamiclly allocate space for a newly created data node
	struct data *DataPtr=malloc(sizeof (struct data));
	
	//dynamiclly allocate space sufficient for the date to be saved
	DataPtr->data_ptr= malloc(element_size);
	
	//initially setting the node's next pointer to NULL 
	DataPtr->next=NULL;
	
	//return the address of the data node
	return DataPtr;
}


/*-----------------------------------------------------------------------------------------------------------------
  Function: IsEmpty is used to check if the passed stack is empty or not
  Return  :FALSE if the stack isn't empty , TRUE if emtpy
  Argument: stack address-
------------------------------------------------------------------------------------------------------------------*/
 
static char IsEmpty(Stack *const ptr)
{
	if (ptr->top ==NULL)
	{
		return TRUE;
	}
	else 
	{
		return FALSE;
	}
}



/*------------------------------------------------------------------------------------------------------------------
Function: IsFull is used to check if the stack reached it's maximum size or not ,but
as long as the stack size is being set dynamically so the return of this function will be 
always FALSE as long as malloc function don't fail to create a space for new nodes

Return  :always FALSE
Argument:NONE
-------------------------------------------------------------------------------------------------------------------*/
static char IsFull(Stack *const ptr)
{
	return FALSE;
}




/*------------------------------------------------------------------------------------------------------------------
Function:Push is used to store the passed data into a given stack
Return  :NONE
Argument:stackpre:a pointer to a stack object
         ElementSize: the size of the data to be stored in Bytes
		 PushData: a void pointer to the data to be stored in the stack
-------------------------------------------------------------------------------------------------------------------*/
void push(Stack *stackptr, char ElementSize,void *PushData)
{
	//call the CreateNode function to create a data node
	struct data *DataNode=CreateNode(ElementSize);
	
	//Loop to copy a bytes of momory=ElementSize "copy passed data to stack"
	for (char count=0; count<ElementSize;count++)
	{
		//cast the void pointer to char as it the smallest size that can be passed by the calle
		((char*)DataNode->data_ptr)[count]=((char*)PushData)[count];
	}
	//connect the data nodes together ,making each node's next pointer points at the following data node in the stack
    //the first ever data node's next pointer will have a NULL value 	
	DataNode->next=stackptr->top;
	
    //modify the top pointer to point at the last added data node
	stackptr->top=DataNode;
}


/*--------------------------------------------------------------------------------------------------------------------
Funtion : pop is used to pop data with a given size from the stack 
Return  :a void pointer to a dynamically allocated memory space that holds the popped data
Argument:stackptr: a pointer to stack object
         ElementSize:the size of the needed data to be popped off the stack in bytes
---------------------------------------------------------------------------------------------------------------------*/
void *pop(Stack *stackptr , char ElementSize)
{
	//check if the stack is empty or not if so return a NULL
	if(IsEmpty(stackptr))
	{
		printf("The stack is empty!\n");
		return NULL;
	}
	else{
		//create a temporary void pointer that points to a dynamically allocated memory space equals to a given memory size passed by the callee in bytes
		void *TempPtr=malloc(ElementSize);
		
		//copy the data from the memory to the tempororay pointer
		for(char count=0;count<ElementSize;count++)
		{
			((char*)TempPtr)[count]=((char*)stackptr->top->data_ptr)[count];
		}
		
		//getting the address of the new Top pointer of the stack 
		struct data *PoppedNode=stackptr->top;
		stackptr->top=PoppedNode->next;
		
		//free the allocated space of the popped node
		free(PoppedNode);
		
		//return a pointer to a dynamically allocated momory space that stores the popped data 
		//CAUTION : THE CALLE HAS TO USE THE FREE FUNCTON TO FREE THE ALLOCATED MEMORY SPACE AFTER STORING IT IN A SUITABLE VARIABLE TO AVOID MEMORY LEAKS
		return TempPtr;
	}
}
/*--------------------------------------------------------------------------------------------------------------------------
Functiton:StackDestroy is used to clear all the data stored in a given stack object 
Return   :void
Argument :pointer to Stack object
----------------------------------------------------------------------------------------------------------------------------*/
void StackDestroy(Stack *stackptr)
{
	//create a temporary contaioner to hold the current data node's address stored in Top pointer
	struct data *DestroyNode=NULL;
	
	//iterrate over data node's and Free their space and also free the space allocated for data_ptr 
	while(stackptr->top!=NULL)
	{
    //store the current address stored in "top"
	DestroyNode=stackptr->top;
	
	//getting the address of the next data node and store it in "top"
	stackptr->top=DestroyNode->next;
	
	//free the memory space allocated for the data node
	free(DestroyNode->data_ptr);
	
	//free the memory space allocated for the data_ptr
	free(DestroyNode);
	}
}


