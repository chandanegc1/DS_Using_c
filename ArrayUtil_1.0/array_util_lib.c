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

ArrayUtil resize(ArrayUtil util, int length){
	util.base = realloc(util.base,length);
	util.length = length;
	return util;
}
int areEqual(ArrayUtil a, ArrayUtil b){
	if(a.length!=b.length){return 0;}
	return memcmp(a.base,b.base,a.length*a.type_size) == 0;
}

//------------1.1---------------

int findIndex(ArrayUtil util, void* element){
	for(int i=0;i<util.length;i++){
		if(memcmp(util.base,element,util.type_size)==0){
			return i;			
		}
		util.base += util.type_size;
	}
	return -1;
}
