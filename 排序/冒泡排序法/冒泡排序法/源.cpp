#include<stdio.h>
#define N 10
void main()
{
	int A[N],a,t,b;
	printf("输入任意十个整数，用空格分隔：");
	for (a = 0; a < N; a++)
		scanf_s("%d", &A[a]);
	getchar();
	for (a = 0; a < N; a++)
	{
		for (b = a; b > 0; b--)
		{
			if (A[b] < A[b-1])
			{
				t = A[b];
				A[b] = A[b - 1];
				A[b - 1] = t;
			}
		}
	}
	printf("从小到大顺序输出为：");
	for (a = 0; a < N; a++)
		printf(" %d", A[a]);
	putchar('\n');
}