#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int a, b;
	int X = 1, Y = 10;
	srand((unsigned)time(NULL));
	a= rand() % (Y - X + 1) + X;
	printf("������Ϸ,��һ�λ���!\n����1-10��������");
	scanf_s("%d", &b);
	if (a == b)
		printf("��ϲ�¶Դ𰸣���ȷ��Ϊ��%d\n", a);
	else
		printf("ʤ���˱��ҳ��£�������������������ȷ��Ϊ��%d\n", a);

}