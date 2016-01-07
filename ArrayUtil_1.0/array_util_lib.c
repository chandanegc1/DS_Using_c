#include "array_util_lib.h"
#include "stdlib.h"
#include "assert.h"
#include "string.h"
#include <stdio.h>


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
//----------------1.2----------------

void dispose(ArrayUtil util){
	free(util.base);
}


//----------------1.3---------------


void *findFirst(ArrayUtil util, MatchFunc* match, void* hint){
	for(int i= 0;i<util.length-1;i++){
		if(hint !=0 && match(0,util.base)==1)
			return &util.base[i];
		if(match(hint,util.base)==1)
			return &util.base[i];
	}
	return NULL;
}
// void* get(ArrayList *list, int index){
// 	if (index < 0 || index >= list->length) return NULL;
// 	return list->base[index];
// };

//---------------1.4------------------------------

void *findLast(ArrayUtil util, MatchFunc* match, void* hint){
	void *lastValue = (void *)NULL;
	//void *array = util.base;
	for (int i = 0; i < util.length; ++i){
		if(match(hint,util.base) == 1){
			lastValue = util.base;
		}
		util.base += util.type_size;
	}
	return lastValue;
}	
// int count(ArrayUtil util, MatchFunc* match, void* hint){
	

// }
