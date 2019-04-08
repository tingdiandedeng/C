#include<stdio.h>
void main()
{
	int A[11] = { 5,8,9,11,15,17,18,19,22,26 };
	int a,b;
	printf("输入向数组5,8,9,11,15,17,18,19,22,26中插入的任意数：");
	scanf_s("%d", &A[10]);
	for (a = 9; a >= 0; a--)
	{
		if (A[a] > A[a + 1])
		{
			b = A[a];
			A[a] = A[a + 1];
			A[a + 1] = b;
		}
		else
			break;
	}
		for (a = 0; a <= 10; a++)
			printf(" %d", A[a]);
		putchar('\n');
}