#include<stdio.h>
#define N 10
void main()
{
	int A[N],a,t,b;
	printf("��������ʮ���������ÿո�ָ���");
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
	printf("��С����˳�����Ϊ��");
	for (a = 0; a < N; a++)
		printf(" %d", A[a]);
	putchar('\n');
}