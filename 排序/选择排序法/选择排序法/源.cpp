#include<stdio.h>
void main()
{
	int A[10],a,min,b,c,f;
	printf("随机输入十个整数以空格分隔：");
	for (a = 0; a < 10; a++)        /*从键盘输入数组*/
		scanf_s("%d", &A[a]);
	getchar();
	for (a = 0; a < 10; a++)    /*外层循环，排序完成的数列由左向右推进*/
	{
		min = A[a];      /*假设第一个数为最小数*/
		b = a;
		f = a;
		for (b;b < 10; b++)  /*内层循环，寻找最小数，并赋值到min*/
		{
			if (A[b] < min)
			{
				min = A[b];
				f = b;  /*定位最小数的位置量b，并赋值到f*/
			}
		}
		c = A[a];    /*最小数与未排序的最末位数交换位置*/
		A[f] = A[a];
		A[a] = min;
	}
	printf("由小到大排序结果为：");/*输出由小到大排序结果*/
	for (a = 0; a < 10; a++)
		printf(" %d", A[a]);
	putchar('\n');
}