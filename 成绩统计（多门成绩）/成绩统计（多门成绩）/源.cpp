#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 26
void fales(char *stud_name[], int stud_id[], int stud_grade[], int n);/*统计不及格人数，并打印名单*/
void fales(char *stud_name[], int stud_id[], int stud_grade[], int n)
{
	int i, count = 0;
	printf("不及格名单有：\n");
	for (i = 0; i < n; i++)
	{
		if (stud_grade[i] < 60)
		{
			++count;
			printf("%s %d %d", stud_name[i], stud_id[i], stud_grade[i]);
			putchar('\n');
		}
	}
	printf("总计%d人\n", count);
}
void best(char *stud_name[], int stud_id[], int stud_grade[], int n);
void best(char *stud_name[], int stud_id[], int stud_grade[], int n)/*统计最高分*/
{
	int best = 0;
	int i;
	printf("最高成绩为：\n");
	for (i = 1; i < n; i++)
	{
		if (stud_grade[i]>stud_grade[best]);
		best = i;
	}
	printf("%s %d %d\n", stud_name[best], stud_id[best], stud_grade[best]);
	for (i = 0; i < n; ++i)
		if (stud_grade[i] == stud_grade[best] && (i != best))
			printf("%s %d %d", stud_name[i], stud_id[i], stud_grade[i]);
}
void main()
{
	char *stud_name[N];
	int stud_id[N];
	int stud_grade[N];
	int i, X = 1, Y = 100, n = N;
	srand((unsigned)time(NULL));
	for (i = 0; i < N; i++)
		stud_name[i] = (char*)malloc(10);   /*开辟内存*/
	for (i = 0; i < N; i++)
	{
		printf("输入第%d个人的名字（%d人）\n", i + 1, n);
		scanf("%s", stud_name[i]);
	}
	for (i = 0; i < N; i++)
	{
		printf("依次输入第%d个人的学号（%d人）\n", i + 1, n);
		scanf("%d", &stud_id[i]);
	}
	for (i = 0; i < N; i++)
		stud_grade[i] = rand() % (Y - X + 1) + X;   /*使用随机函数产生随机分数*/
	fales(stud_name, stud_id, stud_grade, n);
	best(stud_name, stud_id, stud_grade, n);
	for (i = 0; i < N; i++)    /*释放内存*/
	{
		free(stud_name[i]);
		stud_name[i] = NULL;
	}
}