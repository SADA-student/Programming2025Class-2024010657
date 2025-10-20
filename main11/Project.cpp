#include <stdio.h>

int main(void)
{
	int n;

	scanf("%d", &n);

	for (unsigned int i = 2; i <= n; i++)
	{
		 for (unsigned int j = 1; j<= n; j++)
		 {
			 printf("%d * %d = %d\n", i, j, i * j);
		 }
		 printf("\n");
	}
	return 0;
}