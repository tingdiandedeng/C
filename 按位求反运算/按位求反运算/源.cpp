#include<stdio.h>
int invert(int x, int p, int n);
int invert(int x, int p, int n)
{
	int moc = 0, a, b,c;
	c = p + n - 1;
	for (p; p <= c; p++)
	{
		for (b = 1, a = 1; b <= p-1; b++)
			a *= 2;
		moc += a;
	}
	return x^moc;
}
void main()
{
	int A,x, p, n;
	printf("输入整数x,p,n(空格分隔):");
	scanf_s("%d %d %d", &x, &p, &n);
	A=invert(x, p, n);
 	printf("整数%d从第%d位开始的%d个位按位求反的结果是：%d\n", x, p, n, A);
}
