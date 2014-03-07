#include "unity.h"
#include "mock_LinkedList.h"
#include "mock_Stack.h"
#include "Institution.h"

void setUp(){}
void tearDown(){}

void test_Institution_reverse_should_reverse_linked_list_testing_with_2_element(){
	//Test fixture
	Institution institutionArray[2];
	LinkedList inList = {.head = &institutionArray[0], 
						 .tail = &institutionArray[1]};
	LinkedList outList;
	
	List_removeHead_ExpectAndReturn(&inList, &institutionArray[0]);
	Stack_push_Expect(&stack, &institutionArray[0]);
	List_removeHead_ExpectAndReturn(&inList, &institutionArray[1]);
	Stack_push_Expect(&stack, &institutionArray[1]);
	
	List_removeHead_ExpectAndReturn(&inList, NULL);
	
	Stack_pop_ExpectAndReturn(&stack, &institutionArray[0]);
	List_addTail_Expect(&outList, &institutionArray[0]);
	Stack_pop_ExpectAndReturn(&stack, &institutionArray[1]);
	List_addTail_Expect(&outList, &institutionArray[1]);
	
	//Call SUT
	//Institution_reverse(&inList, &outList);
	
	TEST_ASSERT_EQUAL(2, Institution_reverse(&inList, &outList));
}