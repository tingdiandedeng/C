#include<stdio.h>
void main()
{
	int y, m, d;
	printf("�����꣬�£���(��Ӣ�Ķ��ż��)��");
	scanf_s("%d,%d,%d", &y, &m, &d);
	if ((y % 4 != 0 || (y % 100 == 0 && y % 400 != 0)) && m == 2)
	{
		d == 28 ? m = 3, d = 1 : d += 1;
	}
	else
	{
		if (m == 2)
			d == 29 ? m = 3, d = 1 : d += 1;
		else
			if (m == 4 || m == 6 || m == 9 || m == 11)
				d == 30 ? m += 1, d = 1 : d += 1;
			else
				if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10)
					d == 31 ? m += 1, d = 1 : d += 1;
				else
					if (m == 12)
						d == 31 ? y += 1, m = 1, d = 1 : d += 1;
	}

	printf("��������ڣ�%d,%d,%d\n", y, m, d);
}