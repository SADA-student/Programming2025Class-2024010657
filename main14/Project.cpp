#include <stdio.h>

int main(void)
{
	int first_number, second_number;
	int sum, sub, mul, inv;

	int first_number = 0;
	int second_number = 0;
	
	scanf("%d", &first_number);
	scanf("%d", &second_number);

	sum = first_number + second_number;
	sub = first_number - second_number;
	mul = first_number * second_number;
	inv = first_number / second_number;

	printf("첫번째 값 :%d, 두번째 값 :%d\n", first_number, second_number);
}