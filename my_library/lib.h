int increment (int);
int sum(int,int);
int is_even(int);
typedef int (inc)(int);
typedef int (sum_of_numbers)(int,int);
void map(void score[] ,void result[],int length,inc i);
int filter(int score[] ,int result[],int length,inc i);
int reduce(int *score ,int length,sum_of_numbers su);

