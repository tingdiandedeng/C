#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int a, b;
	int X = 1, Y = 10;
	srand((unsigned)time(NULL));
	a= rand() % (Y - X + 1) + X;
	printf("猜数游戏,仅一次机会!\n输入1-10任意数：");
	scanf_s("%d", &b);
	if (a == b)
		printf("恭喜猜对答案，正确答案为：%d\n", a);
	else
		printf("胜败乃兵家常事，大侠请重新来过！正确答案为：%d\n", a);

}