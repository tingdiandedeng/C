#include<stdio.h>
int PrimeNumber(int a)    /*若该数是素数则返回该数，若该数不是素数则返回0*/
{
	int i;
	if (a == 2)
		return a;
	if (a == 1)
		return 0;
	for (i = 2; i < a; i++)
		if (a%i == 0)
			return 0;
	 return a;
}
void main()
{
	int a, b,c,number,sum=0;
	printf("输入任意两个大于0的整数(先小后大，空格分隔)：");
	scanf_s("%d %d", &a, &b);
	getchar();
	for(a;a<=b;a++)
	{
		c = PrimeNumber(a);
		if (c != 0)
		{
			number = c;
			sum++;
			printf(" %d", number);
		}
		if (sum == 20)
			putchar('\n');
	}
	putchar('\n');
	if (sum == 0)
		printf("该两数间无素数。");
	else
		printf("该两数间素数个数为：%d", sum);
	putchar('\n');
}