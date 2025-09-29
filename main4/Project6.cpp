#include <stdio.h>

#define PI_VALUE 3.14159265358979323846

int main(void)
{
	int version = 1;

	unsigned int year = 2025;

	const char* title = "C \"printf\" demo";

	int widt_demo_num = 123;

	char sample_char = 'A';

	printf("=== Constants & Formats ===\n");

	printf("Course: C Programming (v%d, %u))\n", version, year);

	printf("Title : %s\n", title);

	printf("PI default \t : %f\n", PI_VALUE);
	printf("PI 2 digits \t : %.2f\n", PI_VALUE);

	printf("Width demo \t : [%8d]\n", widt_demo_num);

	printf("Char sample \t : %c\n", sample_char);
	printf("BacksLach \t : \\\n");
	return 0;
}
