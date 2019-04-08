#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int a, b,j;
	int X = 1, Y = 100;
	srand((unsigned)time(NULL));
	a = rand() % (Y - X + 1) + X;
	printf("猜数游戏,猜对为止!\n");
	do
	{
		printf("输入1-100任意数：");
		scanf_s("%d", &b);
		if (a == b)
		{
			printf("恭喜猜对答案，正确答案为：%d\n", a);
			j = 1;
		}
		else
			if(b>a)
		{
			printf("胜败乃兵家常事，大侠请重新来过！(猜数过大)\n");
			j = 0;
		}
			else
				if (b < a)
				{
					printf("胜败乃兵家常事，大侠请重新来过！(猜数过小)\n");
					j = 0;
				}
	} while (j == 0);

}