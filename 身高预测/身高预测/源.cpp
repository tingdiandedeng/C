#include<stdio.h>
void main()
{
	int sex, sports, diet;
	float f, m, a, b, h;
	printf("�����Ա�1����Ů�ԣ�2�������ԡ��Ƿ��Ȱ��˶�����ʳ�Ƿ񽡿���1��ʾ�ǣ�2��ʾ�񣩣�");
	scanf_s("%d,%d,%d", &sex, &sports, &diet);
	printf("���븸����ߣ�ĸ�����(cm)��");
	scanf_s("%f,%f", &f, &m);
	sports == 1 ? a = 1.02 : a = 1;
	diet == 1 ? b = 1.015 : b = 1;
	if (sex = 1)
		h = (f*0.923 + m)*0.5*a*b;
	else
		h = (f + m)*a*b*0.54;
	printf("Ԥ�����:%.2f(cm)", h);
}
