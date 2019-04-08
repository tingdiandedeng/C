#include<stdio.h>
void insert(int A[], int b, int x);
void insert(int A[], int b, int x)
{
	int a,pos;
	for(a=0;a<10&&x>=A[a];a++)
	{ }
	pos = a;
	for (a = b - 1; a >= pos; a--)
		A[a + 1] = A[a];
	A[pos] = x;
}
void main()
{
	int A[11], a, x;
	printf("从大到小依次输入十个数：");
	for (a = 0; a < 10; a++)
		scanf_s("%d", &A[a]);
	printf("输入被插入的数：");
	scanf_s("%d", &x);
	insert(A, 11, x);
	printf("插入x的数组为：");
	for (a = 0; a < 11; a++)
		printf(" %d", A[a]);
	putchar('\n');
}