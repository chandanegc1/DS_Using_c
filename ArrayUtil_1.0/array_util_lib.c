#include "array_util_lib.h"
#include "stdlib.h"
#include "assert.h"


ArrayUtil create(int typeSize, int length){
	ArrayUtil array;
	array.base = calloc(typeSize ,length);
	array.type_size  = typeSize;
	array.length = length;
	return array;
}

ArrayUtil resize(ArrayUtil util, int length){
	ArrayUtil array;
	array.base = (ArrayUtil *)realloc(array.base,length);
	return array;
}

