#include<stdio.h>
void main()
{
	int A[10][10];
	int k = 1, a = 0, b = 0;
	for (b = 0; b <10; b++)
		for (a = 0; a <10; a++, k++)
			A[a][b] = k;
	for (a = 0; a < 10; a++)
	{
		for (b = 0; b < 10; b++)
			printf("%d\t", A[a][b]);
		printf("\n");
	}
}