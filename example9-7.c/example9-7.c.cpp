#include <stdio.h>

void swap_pointer(int* pnA, int* pnB);
void swap_normal(int nA, int nB);

int main(void)
{
	int nA = 0, nB = 0;
	nA = 10;
	nB = 20;

	int *pnA, *pnB;
	pnA = &nA;
	pnB = &nB;

	printf("before swap : (nA,nB)=(%d,%d)\n", nA, nB);

	swap_pointer(pnA, pnB);
	//swap_normal(int pnA, int pnB);


	printf("after swap:(nA,nB)=(%d,%d)\n", nA, nB);
	
}