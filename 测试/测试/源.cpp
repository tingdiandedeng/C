#include<stdio.h>
int main()
{
	int t = 0, a = 4,n=2;
	if (n / 2)
	{
		int b = 6;
		t += b++;
	}
	else
		t += a++;
	printf("%d",a+t);
}