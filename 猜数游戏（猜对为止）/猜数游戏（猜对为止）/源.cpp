#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int a, b,j;
	int X = 1, Y = 100;
	srand((unsigned)time(NULL));
	a = rand() % (Y - X + 1) + X;
	printf("������Ϸ,�¶�Ϊֹ!\n");
	do
	{
		printf("����1-100��������");
		scanf_s("%d", &b);
		if (a == b)
		{
			printf("��ϲ�¶Դ𰸣���ȷ��Ϊ��%d\n", a);
			j = 1;
		}
		else
			if(b>a)
		{
			printf("ʤ���˱��ҳ��£�����������������(��������)\n");
			j = 0;
		}
			else
				if (b < a)
				{
					printf("ʤ���˱��ҳ��£�����������������(������С)\n");
					j = 0;
				}
	} while (j == 0);

}