#include<stdio.h>
#define N 1/*�궨�壬����ͳ�ƽ�ʦ����ΪN+1��*/
typedef struct teach/*����ṹ�壬�洢ÿ����ʦ�����ݣ�������typedef���ṹ���ΪTEACH��������*/
{
	int id;
	char name[30] = { 0 };
	int sex = 0;
	char unit[50] = { 0 };
	char address[50] = { 0 };
	char tell[11];
	float a;
	float b;
	float c;
	float d;
	float e;
	float f;
	float g;
	float h;
	float i;
	float j = 0;
	float k = 0;
	float l = 0;
}TEACH;
void count(TEACH teacher[], int j);/*����count�������ڼ���ϼƿۿʵ�����ʣ�Ӧ�����ʡ��β�Ϊ�ṹ��������������������ʦ��Ϣ����j�����������������Ӧ��ʦ����Ϣ�С�*/
void count(TEACH teacher[], int j)
{
	int i;
	for (i = 0; i <= (N + j); i++)
	{
		teacher[i].l = teacher[i].a + teacher[i].b + teacher[i].c;
		teacher[i].j = teacher[i].d + teacher[i].e + teacher[i].f + teacher[i].g + teacher[i].h + teacher[i].i;
		teacher[i].k = teacher[i].l - teacher[i].j;
	}
	return;
}
void find(TEACH teacher[], int f, int j);/*����find���������ڲ���ĳ��ʦ����ʦ��������Ϣ������ʾ���β�Ϊ����������������ʦ�Ľ�ʦ��f��������ʦ��j��*/
void find(TEACH teacher[], int f, int j)
{
	int i;
	for (i = 0; i <= (N + j); i++)
	{
		if (f == teacher[i].id)
		{
			printf("**���ҽ������**:\n");
			printf("��ʦ�ţ�%d ,������%s ,�Ա�%d ,��λ���ƣ�%s ,��ͥסַ��%s ,��ϵ�绰��%s ,��������=%f ,����=%f ,�����=%f ,\
�绰��=%f ,ˮ���=%f ,����=%f ,����˰=%f ,������=%f ,������=%f ,�ϼƿۿ�=%f ,Ӧ������=%f ,ʵ������=%f\n", teacher[i].id, \
teacher[i].name, teacher[i].sex, teacher[i].unit, teacher[i].address, teacher[i].tell, \
teacher[i].a, teacher[i].b, teacher[i].c, teacher[i].d, teacher[i].e, teacher[i].f, teacher[i].g, teacher[i].h, teacher[i].i, teacher[i].j, teacher[i].l, teacher[i].k);
			return;
		}
	}
	printf("**���޴��ˣ�**\n");
	return;
}
void insret(TEACH teacher[], int j);/*����insert���������ڲ�����һ����ʦ����Ϣ���β�Ϊ���������Լ�������ʦ����j��*/
void insret(TEACH teacher[], int j)
{
	int i = N + j;
	printf("�������ʦ��:");
	scanf("%d", &teacher[i].id);
	printf("����������:");
	scanf("%s", teacher[i].name);
	printf("�������Ա�(0����Ů��1������):");
	scanf("%d", &teacher[i].sex);
	printf("�����뵥λ���ƣ�");
	scanf("%s", teacher[i].unit);
	printf("�������ͥסַ��");
	scanf("%s", teacher[i].address);
	printf("��������ϵ�绰��");
	scanf("%s", teacher[i].tell);
	printf("������������ʣ���������������绰�ѣ�ˮ��ѣ����⣬����˰�������ѣ�������(�����Ķ��ŷָ�):\n");
	scanf("%f��%f��%f��%f��%f��%f��%f��%f��%f", &teacher[i].a, &teacher[i].b, &teacher[i].c, &teacher[i].d, &teacher[i].e, &teacher[i].f, &teacher[i].g, &teacher[i].h, &teacher[i].i);
	printf("**����ɹ���**\n");
	count(teacher, j);
}
void dele(TEACH teacher[], int d, int j);/*����dele����������ɾ����ʦ��Ϣ���β�dΪ��ɾ����ʦ�Ľ�ʦ�ţ�jΪ��������ʦ��������*/
void dele(TEACH teacher[], int d, int j)
{
	int i;
	for (i = 0; i <= (N + j); i++)
	{
		if (d == teacher[i].id)
		{
			teacher[i].id = 0;/*��ɾ����ʦ����Ϣ��δ��ȫ���㣬���ǽ�����ʦ�����㡣*/
			printf("**ɾ���ɹ���**\n");
			return;
		}
	}
	printf("**���޴��ˣ�**\n");
	return;
}
void revise(TEACH teacher[], int r, int j);
void revise(TEACH teacher[], int r, int j)/*����revise���������������޸�ĳһ��ʦ��Ϣ���Խ�ʦ��Ϣ����¼�롣�β�Ϊ��������rΪ���޸���ʦ�Ľ�ʦ�ţ�jΪ������ʦ��������*/
{
	int i;
	for (i = 0; i <= (N + j); i++)
	{
		if (r == teacher[i].id)
		{
			printf("**��Ҫ�޸ĵ���Ϣ���£�**\n");
			printf("��ʦ�ţ�%d ,������%s ,�Ա�%d ,��λ���ƣ�%s ,��ͥסַ��%s ,��ϵ�绰��%s ,��������=%f ,����=%f ,�����=%f ,\
�绰��=%f ,ˮ���=%f ,����=%f ,����˰=%f ,������=%f ,������=%f ,�ϼƿۿ�=%f ,Ӧ������=%f ,ʵ������=%f\n", teacher[i].id, \
teacher[i].name, teacher[i].sex, teacher[i].unit, teacher[i].address, teacher[i].tell, \
teacher[i].a, teacher[i].b, teacher[i].c, teacher[i].d, teacher[i].e, teacher[i].f, teacher[i].g, teacher[i].h, teacher[i].i, teacher[i].j, teacher[i].l, teacher[i].k);
			printf("**�����޸ĺ����Ϣ��**\n");
			printf("����������:");
			scanf("%s", teacher[i].name);
			printf("�������Ա�(0����Ů��1������):");
			scanf("%d", &teacher[i].sex);
			printf("�����뵥λ���ƣ�");
			scanf("%s", teacher[i].unit);
			printf("�������ͥסַ��");
			scanf("%s", teacher[i].address);
			printf("��������ϵ�绰��");
			scanf("%s", teacher[i].tell);
			printf("������������ʣ���������������绰�ѣ�ˮ��ѣ����⣬����˰�������ѣ�������(��Ӣ�Ķ��ŷָ�):\n");
			scanf("%f��%f��%f��%f��%f��%f��%f��%f��%f", &teacher[i].a, &teacher[i].b, &teacher[i].c, &teacher[i].d, &teacher[i].e, &teacher[i].f, &teacher[i].g, &teacher[i].h, &teacher[i].i);
			printf("**�޸ĳɹ���**\n");
			count(teacher, j);
			return;
		}
	}
	printf("**���޴��ˣ�**\n");
	return;
}
void main()
{

	TEACH teacher[50];/*����ṹ�����飬���ڴ洢���н�ʦ��Ϣ��*/
	int i, f, operation = -1, j = 0, d, r, a = 0;
	printf("                                 ****************************************************\n");
	printf("                                 **                                                **\n");
	printf("                                 **    ��ӭʹ��������ҵ��ѧ��ʦ���ʹ���ϵͳ2.0     **\n");
	printf("                                 **                                                **\n");
	printf("                                 ****************************************************\n");
	for (i = 0; i <= N; i++)/*ѭ����䣬��ÿ����ʦ��������Ϣ���д洢��*/
	{
		printf("�������%d���˵Ľ�ʦ��:", i + 1);
		scanf("%d", &teacher[i].id);
		printf("����������:");
		scanf("%s", teacher[i].name);
		printf("�������Ա�(0����Ů��1������):");
		scanf("%d", &teacher[i].sex);
		printf("�����뵥λ���ƣ�");
		scanf("%s", teacher[i].unit);
		printf("�������ͥסַ��");
		scanf("%s", teacher[i].address);
		printf("��������ϵ�绰��");
		scanf("%s", teacher[i].tell);
		printf("������������ʣ���������������绰�ѣ�ˮ��ѣ����⣬����˰�������ѣ�������(�����Ķ��ŷָ�):\n");
		scanf("%f��%f��%f��%f��%f��%f��%f��%f��%f", &teacher[i].a, &teacher[i].b, &teacher[i].c, &teacher[i].d, &teacher[i].e, &teacher[i].f, &teacher[i].g, &teacher[i].h, &teacher[i].i);
		putchar('\n');
		count(teacher, j);
	}
	printf("**����������ɣ�**\n*\n*\n*\n*\n");
	for (i = 0;; i++)/*ѭ����䣬����ĳһ������������֣���if�������жϣ��жϳɹ�����ö�Ӧ������������0���ѭ��������*/
	{
		printf("     ***************************************************************************************************************\n");
		printf("     **������������еĲ������˳���0�������ң�1���������½�ʦ��Ϣ��2����ɾ����3�����޸ģ�4��,���������Ϣ��5������**\n");
		printf("     ***************************************************************************************************************\n");
		scanf("%d", &operation);
		if (operation == 0)
		{
			printf("                                    *********************************\n");
			printf("                                    **                             **\n");
			printf("                                    **      ��л����ʹ�ã��ټ���   **\n");
			printf("                                    **                             **\n");
			printf("                                    *********************************\n");
			break;
		}
		if (operation == 1)
		{
			printf("**�������ʦ��**��");
			scanf("%d", &f);
			find(teacher, f, j);
		}
		if (operation == 2)
		{
			insret(teacher, ++j);
		}
		if (operation == 3)
		{
			printf("**��������Ҫɾ���Ľ�ʦ��Ϣ�Ľ�ʦ��**��");
			scanf("%d", &d);
			dele(teacher, d, j);
		}
		if (operation == 4)
		{
			printf("**��������Ҫ�޸ĵĽ�ʦ��Ϣ�Ľ�ʦ��**��");
			scanf("%d", &r);
			revise(teacher, r, j);
		}
		if (operation == 5)
		{
			for (i = 0; i <= N + j; i++)
			{
				if (teacher[i].id != 0)
				{
					printf("��ʦ�ţ�%d ,������%s ,�Ա�%d ,��λ���ƣ�%s ,��ͥסַ��%s ,��ϵ�绰��%s ,��������=%f ,����=%f ,�����=%f ,\
�绰��=%f ,ˮ���=%f ,����=%f ,����˰=%f ,������=%f ,������=%f ,�ϼƿۿ�=%f ,Ӧ������=%f ,ʵ������=%f\n\n", teacher[i].id, \
teacher[i].name, teacher[i].sex, teacher[i].unit, teacher[i].address, teacher[i].tell, \
teacher[i].a, teacher[i].b, teacher[i].c, teacher[i].d, teacher[i].e, teacher[i].f, teacher[i].g, teacher[i].h, teacher[i].i, teacher[i].j, teacher[i].l, teacher[i].k);
					a = 1;
				}
				if (a == 0)
					printf("**�����ݣ�**\n");
			}
		}
		if (operation != 0 && operation != 1 && operation != 2 && operation != 3 && operation != 4 && operation != 5)
			printf("**δ֪������**\n");
		putchar('\n');
	}
}
