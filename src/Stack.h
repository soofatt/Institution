#ifndef _STACK_H__
#define _STACK_H__

typedef struct Stack_t {
	void *topOfStack;
} Stack;

void Stack_push(Stack *stack, void *element);
void *Stack_pop(Stack *stack);

#endif //_STACK_H__