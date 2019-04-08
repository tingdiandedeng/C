#include<stdio.h>
void main()
{
	int a, b;
	int c, d, e, f;
	printf("Ô¤²â³µÅÆºÅÎª£º");
	for (a = 33; a<100; a++)
	{
		    b = a*a;
			c = b / 1000;
			d = (b / 100) % 10;
			e = (b / 10) % 10;
			f = b % 10;
			if (c == d&&e == f)
				printf("%d\n", b);
	}
}
