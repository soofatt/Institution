#ifndef _LINKED_LIST_H__
#define _LINKED_LIST_H__

typedef struct LinkedList_t {
	void *head;
	void *tail;
} LinkedList;

void List_addTail(LinkedList *list, void *element);
void *List_removeHead(LinkedList *list);

#endif //_LINKED_LIST_H__