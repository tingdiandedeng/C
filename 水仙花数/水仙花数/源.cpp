#include<stdio.h>
void main()
{
	int a, b, c, d, e;
	printf("水仙花数有：\n");
	for (a = 1; a <= 9; a++)
	{
		for (b = 0; b <= 9; b++)
		{
			for (c = 0; c <= 9; c++)
			{
				d = a * 100 + b * 10 + c;
				e = a*a*a + b*b*b + c*c*c;
				if (d == e)
				{
					printf(" %d\n", e);
				}
			}
		}
	}
}