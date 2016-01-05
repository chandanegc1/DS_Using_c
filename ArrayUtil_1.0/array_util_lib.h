typedef struct array_util {
	void *base;
	int type_size;
	int length;
} ArrayUtil;

ArrayUtil create(int typeSize, int length);
void array_util_for_int_type(int *num);
void array_util_for_float_type(int *num);
