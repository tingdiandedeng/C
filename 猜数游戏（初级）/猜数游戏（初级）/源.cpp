#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int n,i,j;
	int X=1, Y=10;             /*随机数为X-Y之间的数*/
	srand((unsigned)time(NULL));
	printf("猜数游戏（初级）开始！(输入0结束游戏)\n");
	do
	{
		n = rand() % (Y - X + 1) + X;
		printf("输入1-10任意数：");
		scanf_s("%d", &i);
		if (i == 0)
			j = 1;
		else
		   if (i == n)
		{
			printf("恭喜猜对答案，正确答案为：%d\n", n);
			j = 0;
		}
		else
			if(i!=n)
		{
			printf("胜败乃兵家常事，大侠请重新来过！正确答案为：%d\n", n);
			j = 0;
		}
	} while (j == 0);
	
}