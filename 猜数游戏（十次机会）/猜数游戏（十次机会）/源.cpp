#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
	int a, b, j=10;
	int X = 1, Y = 100;
	srand((unsigned)time(NULL));
	a = rand() % (Y - X + 1) + X;
	printf("������Ϸ,ʮ�λ���!\n");
	do
	{
		printf("����1-100��������");
		scanf_s("%d", &b);
		j--;
		if (a == b)
		{
			printf("��ϲ�¶Դ𰸣���ȷ��Ϊ��%d\n", a);
			j = -1;
		}
		else
			if (b>a)
			{
				printf("�������� ");
			}
			else
				if (b < a)
				{
					printf("������С ");
				}
			if(j!=-1)
		    printf("��ʣ%d�λ���\n", j);
			if(j==0)
			printf("ʤ���˱��ҳ��£�������������������ȷ��Ϊ%d\n", a);
		
	} while (j >0);
	
}