#include<stdio.h>
void insert(int *A, int b, int x);
void insert(int *A, int b, int x)
{
	int *pos;
	int *B = A, n = 1;
	for(B;(B<A+10)&&x>=*B;B++)
	{ }
	pos = B;
	for (B = A + 10; B > pos; B--)
		*B = *(B - 1);
	*B = x;
}
void main()
{
	int A[11], b = 11, x;
	int *a = A;
	*(a + 10) = 0;
	printf("按顺序从大到小依次输入十个整数：");
	for (a; a < A + 10; a++)
		scanf_s("%d", a);
	printf("输入需插入的数：");
	scanf_s("%d", &x);
	insert(A, 11, x);
	printf("插入数x后的数列为：");
	for (a = A; a < A + 11; a++)
		printf(" %d", *a);
	putchar('\n');
}