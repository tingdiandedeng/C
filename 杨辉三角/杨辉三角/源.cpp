#include<stdio.h>
void main()
{
	int	A[10][10] = { 0 };
	int m, n;
	A[0][0] = 1; A[1][0] = 1; A[1][1] = 1;
	for (m = 2; m<10; m++)
	{
		A[m][0] = 1;
		A[m][m] = 1;
		for (n = 1; n<m; n++)
			A[m][n] = A[m - 1][n - 1] + A[m - 1][n];
	}
	printf("输出杨辉三角前十行：\n");
	for (m = 0; m<10; m++)
	{
		for (n = 0; n <= m; n++)
			printf(" %d", A[m][n]);
		putchar('\n');
	}
}