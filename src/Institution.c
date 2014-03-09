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

int isUniversityCollege(void *elem1, void *type){
	Institution *selectedInstitution = (Institution *)elem1;
	InstitutionType *institutionType = (InstitutionType *)type;
	
	if(selectedInstitution->type == *institutionType)
		return 1;
	else
		return 0;
}