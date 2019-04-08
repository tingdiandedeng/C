#include<stdio.h>
void main()
{
	float c = 0, F = 0;
	printf("输入华氏温度：");
	scanf_s("%f", &F);
	c = (5.0 / 9)*(F - 32);
	printf("摄氏温度c=%.2lf", c);
}