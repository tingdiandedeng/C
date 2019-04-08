#include<stdio.h>
int age(int b);
int age(int b)
{
	if (b == 1)
		return 10;
	else
		return age(b - 1) + 2;
}
void main()
{
	int a;
	a = age(5);
	printf("第五个人年龄为%d岁", a);
	putchar('\n');
}
