#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "assert.h"
#include "array_util_lib.h"

void array_util_for_char_type(int *num){
	printf("--------\n-->array_util_for_int_type \n");
	ArrayUtil numbers = create(sizeof(char) , 5);

	assert(numbers.length == 5);
	assert(numbers.type_size == sizeof(char));

	char *c = (char *)numbers.base;
	c[0] = 92, c[1] = 70, c[2] = 30;

	assert(c[0] == 92);
	assert(c[1] == 70);
	assert(c[2] == 30);
	assert(c[4] == 0);

	(*num)++;
}

void array_util_for_int_type(int *num){
	printf("--------\n-->array_util_for_int_type \n");
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
	printf("--------\n-->array_util_for_float_type \n");
	ArrayUtil numbers = create(sizeof(float) , 10);

	assert(numbers.length == 10);
	assert(numbers.type_size == sizeof(float));

	float *f = (float *)numbers.base;
	f[0] = 0.5, f[1] = 0.50, f[2] = 5.0 ,f[3] = 9.0 ,f[4] = 67.0 ,f[5] = 10.50;

	assert(f[0] == 0.5);
	assert(f[1] == 0.50);
	assert(f[2] == 5.0);
	assert(f[3] == 9.0);
	assert(f[4] == 67.0);
	assert(f[5] == 10.50);

	(*num)++;
}

void array_util_for_double_type(int *num){
	printf("--------\n-->array_util_for_double_type \n");
	ArrayUtil numbers = create(sizeof(double) , 10);

	assert(numbers.length == 10);
	assert(numbers.type_size == sizeof(double));

	double *d = (double *)numbers.base;
	d[0] = 0.5, d[1] = 0.50, d[2] = 5.0 ,d[3] = 9.0 ,d[4] = 67.6 ,d[5] = 10.10;

	assert(d[0] == 0.5);
	assert(d[1] == 0.50);
	assert(d[2] == 5.0);
	assert(d[3] == 9.0);
	assert(d[4] == 67.6);
	assert(d[5] == 10.10);

	(*num)++;
}


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
