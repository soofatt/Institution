#include <stdio.h>
#include "LinkedList.h"
#include "Stack.h"
#include "Institution.h"

Stack stack;

int Institution_reverse(LinkedList *inputList, LinkedList *outputList){
	int counter = 0, i;
	void *tempPtr;
	
	for(tempPtr; tempPtr != NULL; ){
		if((tempPtr = List_removeHead(inputList)) != NULL){
			Stack_push(&stack, tempPtr);
			counter++;
		}
	}
	
	for(i = 0; i < counter; i++){
		tempPtr = Stack_pop(&stack);
		List_addTail(outputList, tempPtr);
	}
	
	return counter;
}