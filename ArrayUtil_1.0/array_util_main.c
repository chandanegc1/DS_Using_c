#include <stdio.h>
#include "array_util_lib.h"
#include "assert.h"
#include <stdlib.h>




int main(void){
	int num_of_test = 0;
	ArrayUtil e;
	e = create(1,4);
	array_util_for_char_type(&num_of_test);
	array_util_for_int_type(&num_of_test);
	array_util_for_float_type(&num_of_test);
	array_util_for_double_type(&num_of_test);
	// printf("%lu\n",sizeof(e.type_size));
	printf("%d passed\n",num_of_test);
	return 0;
}