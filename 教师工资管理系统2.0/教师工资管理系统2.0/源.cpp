#include<stdio.h>
#define N 1/*宏定义，初次统计教师人数为N+1个*/
typedef struct teach/*定义结构体，存储每个老师的数据，并利用typedef将结构体简化为TEACH数据类型*/
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
void count(TEACH teacher[], int j);/*定义count函数用于计算合计扣款，实发工资，应发工资。形参为结构体数组数组名与新增教师信息个数j。并将计算结果存入对应教师的信息中。*/
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
void find(TEACH teacher[], int f, int j);/*定义find函数，用于查找某教师号老师的所有信息，并显示。形参为数组名，被查找老师的教师号f，新增老师数j。*/
void find(TEACH teacher[], int f, int j)
{
	int i;
	for (i = 0; i <= (N + j); i++)
	{
		if (f == teacher[i].id)
		{
			printf("**查找结果如下**:\n");
			printf("教师号：%d ,姓名：%s ,性别：%d ,单位名称：%s ,家庭住址：%s ,联系电话：%s ,基本工资=%f ,津贴=%f ,生活补贴=%f ,\
电话费=%f ,水电费=%f ,房租=%f ,所得税=%f ,卫生费=%f ,公积金=%f ,合计扣款=%f ,应发工资=%f ,实发工资=%f\n", teacher[i].id, \
teacher[i].name, teacher[i].sex, teacher[i].unit, teacher[i].address, teacher[i].tell, \
teacher[i].a, teacher[i].b, teacher[i].c, teacher[i].d, teacher[i].e, teacher[i].f, teacher[i].g, teacher[i].h, teacher[i].i, teacher[i].j, teacher[i].l, teacher[i].k);
			return;
		}
	}
	printf("**查无此人！**\n");
	return;
}
void insret(TEACH teacher[], int j);/*定义insert函数，用于插入新一个老师的信息。形参为数组名，以及新增老师个数j。*/
void insret(TEACH teacher[], int j)
{
	int i = N + j;
	printf("请输入教师号:");
	scanf("%d", &teacher[i].id);
	printf("请输入姓名:");
	scanf("%s", teacher[i].name);
	printf("请输入性别(0代表女，1代表男):");
	scanf("%d", &teacher[i].sex);
	printf("请输入单位名称：");
	scanf("%s", teacher[i].unit);
	printf("请输入家庭住址：");
	scanf("%s", teacher[i].address);
	printf("请输入联系电话：");
	scanf("%s", teacher[i].tell);
	printf("请输入基本工资，津贴，生活补贴，电话费，水电费，房租，所得税，卫生费，公积金(用中文逗号分隔):\n");
	scanf("%f，%f，%f，%f，%f，%f，%f，%f，%f", &teacher[i].a, &teacher[i].b, &teacher[i].c, &teacher[i].d, &teacher[i].e, &teacher[i].f, &teacher[i].g, &teacher[i].h, &teacher[i].i);
	printf("**插入成功！**\n");
	count(teacher, j);
}
void dele(TEACH teacher[], int d, int j);/*定义dele函数，用于删除教师信息。形参d为被删除教师的教师号，j为被插入老师的人数。*/
void dele(TEACH teacher[], int d, int j)
{
	int i;
	for (i = 0; i <= (N + j); i++)
	{
		if (d == teacher[i].id)
		{
			teacher[i].id = 0;/*被删除老师的信息并未完全置零，而是仅将教师号置零。*/
			printf("**删除成功！**\n");
			return;
		}
	}
	printf("**查无此人！**\n");
	return;
}
void revise(TEACH teacher[], int r, int j);
void revise(TEACH teacher[], int r, int j)/*定义revise函数，用于重新修改某一教师信息，对教师信息重新录入。形参为数组名，r为被修改老师的教师号，j为新增老师的人数。*/
{
	int i;
	for (i = 0; i <= (N + j); i++)
	{
		if (r == teacher[i].id)
		{
			printf("**需要修改的信息如下：**\n");
			printf("教师号：%d ,姓名：%s ,性别：%d ,单位名称：%s ,家庭住址：%s ,联系电话：%s ,基本工资=%f ,津贴=%f ,生活补贴=%f ,\
电话费=%f ,水电费=%f ,房租=%f ,所得税=%f ,卫生费=%f ,公积金=%f ,合计扣款=%f ,应发工资=%f ,实发工资=%f\n", teacher[i].id, \
teacher[i].name, teacher[i].sex, teacher[i].unit, teacher[i].address, teacher[i].tell, \
teacher[i].a, teacher[i].b, teacher[i].c, teacher[i].d, teacher[i].e, teacher[i].f, teacher[i].g, teacher[i].h, teacher[i].i, teacher[i].j, teacher[i].l, teacher[i].k);
			printf("**输入修改后的信息：**\n");
			printf("请输入姓名:");
			scanf("%s", teacher[i].name);
			printf("请输入性别(0代表女，1代表男):");
			scanf("%d", &teacher[i].sex);
			printf("请输入单位名称：");
			scanf("%s", teacher[i].unit);
			printf("请输入家庭住址：");
			scanf("%s", teacher[i].address);
			printf("请输入联系电话：");
			scanf("%s", teacher[i].tell);
			printf("请输入基本工资，津贴，生活补贴，电话费，水电费，房租，所得税，卫生费，公积金(用英文逗号分隔):\n");
			scanf("%f，%f，%f，%f，%f，%f，%f，%f，%f", &teacher[i].a, &teacher[i].b, &teacher[i].c, &teacher[i].d, &teacher[i].e, &teacher[i].f, &teacher[i].g, &teacher[i].h, &teacher[i].i);
			printf("**修改成功！**\n");
			count(teacher, j);
			return;
		}
	}
	printf("**查无此人！**\n");
	return;
}
void main()
{

	TEACH teacher[50];/*定义结构体数组，用于存储所有教师信息。*/
	int i, f, operation = -1, j = 0, d, r, a = 0;
	printf("                                 ****************************************************\n");
	printf("                                 **                                                **\n");
	printf("                                 **    欢迎使用沈阳工业大学教师工资管理系统2.0     **\n");
	printf("                                 **                                                **\n");
	printf("                                 ****************************************************\n");
	for (i = 0; i <= N; i++)/*循环语句，对每个老师的所有信息进行存储。*/
	{
		printf("请输入第%d个人的教师号:", i + 1);
		scanf("%d", &teacher[i].id);
		printf("请输入姓名:");
		scanf("%s", teacher[i].name);
		printf("请输入性别(0代表女，1代表男):");
		scanf("%d", &teacher[i].sex);
		printf("请输入单位名称：");
		scanf("%s", teacher[i].unit);
		printf("请输入家庭住址：");
		scanf("%s", teacher[i].address);
		printf("请输入联系电话：");
		scanf("%s", teacher[i].tell);
		printf("请输入基本工资，津贴，生活补贴，电话费，水电费，房租，所得税，卫生费，公积金(用中文逗号分隔):\n");
		scanf("%f，%f，%f，%f，%f，%f，%f，%f，%f", &teacher[i].a, &teacher[i].b, &teacher[i].c, &teacher[i].d, &teacher[i].e, &teacher[i].f, &teacher[i].g, &teacher[i].h, &teacher[i].i);
		putchar('\n');
		count(teacher, j);
	}
	printf("**数据输入完成！**\n*\n*\n*\n*\n");
	for (i = 0;; i++)/*循环语句，输入某一操作代表的数字，用if语句进行判断，判断成功则调用对应函数。若输入0则该循环结束。*/
	{
		printf("     ***************************************************************************************************************\n");
		printf("     **请输入您想进行的操作（退出（0），查找（1），插入新教师信息（2），删除（3），修改（4）,浏览所有信息（5））：**\n");
		printf("     ***************************************************************************************************************\n");
		scanf("%d", &operation);
		if (operation == 0)
		{
			printf("                                    *********************************\n");
			printf("                                    **                             **\n");
			printf("                                    **      感谢您的使用，再见！   **\n");
			printf("                                    **                             **\n");
			printf("                                    *********************************\n");
			break;
		}
		if (operation == 1)
		{
			printf("**请输入教师号**：");
			scanf("%d", &f);
			find(teacher, f, j);
		}
		if (operation == 2)
		{
			insret(teacher, ++j);
		}
		if (operation == 3)
		{
			printf("**请输入需要删除的教师信息的教师号**：");
			scanf("%d", &d);
			dele(teacher, d, j);
		}
		if (operation == 4)
		{
			printf("**请输入需要修改的教师信息的教师号**：");
			scanf("%d", &r);
			revise(teacher, r, j);
		}
		if (operation == 5)
		{
			for (i = 0; i <= N + j; i++)
			{
				if (teacher[i].id != 0)
				{
					printf("教师号：%d ,姓名：%s ,性别：%d ,单位名称：%s ,家庭住址：%s ,联系电话：%s ,基本工资=%f ,津贴=%f ,生活补贴=%f ,\
电话费=%f ,水电费=%f ,房租=%f ,所得税=%f ,卫生费=%f ,公积金=%f ,合计扣款=%f ,应发工资=%f ,实发工资=%f\n\n", teacher[i].id, \
teacher[i].name, teacher[i].sex, teacher[i].unit, teacher[i].address, teacher[i].tell, \
teacher[i].a, teacher[i].b, teacher[i].c, teacher[i].d, teacher[i].e, teacher[i].f, teacher[i].g, teacher[i].h, teacher[i].i, teacher[i].j, teacher[i].l, teacher[i].k);
					a = 1;
				}
				if (a == 0)
					printf("**无数据！**\n");
			}
		}
		if (operation != 0 && operation != 1 && operation != 2 && operation != 3 && operation != 4 && operation != 5)
			printf("**未知操作！**\n");
		putchar('\n');
	}
}
