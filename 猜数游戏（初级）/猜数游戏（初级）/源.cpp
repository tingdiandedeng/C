#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int n,i,j;
	int X=1, Y=10;             /*�����ΪX-Y֮�����*/
	srand((unsigned)time(NULL));
	printf("������Ϸ����������ʼ��(����0������Ϸ)\n");
	do
	{
		n = rand() % (Y - X + 1) + X;
		printf("����1-10��������");
		scanf_s("%d", &i);
		if (i == 0)
			j = 1;
		else
		   if (i == n)
		{
			printf("��ϲ�¶Դ𰸣���ȷ��Ϊ��%d\n", n);
			j = 0;
		}
		else
			if(i!=n)
		{
			printf("ʤ���˱��ҳ��£�������������������ȷ��Ϊ��%d\n", n);
			j = 0;
		}
	} while (j == 0);
	
}