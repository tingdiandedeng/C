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
	printf("��������x,p,n(�ո�ָ�):");
	scanf_s("%d %d %d", &x, &p, &n);
	A=invert(x, p, n);
 	printf("����%d�ӵ�%dλ��ʼ��%d��λ��λ�󷴵Ľ���ǣ�%d\n", x, p, n, A);
}
