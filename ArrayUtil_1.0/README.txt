
-------ArrayUtil_1.0-----------------------------
Implement a ArrayUtil DataType and methods around it.

The ArrayUtil contains 
base, which is a pointer to the array
typeSize,  which is size of one array element
length, which is how many elements are there.

To use the array you just have to cast the base to the pointer of the respective type: like int* a, float* a ,etc and then a[5] will give you the fifth int or float

int areEqual(ArrayUtil a, ArrayUtil b)
will compare a with b and return 1 if both are equal, if not it returns 0 

ArrayUtil create(int typeSize, int length) 
will create an array and wrap it with the ArrayUtil and return it.
the array contents will all be set to zero or its equivalent value.

ArrayUtil resize(ArrayUtil util, int length) 
will resize the array and return the modified ArrayUtil. 
the array contents should be trimmed if new size is less and copied over if the new size is more.

-------ArrayUtil_1.1-----------------------------

Implement a findIndex method.

int findIndex(ArrayUtil util, void* element)
will return -1 if not found and the array index of the element if found

for example to search 5 in [4,2,1,5,6,0]
int x = 5;
findIndex(util, &x) will return 3 
---------------------1.2-------------------------
Implement a method dispose to free the memory allocated for the Array inside array util

void dispose(ArrayUtil util)

--------------------------1.3----------------------------------
Implement a findFirst method to find the first element matching the criteria.

void* findFirst(ArrayUtil util, MatchFunc* match, void* hint);
which returns the first element which matches the criteria or null if there is no match.

where the signature of the MatchFunc is:

int MatchFunc(void* hint, void* item);
which will return 0 in case of no match and 1 in case of match.
As C language does not have closure, we have some hint that can be passed, which will help in customizing the match.

for example: 
int isEven(void* hint, void* item)
can be used to find if a given number is even. Here the hint is not needed.

int isDivisible(void* hint, void* item)
can be used to find if a given number is divisible by the number mentioned in the hint.


---------------1.4------------------------------

Implement a findLast method similar to findFirst

----------------1.5-----------------------------

Implement a count method to count the number of elements matching the criteria.

int count(ArrayUtil util, MatchFunc* match, void* hint);

----------------------------1.6------------------------

