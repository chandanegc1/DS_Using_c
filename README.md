#Data Structures Using C 

##Linked_list:

  It is a data type that holds the first and last element of a linked list(head and tail).
  It may also contain the number of elements in that list.
  we defined it as follows.
  typedef struct element{
	  void *value;
	  struct element *next;
  } Element;
  typedef struct linkedList{
	  Element *head,*tail;
	  int length;
  } Linked_list;

##Linked_list createList(void);
  This function create an empty LinkedList structure.

##int add_to_list(LinkedList *,void *);
  It given a reference to some data, add it to list. For now, add it to the end of the list. 

##void *get_first_element(LinkedList list);
  This function returns the first element in the list. 

##void *get_last_element(LinkedList list);
  This function returns the first element in the list. 

##void forEach(LinkedList, ElementProcessor e)
  where ElementProessor is a function pointer type with the following signature: 

##void (*ElementProcessor)(void *)
  Write a generic traverse function that can go through a list and process each element.
  Example: 
  void increment(void *){
  // code
  }
  forEach(list,&increment);

##void * getElementAt(LinkedList, int )
  Given an index as an integer, return the data reference contained at that position in the list.
  For ex: getElementAt(2) should return the element at index 2.
  This is basically like an array's [] operator. Return NULL if index is invalid.

##int indexOf(LinkedList, void *)
  Given an element, find the first index at which this element occurs in a list. Return -1 if not found.

##void * deleteElementAt(LinkedList *, int)
  Given an index, delete the element at that list. Return the data referenced by the node at that position. 

##int asArray(LinkedList, void **, int maxElements)
  Given a linked list and a reference to an array, 
  this function will populate the array with all the elements of a list(or maxElements,
  whichever is smaller) and finally return the number of elements added to the array.
  Each element of the array will contain a reference to each piece of data in the linked list.

##LinkedList  filter(LinkedList, MatchFunc )
    where the signature of the MatchFunc is:
    int MatchFunc(void* hint, void* item);
    Given a linked list and a function pointer,
    this function will filter the original list and return a new LinkedList that consists only of references to data that satisfy the filtering criteria.
    This is basically the same as ArrayUtil's filter, except, we return a LinkedList instead of an ArrayUtil.
  
##LinkedList reverse(LinkedList)
  This function will take a LinkedList as an argument and return a LinkedList
  with the order of the elements of the source LinkedList reversed. Do not modify the existing LinkedList.

##LinkedList map(LinkedList, ConvertFunc, void * )
  where the signature of the ConvertFunc is:
  void ConvertFunc(void* hint, void* sourceItem, void* destinationItem);

##LinkedList reduce(LinkedList, Reducer, void *hint, void *initialValue);
  where the signature of Reducer is:
  void* Reducer(void* hint, void* previousItem, void* item);

    
