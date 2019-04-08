#include<stdio.h>
int exchange(int number);
int exchange(int number)
{
	int b = 0, i, j, c = 0, d;
	for (i = 0; number >= 1; i++)
	{
		if (number == 1)
		{
			for (j = 1, d = 1; j <= i; j++)
				d *= 10;
			c = d;
		}
		if (number != 1)
			if (number % 2 == 1)
			{
				if (i != 0)
				{
					for (j = 1, d = 1; j <= i; j++)
						d *= 10;
					c = d;
				}
				if (i == 0)
					c = 1;
			}
		number = number / 2;
		b += c;
		c = 0;
	}
	return b;
}
int getbits(int x, int p, int n);
int getbits(int x, int p, int n)
{

}
void main()
{
	int number,b,x;
	scanf_s("%d", &number);
	x = exchange(number);
	
}