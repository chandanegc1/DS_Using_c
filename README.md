# DS_Using_c
Data Structures Using C 
#Data Structures Using C

##Linked_list:

It is a data type that holds the first and last element of a linked list(head and tail). It may also contain the number of elements in that list. we defined it as follows. typedef struct element{ void *value; struct element *next; } Element; typedef struct linkedList{ Element *head,*tail; int length; } Linked_list;

##Linked_list createList(void); This function create an empty Linked_list structure.

##int add_to_list(Linked_list *,void *); It given a reference to some data, add it to list. For now, add it to the end of the list.

##void *get_first_element(Linked_list list); This function returns the first element in the list.

##void *get_last_element(Linked_list list); This function returns the first element in the list.

##void forEach(Linked_list, ElementProcessor e) where ElementProessor is a function pointer type with the following signature:

##void (*ElementProcessor)(void *) Write a generic traverse function that can go through a list and process each element. Example: void increment(void *){ // code } forEach(list,&increment);

##void * getElementAt(Linke_list, int ) Given an index as an integer, return the data reference contained at that position in the list. For ex: getElementAt(2) should return the element at index 2. This is basically like an array's [] operator. Return NULL if index is invalid.

##int indexOf(Linked_list, void *) Given an element, find the first index at which this element occurs in a list. Return -1 if not found.

##void * deleteElementAt(Linked_list *, int) Given an index, delete the element at that list. Return the data referenced by the node at that position.

##int asArray(Linked_list, void **, int maxElements) Given a linked list and a reference to an array, this function will populate the array with all the elements of a list(or maxElements, whichever is smaller) and finally return the number of elements added to the array. Each element of the array will contain a reference to each piece of data in the linked list.

##LinkedList filter(Linked_list, MatchFunc ) where the signature of the MatchFunc is: int MatchFunc(void* hint, void* item); Given a linked list and a function pointer, this function will filter the original list and return a new LinkedList that consists only of references to data that	satisfy the filtering criteria. This is basically the same as ArrayUtil's filter, except, we return a Linked_list instead of an ArrayUtil.

##Linked_list reverse(Linked_list) This function will take a LinkedList as an argument and return a Linked_list with the order of the elements of the source Linked_list reversed. Do not modify the existing Linked_list.

##Linked_list map(Linked_list, ConvertFunc, void * ) where the signature of the ConvertFunc is: void ConvertFunc(void* hint, void* sourceItem, void* destinationItem);

##Linked_list reduce(Linked_list, Reducer, void hint, void initialValue); where the signature of Reducer is: void Reducer(void hint, void* previousItem, void* item);
