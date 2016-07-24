#Data Structures Using C 

##There is so many work which can be easy to do if we will have this library.

###ArrayUtil=>
       The ArrayUtil contains base, typeSize ,length.
       base which is a pointer to the array
       typeSize,  which is size of one array element
       length, which is how many elements are there.

       To use the array you just have to cast the base to the pointer of the respective type: like int* a, float* a ,etc        and then a[5] will give you the fifth int or float

##int areEqual(ArrayUtil a, ArrayUtil b)
        will compare a with b and return 1 if both are equal, if not it returns 0 

##ArrayUtil create(int typeSize, int length) 
        will create an array and wrap it with the ArrayUtil and return it.
        the array contents will all be set to zero or its equivalent value.

##ArrayUtil resize(ArrayUtil util, int length) 
        will resize the array and return the modified ArrayUtil. 
        the array contents should be trimmed if new size is less and copied over if the new size is more.

##int findIndex(ArrayUtil util, void* element);
       This function takes two argumens array and element.
       array -It is array of void type.
       element- It is element of array.
       findIndex returns the index of elelement in array.

##void dispose(ArrayUtil util);
       This function takes one void to pointer arguments which should be alocated in heap.
       and does free of alocated memory.

##void *findFirst(ArrayUtil util, MatchFunc* match, void* hint);   
       This function takes three arguments array,match and hint.
       Where array is void to pointer array
       match is function to pointer,signature of the function is,
       int MatchFunc(void* hint, void* item);
       findFirst returns the first element which matches the criteria or null if there is no match.

##void *findLast(ArrayUtil util,MatchFunc *match, void *hint);
       This function is similar to findFirst,
       findLast returns the last element which matches the criteria or null if there is no match.

##int filter(ArrayUtil util, MatchFunc* match, void* hint, void** destination, int maxItems );
       where destination is an array of pointers into which the address of the matching elements are copied onto. maxitems        is the capacity of destination.
       This method returns the number of elements which matches the criteria that have been copied onto the destination.

##void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint);
       This function maps source to destination using the provided convert function.
       where the signature of the ConvertFunc is:
       void ConvertFunc(void* hint, void* sourceItem, void* destinationItem);       
       
##void forEach(ArrayUtil util, OperationFunc* operation, void* hint);
       This function performs operation on all items in the array.
       where the signature of the OperationFunc is:
       void OperationFunc(void* hint, void* item);       

##void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue);
       This function returns the reduced answer.
       where the signature of ReducerFunc is:
       void* ReducerFunc(void* hint, void* previousItem, void* item);
