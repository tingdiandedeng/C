#include<stdio.h>
void main()
{
	int j = 30;
	long double pai = 1, a, b, c;
	for (b = 1.0, a = 3.0, c = 1.0; b <= j; ++b, a += 2.0)
	{
		c = (b / a)*c;
		pai = pai + c;
	}
	pai = 2 * pai;
	printf("¹ÀËã¦ÐÖµÎª:%.10lf\n", pai);
}