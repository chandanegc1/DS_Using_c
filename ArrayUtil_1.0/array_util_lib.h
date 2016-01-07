typedef struct array_util {
	void *base;
	int type_size;
	int length;
} ArrayUtil;

ArrayUtil create(int typeSize, int length);
ArrayUtil resize(ArrayUtil , int length);
int areEqual(ArrayUtil a, ArrayUtil b);

int findIndex(ArrayUtil util, void* element);

void dispose(ArrayUtil util);


typedef int (MatchFunc)(void * , void *);
void* findFirst(ArrayUtil util, MatchFunc* match, void* hint);
void* findLast(ArrayUtil util, MatchFunc* match, void* hint);

int count(ArrayUtil util, MatchFunc* match, void* hint);

