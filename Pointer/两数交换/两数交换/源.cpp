#include<stdio.h>
void exchange(int*a, int*b);
void exchange(int*a, int*b)
{
	int c;
c = *a;
*a = *b;
*b = c;
}
void main()
{
	int a, b,*A=&a,*B=&b;
	printf("������Ҫ������a��b����ֵ��");
	scanf_s("%d %d", &a, &b);
	exchange(&a, &b);
	printf("a=%d,b=%d\n", a, b);
	printf("a=%d,b=%d\n", A, B);
}