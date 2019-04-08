#include<stdio.h>
int factor(int a);
int factor(int a)
{
	if (a % 2 != 0 && a % 3 != 0 && a % 5 != 0 && a % 7 != 0&&a!=1)
		return a;
	if (a % 2 == 0)        /*返回该数的因子*/
		return 2;
	if (a % 3 == 0)
		return 3;
	if (a % 5 == 0)
		return 5;
	if (a % 7 == 0)
		return 7;
	if (a == 1)
		return 0;
}
void main()
{
	int sum=0,a,b=1;
	printf("输入所求的正整数：");
	scanf_s("%d", &a);
	if (a == 2 || a == 3 || a == 5 || a == 7)   /*判断该整数是否是质数，若是质数令b=-1*/
		b=-1;
	if (a % 2 != 0 && a % 3 != 0 && a % 5 != 0 && a % 7 != 0)    
		b= -1;
	if (a == 1)
	{
		b = -1;
		printf("1不为质数也不为合数");
	}
	if (b != -1)
		printf("该整数因子有：");
	do
	{
		a = a / b;
		if(b!=-1)
		b = factor(a);
		sum += b;
		if (b > 0)
			printf(" %d", b);
	} while (b != 0 && b != -1);
	if (b == -1)
		printf("该数为质数。\n");
	else
	    printf("该整数所有因子和为：%d\n", sum);
}