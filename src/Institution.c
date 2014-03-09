#include <stdio.h>
#include "CException.h"
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

int Institution_select(LinkedList *inputList, LinkedList *outputList,
					   void *criterion, int (*compare)(void *, void*)){

	int counter = 0, i;
	void *tempPtr;
	
	for(tempPtr; tempPtr != NULL; ){
		if((tempPtr = List_removeHead(inputList)) != NULL){
			if(compare(tempPtr, criterion) == 1){
				Stack_push(&stack, tempPtr);
				counter++;
			}
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

int wasEstablishedBefore(void *elem1, void *year){
	Institution *selectedInstitution = (Institution *)elem1;
	int *yearOfEstablishment = (int *)year;
	
	if(selectedInstitution->yearEstablished > 2014){
		printf("I threw an exception : %d\n", selectedInstitution->yearEstablished);
		Throw(ERR_YEAR_GREATER_THAN_2014);
	}
	else{
		if(selectedInstitution->yearEstablished < *yearOfEstablishment){
			printf("I performed a check : %d\n", selectedInstitution->yearEstablished);
			return 1;
		}
		else{
			printf("I performed a check : %d\n", selectedInstitution->yearEstablished);
			return 0;
		}
	}
}