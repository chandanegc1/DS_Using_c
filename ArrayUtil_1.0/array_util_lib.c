#include "array_util_lib.h"
#include "stdlib.h"
#include "assert.h"
#include "string.h"


ArrayUtil create(int typeSize, int length){
	ArrayUtil array;
	array.base = calloc(typeSize ,length);
	array.type_size  = typeSize;
	array.length = length;
	return array;
}

// ArrayUtil resize(ArrayUtil util, int length){
// 	ArrayUtil array;
// 	array.base = (ArrayUtil *)realloc(array.base,length);
// 	return array;
// }

void array_util_for_int_type(int *num){
	ArrayUtil numbers = create(sizeof(int) , 5);

	assert(numbers.length == 5);
	assert(numbers.type_size == sizeof(int));

	int *s = (int *)numbers.base;
	s[0] = 92, s[1] = 70, s[2] = 30;

	assert(s[0] == 92);
	assert(s[1] == 70);
	assert(s[2] == 30);
	assert(s[4] == 0);

	(*num)++;
}

void array_util_for_float_type(int *num){
	ArrayUtil numbers = create(sizeof(float) , 10);

	assert(numbers.length == 10);
	assert(numbers.type_size == sizeof(float));

	float *f = (float *)numbers.base;
	f[0] = 0.5, f[1] = 0.50, f[2] = 5.0 ,f[3] = 9.0 ,f[4] = 67.0 ,f[5] = 67.0;

	assert(f[0] == 0.5);
	assert(f[1] == 0.50);
	assert(f[2] == 5.0);
	assert(f[3] == 9.0);
	assert(f[4] == 67.0);

	(*num)++;
}

