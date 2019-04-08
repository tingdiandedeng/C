#include<stdio.h>   /*函数说明*/
#include<math.h>
#define PI 3.14
void main()
{
	float r, h, C, S1, S2, S3, S4, V1, V2, V3, l;  /*变量定义*/
	printf("输入圆半径、高r,h:");  /*提示输入数据*/
	scanf_s("%f,%f", &r, &h);    /*数据输入*/
	C = 2 * PI*r;       /*数据计算*/
	S1 = PI*r*r;
	S2 = 4 * PI*r*r;
	V1 = 4 * (PI*r*r*r) / 3;
	V2 = S1*h;
	S3 = 2 * S1 + C*h;
	V3 = (S1*h) / 3;
	l = sqrt(r*r + h*h);
	S4 = S1 + PI*r*l;
	printf("圆周长C=%.2f\n圆面积S1=%.2f\n球表面积S2=%.2f\n球体积V1=%.2f\n圆柱体积V2=%.2f\n", C, S1, S2, V1, V2);  /*数据输出*/
	printf("圆柱表面积S3=%.2f\n圆锥体积V3=%.2f\n圆锥表面积S4=%.2f\n", S3, V3, S4);

}