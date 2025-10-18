#include <stdio.h>

int main()
{
	int chest = 95;
	char size;

	if (chest <= 90)
	{
		size = 'S';
	}
	else if (chest <= 100)
	{
		size = 'M';
	}
	else
	{
		size = 'L';
	}
}
