#include <stdio.h>


int main(void)
{
	int age = 21;
	unsigned int count = 3000000000;
	float score = 93.5f;
	const char* title = "Basic Constants";
	const char* name = "Jeonghun";
	char initial = name[0];
	printf("=== %s ===\n Name \t : %s\n Initial : %c\n Age : %d\n Score \t : %.6f\n Count \t : %u\n", title, name, initial, age, score, count);
	return 0;
}