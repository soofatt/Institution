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
	TEST_ASSERT_EQUAL(2, Institution_reverse(&inList, &outList));
}

void test_Institution_reverse_should_reverse_linked_list_testing_with_3_element(){
	//Test fixture
	Institution institutionArray[3];
	LinkedList inList = {.head = &institutionArray[0], 
						 .tail = &institutionArray[2]};
	LinkedList outList;
	
	List_removeHead_ExpectAndReturn(&inList, &institutionArray[0]);
	Stack_push_Expect(&stack, &institutionArray[0]);
	List_removeHead_ExpectAndReturn(&inList, &institutionArray[1]);
	Stack_push_Expect(&stack, &institutionArray[1]);
	List_removeHead_ExpectAndReturn(&inList, &institutionArray[2]);
	Stack_push_Expect(&stack, &institutionArray[2]);
	
	List_removeHead_ExpectAndReturn(&inList, NULL);
	
	Stack_pop_ExpectAndReturn(&stack, &institutionArray[0]);
	List_addTail_Expect(&outList, &institutionArray[0]);
	Stack_pop_ExpectAndReturn(&stack, &institutionArray[1]);
	List_addTail_Expect(&outList, &institutionArray[1]);
	Stack_pop_ExpectAndReturn(&stack, &institutionArray[2]);
	List_addTail_Expect(&outList, &institutionArray[2]);
	
	//Call SUT
	TEST_ASSERT_EQUAL(3, Institution_reverse(&inList, &outList));
}

void test_Institution_reverse_should_reverse_linked_list_testing_with_4_element(){
	//Test fixture
	Institution institutionArray[4];
	LinkedList inList = {.head = &institutionArray[0], 
						 .tail = &institutionArray[3]};
	LinkedList outList;
	
	List_removeHead_ExpectAndReturn(&inList, &institutionArray[0]);
	Stack_push_Expect(&stack, &institutionArray[0]);
	List_removeHead_ExpectAndReturn(&inList, &institutionArray[1]);
	Stack_push_Expect(&stack, &institutionArray[1]);
	List_removeHead_ExpectAndReturn(&inList, &institutionArray[2]);
	Stack_push_Expect(&stack, &institutionArray[2]);
	List_removeHead_ExpectAndReturn(&inList, &institutionArray[3]);
	Stack_push_Expect(&stack, &institutionArray[3]);
	
	List_removeHead_ExpectAndReturn(&inList, NULL);
	
	Stack_pop_ExpectAndReturn(&stack, &institutionArray[0]);
	List_addTail_Expect(&outList, &institutionArray[0]);
	Stack_pop_ExpectAndReturn(&stack, &institutionArray[1]);
	List_addTail_Expect(&outList, &institutionArray[1]);
	Stack_pop_ExpectAndReturn(&stack, &institutionArray[2]);
	List_addTail_Expect(&outList, &institutionArray[2]);
	Stack_pop_ExpectAndReturn(&stack, &institutionArray[3]);
	List_addTail_Expect(&outList, &institutionArray[3]);
	
	//Call SUT
	TEST_ASSERT_EQUAL(4, Institution_reverse(&inList, &outList));
}

void test_isUniversityCollege_should_return_1_if_type_is_same_and_return_0_if_otherwise(){
	//Test fixture
	Institution institutionArray[2] = {{.type = University},
									   {.type = UniversityCollege}};
									   
	InstitutionType *institutionType = (InstitutionType *)UniversityCollege;
	
	LinkedList inList = {.head = &institutionArray[0], 
						 .tail = &institutionArray[1]};
	LinkedList outList;
	
	//printf("institutionArray[1].type = %d\n", institutionArray[1].type);
	//printf("instType = %d\n", institutionType);
	
	//Call SUT
	TEST_ASSERT_EQUAL(0, isUniversityCollege(&institutionArray[0], &institutionType));
	TEST_ASSERT_EQUAL(1, isUniversityCollege(&institutionArray[1], &institutionType));
	
}
