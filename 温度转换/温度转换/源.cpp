#include<stdio.h>
void main()
{
	float c = 0, F = 0;
	printf("���뻪���¶ȣ�");
	scanf_s("%f", &F);
	c = (5.0 / 9)*(F - 32);
	printf("�����¶�c=%.2lf", c);
}