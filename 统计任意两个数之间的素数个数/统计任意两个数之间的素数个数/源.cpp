#include<stdio.h>
int PrimeNumber(int a)    /*�������������򷵻ظ��������������������򷵻�0*/
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
	printf("����������������0������(��С��󣬿ո�ָ�)��");
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
		printf("����������������");
	else
		printf("����������������Ϊ��%d", sum);
	putchar('\n');
}