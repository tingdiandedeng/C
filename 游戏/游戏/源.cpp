#include <stdio.h> 
#include <dos.h> 
#include <conio.h> 
#include <graphics.h> 
#include <stdlib.h> 
#ifdef __cplusplus 
#define __CPPARGS ... 
#else 
#define __CPPARGS 
#endif 
#define MINBOXSIZE 15 /* ��С����ĳߴ� */ 
#define BGCOLOR 7 /* ������ɫ */ 
#define GX 200 
#define GY 10 
#define SJNUM 10000 /* ÿ����Ҵ�һ��ֵȼ���һ��*/ 
/* ������*/
#define VK_LEFT 0x4b00 
#define VK_RIGHT 0x4d00 
#define VK_DOWN 0x5000 
#define VK_UP 0x4800 
#define VK_HOME 0x4700 
#define VK_END 0x4f00 
#define VK_SPACE 0x3920 
#define VK_ESC 0x011b 
#define VK_ENTER 0x1c0d 
/* �������˹����ķ����Ҷ�����Ϊ4�֣�*/
#define F_DONG 0 
#define F_NAN 1 
#define F_XI 2 
#define F_BEI 3 
#define NEXTCOL 20 /* Ҫ������һ�������������*/ 
#define NEXTROW 12 /* Ҫ������һ������ĺ�ӱ�*/ 
#define MAXROW 14 /* ��Ϸ��Ļ��С*/ 
#define MAXCOL 20 
#define SCCOL 100 /*��Ϸ��Ļ����ʾ���ϵ����λ��*/ 
#define SCROW 60 
int gril[22][16]; /* ��Ϸ��Ļ����*/
int col = 1, row = 7; /* ��ǰ����ĺ�������*/
int boxfx = 0, boxgs = 0; /* ��ǰ�¿����׳�ͷ���*/
int nextboxfx = 0, nextboxgs = 0, maxcol = 22;/*��һ���������׳�ͷ���*/
int minboxcolor = 6, nextminboxcolor = 6;
int num = 0; /*��Ϸ��*/
int dj = 0, gamedj[10] = { 18,16,14,12,10,8,6,4,2,1 };/* ��Ϸ�ȼ�*/
													  /* ����������һ��3ά��������¼����������״�ͷ���*/
int boxstr[7][4][16] = { {
	{ 1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0 },
	{ 0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0 },
	{ 1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0 },
	{ 0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0 } },
	{
		{ 0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0 },
		{ 1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0 },
		{ 0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0 },
		{ 1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0 } },
		{
			{ 1,1,0,0,0,1,0,0,0,1,0,0,0,0,0,0 },
			{ 1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0 },
			{ 1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0 },
			{ 0,0,1,0,1,1,1,0,0,0,0,0,0,0,0,0 } },
			{
				{ 1,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0 },
				{ 1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0 },
				{ 0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,0 },
				{ 1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0 } },
				{
					{ 0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0 },
					{ 0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0 },
					{ 0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0 },
					{ 0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0 } },
					{
						{ 1,1,0,0,1,1,0,0,0,0,0,0.0,0,0,0 },
						{ 1,1,0,0,1,1,0,0,0,0,0,0.0,0,0,0 },
						{ 1,1,0,0,1,1,0,0,0,0,0,0.0,0,0,0 },
						{ 1,1,0,0,1,1,0,0,0,0,0,0.0,0,0,0 } },
						{
							{ 0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0 },
							{ 1,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0 },
							{ 0,1,0,0,1,1,1,0,0,0,0,0.0,0,0,0 },
							{ 0,1,0,0,1,1,0,0,0,1,0,0,0,0,0,0 } }
};
/* ����õ���ǰ�������һ���������״�ͷ���*/
void boxrad() {
	minboxcolor = nextminboxcolor;
	boxgs = nextboxgs;
	boxfx = nextboxfx;
	nextminboxcolor = random(14) + 1;
	if (nextminboxcolor == 4 || nextminboxcolor == 7 || nextminboxcolor == 8)
		nextminboxcolor = 9;
	nextboxfx = F_DONG;
	nextboxgs = random(7);
}
/*��ʼ��ͼ��ģ��*/
void init(int gdrive, int gmode) {
	int errorcode;
	initgraph(&gdrive, &gmode, "e:\\tc");
	errorcode = graphresult();
	if (errorcode != grOk) {
		printf("error of: %s", grapherrormsg(errorcode));
		exit(1);
	}
}
/* ��ͼ��ģʽ�µ����� */
void cls()
{
	setfillstyle(SOLID_FILL, 0);
	setcolor(0);
	bar(0, 0, 640, 480);
}
/*��ͼ��ģʽ�µĸ߼�����*/
void clscr(int a, int b, int c, int d, int color) {
	setfillstyle(SOLID_FILL, color);
	setcolor(color);
	bar(a, b, c, d);
}
/*��С����Ļ���*/
void minbox(int asc, int bsc, int color, int bdcolor) {
	int a = 0, b = 0;
	a = SCCOL + asc;
	b = SCROW + bsc;
	clscr(a + 1, b + 1, a - 1 + MINBOXSIZE, b - 1 + MINBOXSIZE, color);
	if (color != BGCOLOR) {
		setcolor(bdcolor);
		line(a + 1, b + 1, a - 1 + MINBOXSIZE, b + 1);
		line(a + 1, b + 1, a + 1, b - 1 + MINBOXSIZE);
		line(a - 1 + MINBOXSIZE, b + 1, a - 1 + MINBOXSIZE, b - 1 + MINBOXSIZE);
		line(a + 1, b - 1 + MINBOXSIZE, a - 1 + MINBOXSIZE, b - 1 + MINBOXSIZE);
	}
}
/*��Ϸ�г��ֵ�����*/
void txt(int a, int b, char *txt, int font, int color) {
	setcolor(color);
	settextstyle(0, 0, font);
	outtextxy(a, b, txt);
}
/*windows ����*/
void win(int a, int b, int c, int d, int bgcolor, int bordercolor) {
	clscr(a, b, c, d, bgcolor);
	setcolor(bordercolor);
	line(a, b, c, b);
	line(a, b, a, d);
	line(a, d, c, d);
	line(c, b, c, d);
}
/* ��ǰ����Ļ���*/
void funbox(int a, int b, int color, int bdcolor) {
	int i, j;
	int boxz[4][4];
	for (i = 0; i<16; i++)
		boxz[i / 4][i % 4] = boxstr[boxgs][boxfx][i];
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++)
			if (boxz[i][j] == 1)
				minbox((j + row + a)*MINBOXSIZE, (i + col + b)*MINBOXSIZE, color, bdcolor);
}
/*��һ������Ļ���*/
void nextfunbox(int a, int b, int color, int bdcolor) {
	int i, j;
	int boxz[4][4];
	for (i = 0; i<16; i++)
		boxz[i / 4][i % 4] = boxstr[nextboxgs][nextboxfx][i];
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++)
			if (boxz[i][j] == 1)
				minbox((j + a)*MINBOXSIZE, (i + b)*MINBOXSIZE, color, bdcolor);
}
/*ʱ���ж϶���*/
#define TIMER 0x1c 
int TimerCounter = 0;
void interrupt(*oldhandler)(__CPPARGS);
void interrupt newhandler(__CPPARGS) {
	TimerCounter++;
	oldhandler();
}
void SetTimer(void interrupt(*IntProc)(__CPPARGS)) {
	oldhandler = getvect(TIMER);
	disable();
	setvect(TIMER, IntProc);
	enable();
}
/*������Ϸ�Ĺ�������������С�����һ��*/
void delcol(int a) {
	int i, j;
	for (i = a; i>1; i--)
		for (j = 1; j<15; j++) {
			minbox(j*MINBOXSIZE, i*MINBOXSIZE, BGCOLOR, BGCOLOR);
			gril[i][j] = gril[i - 1][j];
			if (gril[i][j] == 1)
				minbox(j*MINBOXSIZE, i*MINBOXSIZE, minboxcolor, 0);
		}
}
/*�������ж�����С�������*/
void delete() {
	int i, j, zero, delgx = 0;
	char *nm = "00000";
	for (i = 1; i<21; i++) {
		zero = 0;
		for (j = 1; j<15; j++)
			if (gril[j] == 0)
				zero = 1;
		if (zero == 0) {
			delcol(i);
			delgx++;
		}
	}
	num = num + delgx*delgx * 10;
	dj = num / 10000;
	sprintf(nm, "%d", num);
	clscr(456, 173, 500, 200, 4);
	txt(456, 173, "Number:", 1, 15);
	txt(456, 193, nm, 1, 15);
}
/*ʱ���жϽ���*/
void KillTimer() {
	disable();
	setvect(TIMER, oldhandler);
	enable();
}
/* ���Ե�ǰ�����Ƿ����������*/
int downok() {
	int i, j, k = 1, a[4][4];
	for (i = 0; i<16; i++)
		a[i / 4][i % 4] = boxstr[boxgs][boxfx][i];
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++)
			if (a[j] && gril[col + i + 1][row + j])
				k = 0;
	return(k);
}
/* ���Ե�ǰ�����Ƿ����������*/
int leftok() {
	int i, j, k = 1, a[4][4];
	for (i = 0; i<16; i++)
		a[i / 4][i % 4] = boxstr[boxgs][boxfx][i];
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++)
			if (a[j] && gril[col + i][row + j - 1])
				k = 0;
	return(k);
}
/* ���Ե�ǰ�����Ƿ����������*/
int rightok() {
	int i, j, k = 1, a[4][4];
	for (i = 0; i<16; i++)
		a[i / 4][i % 4] = boxstr[boxgs][boxfx][i];
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++)
			if (a[j] && gril[col + i][row + j + 1])
				k = 0;
	return(k);
}
/* ���Ե�ǰ�����Ƿ���Ա���*/
int upok() {
	int i, j, k = 1, a[4][4];
	for (i = 0; i<4; i++)
		for (i = 0; i<16; i++)
			a[i / 4][i % 4] = boxstr[boxgs][boxfx + 1][i];
	for (i = 3; i >= 0; i--)
		for (j = 3; j >= 0; j--)
			if (a[j] && gril[col + i][row + j])
				k = 0;
	return(k);
}
/*��ǰ��������֮�󣬸���Ļ���������*/
void setgril() {
	int i, j, a[4][4];
	funbox(0, 0, minboxcolor, 0);
	for (i = 0; i<16; i++)
		a[i / 4][i % 4] = boxstr[boxgs][boxfx][i];
	for (i = 0; i<4; i++)
		for (j = 0; j<4; j++)
			if (a[j])
				gril[col + i][row + j] = 1;
	col = 1; row = 7;
}
/*��Ϸ����*/
void gameover() {
	int i, j;
	for (i = 20; i>0; i--)
		for (j = 1; j<15; j++)
			minbox(j*MINBOXSIZE, i*MINBOXSIZE, 2, 0);
	txt(103, 203, "Game Over", 3, 10);
}
/*����������*/
void call_key(int keyx) {
	switch (keyx) {
	case VK_DOWN: { /*�·�������������һ��*/
		if (downok()) {
			col++;
			funbox(0, 0, minboxcolor, 0);
		}
		else {
			funbox(0, 0, minboxcolor, 0);
			setgril();
			nextfunbox(NEXTCOL, NEXTROW, 4, 4);
			boxrad();
			nextfunbox(NEXTCOL, NEXTROW, nextminboxcolor, 0);
			delete();
		}
		break;
	}
	case VK_UP: { /*�Ϸ������������״��ת90��*/
		if (upok())
			boxfx++;
		if (boxfx>3)
			boxfx = 0;
		funbox(0, 0, minboxcolor, 0);
		break;
	}
	case VK_LEFT: { /*��������������һ*/
		if (leftok())
			row--;
		funbox(0, 0, minboxcolor, 0);
		break;
	}
	case VK_RIGHT: { /*�ҷ�������������һ*/
		if (rightok())
			row++;
		funbox(0, 0, minboxcolor, 0);
		break;
	}
	case VK_SPACE: /*�ո����ֱ���䵽�������䵽������*/
		while (downok())
			col++;
		funbox(0, 0, minboxcolor, 0);
		setgril();
		nextfunbox(NEXTCOL, NEXTROW, 4, 4);
		boxrad();
		nextfunbox(NEXTCOL, NEXTROW, nextminboxcolor, 0);
		delete();
		break;
	default:
	{
		txt(423, 53, "worng key!", 1, 4);
		txt(428, 80, "Plese Enter Anly Key AG!", 1, 4);
		getch();
		clscr(420, 50, 622, 97, BGCOLOR);
	}
	}
}
/*ʱ���жϿ�ʼ*/
void timezd(void) {
	int key;
	SetTimer(newhandler);
	boxrad();
	nextfunbox(NEXTCOL, NEXTROW, nextminboxcolor, 0);
	for (;;) {
		if (bioskey(1)) {
			key = bioskey(0);
			funbox(0, 0, BGCOLOR, BGCOLOR);
			if (key == VK_ESC)
				break;
			call_key(key);
		}
		if (TimerCounter>gamedj[dj]) {
			TimerCounter = 0;
			if (downok()) {
				funbox(0, 0, BGCOLOR, BGCOLOR);
				col++;
				funbox(0, 0, minboxcolor, 0);
			}
			else {
				if (col == 1) {
					gameover();
					getch();
					break;
				}
				setgril();
				delete();
				funbox(0, 0, minboxcolor, 0);
				col = 1; row = 7;
				funbox(0, 0, BGCOLOR, BGCOLOR);
				nextfunbox(NEXTCOL, NEXTROW, 4, 4);
				boxrad();
				nextfunbox(NEXTCOL, NEXTROW, nextminboxcolor, 0);
			}
		}
	}
}
/*������ʼ*/
void main(void) {
	int i, j;
	char *nm = "00000";
	init(VGA, VGAHI);
	cls();
	/*��Ļ�����ʼ��*/
	for (i = 0; i <= MAXCOL + 1; i++)
		for (j = 0; j <= MAXROW + 1; j++)
			gril[i][j] = 0;
	for (i = 0; i <= MAXCOL + 1; i++) {
		gril[i][0] = 1;
		gril[i][15] = 1;
	}
	for (j = 1; j <= MAXROW; j++) {
		gril[0][j] = 1;
		gril[21][j] = 1;
	}
	clscr(0, 0, 640, 480, 15);
	win(1, 1, 639, 479, 4, 15);
	win(SCCOL + MINBOXSIZE - 2, SCROW + MINBOXSIZE - 2, SCCOL + 15 * MINBOXSIZE + 2, SCROW + 21 * MINBOXSIZE + 2, BGCOLOR, 0);
	nextboxgs = random(8);
	nextboxfx = random(4);
	sprintf(nm, "%d", num);
	txt(456, 173, "Number:", 1, 15);
	txt(456, 193, nm, 1, 15);
	txt(456, 243, "Next Box:", 1, 15);
	timezd();
	KillTimer();
	closegraph();
	getch();
}