#include <stdio.h>
#include "array_util_lib.h"
#include "assert.h"



int main(void){
	int num_of_test = 0;

	array_util_for_int_type(&num_of_test);
	array_util_for_float_type(&num_of_test);

	printf("%d passed\n",num_of_test);
	return 0;
}