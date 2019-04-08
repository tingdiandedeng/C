#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int a, b, j=10;
	int X = 1, Y = 100;
	srand((unsigned)time(NULL));
	a = rand() % (Y - X + 1) + X;
	printf("猜数游戏,十次机会!\n");
	do
	{
		printf("输入1-100任意数：");
		scanf_s("%d", &b);
		j--;
		if (a == b)
		{
			printf("恭喜猜对答案，正确答案为：%d\n", a);
			j = -1;
		}
		else
			if (b>a)
			{
				printf("猜数过大 ");
			}
			else
				if (b < a)
				{
					printf("猜数过小 ");
				}
			if(j!=-1)
		    printf("还剩%d次机会\n", j);
			if(j==0)
			printf("胜败乃兵家常事，少侠请重新来过！正确答案为%d\n", a);
		
	} while (j >0);
	
}