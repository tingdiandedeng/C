#include<stdio.h>   /*����˵��*/
#include<math.h>
#define PI 3.14
void main()
{
	float r, h, C, S1, S2, S3, S4, V1, V2, V3, l;  /*��������*/
	printf("����Բ�뾶����r,h:");  /*��ʾ��������*/
	scanf_s("%f,%f", &r, &h);    /*��������*/
	C = 2 * PI*r;       /*���ݼ���*/
	S1 = PI*r*r;
	S2 = 4 * PI*r*r;
	V1 = 4 * (PI*r*r*r) / 3;
	V2 = S1*h;
	S3 = 2 * S1 + C*h;
	V3 = (S1*h) / 3;
	l = sqrt(r*r + h*h);
	S4 = S1 + PI*r*l;
	printf("Բ�ܳ�C=%.2f\nԲ���S1=%.2f\n������S2=%.2f\n�����V1=%.2f\nԲ�����V2=%.2f\n", C, S1, S2, V1, V2);  /*�������*/
	printf("Բ�������S3=%.2f\nԲ׶���V3=%.2f\nԲ׶�����S4=%.2f\n", S3, V3, S4);

}