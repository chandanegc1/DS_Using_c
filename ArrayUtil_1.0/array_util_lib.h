typedef struct array_util {
	void *base;
	int type_size;
	int length;
} ArrayUtil;

ArrayUtil create(int typeSize, int length);
ArrayUtil resize(ArrayUtil , int length);
int areEqual(ArrayUtil a, ArrayUtil b);