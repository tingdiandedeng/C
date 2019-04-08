#include<stdio.h>
void main()
{
	int sex, sports, diet;
	float f, m, a, b, h;
	printf("输入性别1代表女性，2代表男性。是否热爱运动，饮食是否健康（1表示是，2表示否）：");
	scanf_s("%d,%d,%d", &sex, &sports, &diet);
	printf("输入父亲身高，母亲身高(cm)：");
	scanf_s("%f,%f", &f, &m);
	sports == 1 ? a = 1.02 : a = 1;
	diet == 1 ? b = 1.015 : b = 1;
	if (sex = 1)
		h = (f*0.923 + m)*0.5*a*b;
	else
		h = (f + m)*a*b*0.54;
	printf("预测身高:%.2f(cm)", h);
}
