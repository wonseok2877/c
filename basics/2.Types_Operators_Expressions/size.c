#include <stdio.h>
#include <float.h>
#include <limits.h>

void printRanges() {
	printf("Integer range:\t%d\t%d\n", INT_MIN, INT_MAX);
	printf("Long range:\t%ld\t%ld\n", LONG_MIN, LONG_MAX);
	printf("Float range:\t%e\t%e\n", FLT_MIN, FLT_MAX);
	printf("Double range:\t%e\t%e\n", DBL_MIN, DBL_MAX);
	printf("Long double range:\t%e\t%e\n", LDBL_MIN, LDBL_MAX);
	printf("Float-Double epsilon:\t%e\t%e\n", FLT_EPSILON, DBL_EPSILON);

	printf("void\tchar\tshort\tint\tlong\tfloat\tdouble\n");
	int wow = 21474836470000;
	printf("%i", wow);
}


int main(){
int c;
int size_short = sizeof(short int);
int size_int = sizeof(int);

unsigned char a = 'a';

printf("%i %c \n", a, a);

printf("storage size for int: %i\n", size_int);
printf("storage size for short int: %i\n", size_short);
printf("storage size for long int: %li\n", sizeof(long));
printf("storage size for char: %lu\n", sizeof(char));
printf("storage size for void: %lu\n", sizeof(void));
printf("storage size for float: %lu\n", sizeof(float));
printf("storage size for double: %lu\n", sizeof(double));
printf("storage size for long double: %lu\n", sizeof(long double));

printf("minimum float value: %E\n", FLT_MIN);
printf("maximum float value: %E\n", FLT_MAX);

return 0;
}
