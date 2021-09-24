#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<ctime>
#include "D:\software\VC\Auxiliary\VS\include\easyx.h"
#include<math.h>
#define GRID_W 100  //格子宽度
#define MAX_SIZE 4  //格子数量
#define INTERVAL 15 //间距
#define WIN_SIZE  GRID_W*MAX_SIZE+INTERVAL*(MAX_SIZE+1) //界面边长
using namespace std;
enum Color
{
	twoto0 = RGB(205,193 ,180 ),
	twoto1 = RGB(238,228 ,218 ),
	twoto2 = RGB(237,224 ,200 ),
	twoto3 = RGB(242,177 ,121 ),
	twoto4 = RGB(245,149 ,99 ),
	twoto5 = RGB(246,124 ,95 ),
	twoto6 = RGB(246,94 ,59 ),
	twoto7 = RGB(239, 206, 113),
	twoto8 = RGB(238, 204, 96),
	twoto9 = RGB(238, 199, 78),
	twoto10 = RGB(227, 186, 20),
	twoto11 = RGB(236, 198, 0),
	twoto12 = RGB(118, 96, 204),
};
Color arr[13] = { twoto0,twoto1, twoto2, twoto3, twoto4, twoto5, twoto6, twoto7,  twoto8, twoto9,twoto10,twoto11,twoto12};
int map[MAX_SIZE][MAX_SIZE]={0};
int score=0;
int creatNum()
{
	srand((unsigned)time(NULL) + clock());
	if (rand() % 6 == 0)
	{
		return 4;
	}
	else return 2;
}
void gameOver()
{
	setfillcolor RGB(205, 193, 180);
	//solidroundrect(INTERVAL, WIN_SIZE + INTERVAL, WIN_SIZE - GRID_W - INTERVAL *6, WIN_SIZE + GRID_W, 8, 8);
	settextstyle(50, 0, "Tahoma");
	setbkmode(TRANSPARENT);
	settextcolor(RGB(119, 110, 101));
	outtextxy(INTERVAL*2, WIN_SIZE +1*INTERVAL, "Game Over!");
	{settextstyle(26, 0, "楷体");
	if (score < 6666)outtextxy(INTERVAL * 2, WIN_SIZE + 5 * INTERVAL, "你别不是个傻子哟。");
	if (score >= 6666&&score<10000){
		settextstyle(30, 0, "楷体");
		outtextxy(INTERVAL * 2, WIN_SIZE + 5 * INTERVAL, "哇哦太帅了！o(￣▽￣)ｄ");
	}
	if (score >= 10000) {
		settextstyle(30, 0, "楷体");
		outtextxy(INTERVAL * 2, WIN_SIZE + 5 * INTERVAL, "哇哦太帅了！o(￣▽￣)ｄ");
	}
	}
}
void mapAdd()
{
	int i, j,temp=0;
	for (i = 0; i < MAX_SIZE; i++)
	{
		for (j = 0; j < MAX_SIZE; j++)
		{
			if (map[i][j]==0)
			{
				temp = 1;
				break;
			}
		}
	}
	if (!temp)
	{
		
		return;
	}
	for (; ; )
	{
		int a = rand() % MAX_SIZE;
		int b = rand() % MAX_SIZE;
		if (map[a][b] == 0)
		{
			map[a][b] = creatNum();
			break;
		}
	}
	return ;
}
void moveUp()
{
	int i, begin, temp,flag=0;
	for (i = 0; i < MAX_SIZE; i++)
	{
		temp = 0;
		for (begin = 1; begin < MAX_SIZE; begin++)
		{
			if (map[begin][i] != 0)
			{
				if (map[temp][i] == 0)
				{
					if (map[begin][i] != 0)
					{
						flag = 1;
					}
					map[temp][i] = map[begin][i];
					map[begin][i] = 0;

				}
				else if (map[temp][i] == map[begin][i])
				{
					map[temp][i] += map[begin][i];
					score += map[temp][i];
					map[begin][i] = 0;
					temp++;
					flag = 1;
				}
				else
				{
					map[temp + 1][i] = map[begin][i];
					if ((temp + 1) != begin)
					{
						map[begin][i] = 0;
						flag = 1;
					}
					temp++;
				}
			}
		}
	}
	if (flag == 1) mapAdd();
}
void moveDown()
{
	int i, begin, temp, flag=0;
	for (i = 0; i < MAX_SIZE; i++)
	{
		 temp = MAX_SIZE-1;
		for (begin = MAX_SIZE - 2; begin >=0; begin--)
		{
			if (map[begin][i] != 0)
			{
				if (map[temp][i] == 0)
				{
					if (map[begin][i] != 0)
					{
						flag = 1;
					}
					map[temp][i] = map[begin][i];
					map[begin][i] = 0;
				}
				else if (map[temp][i] == map[begin][i])
				{
					flag = 1;
					map[temp][i] += map[begin][i];
					score += map[temp][i];
					map[begin][i] = 0;
					temp--;
				}
				else
				{
					map[temp - 1][i] = map[begin][i];
					if ((temp - 1) != begin)
					{
						flag = 1;
						map[begin][i] = 0;
					}
					temp--;
				}
			}
		}
	}
	if (flag == 1) mapAdd();
}
void moveLeft()
{
	int i, begin,temp,flag=0;
	for (i = 0; i < MAX_SIZE; i++)
	{
		 temp = 0;
		for (begin = 1; begin < MAX_SIZE; begin++)
		{
			if (map[i][begin] != 0)
			{
				if (map[i][temp] == 0)
				{
					if (map[i][begin] != 0)
					{
						flag = 1;
					}
					map[i][temp] = map[i][begin];
					map[i][begin] = 0;
				}
				else if (map[i][temp] == map[i][begin])
				{
					flag = 1;
					map[i][temp] += map[i][begin];
					score += map[i][temp];
					map[i][begin] = 0;
					temp++;
				}
				else
				{
					map[i][temp+1] = map[i][begin];
					if ((temp + 1) != begin)
					{	
							flag = 1;
						map[i][begin] = 0;
					}
					temp++;
				}
			}
		}
	}
	if (flag == 1) mapAdd();
}
void moveRight()
{
	int i, begin,temp,flag=0;
	for (i = 0; i < MAX_SIZE; i++)
	{
		 temp = MAX_SIZE - 1;
		for (begin = MAX_SIZE-2; begin >=0; begin--)
		{
			if (map[i][begin] != 0)
			{
				if (map[i][temp] == 0)
				{
					if (map[i][begin] != 0)
					{
						flag = 1;
					}
					map[i][temp] = map[i][begin];
					map[i][begin] = 0;
				}
				else if (map[i][temp] == map[i][begin])
				{
					flag = 1;
					map[i][temp] += map[i][begin];
					score += map[i][temp];
					map[i][begin] = 0;
					temp--;
				}
				else
				{
					map[i][temp - 1] = map[i][begin];
					if ((temp - 1) != begin)
					{
						flag = 1;
						map[i][begin] = 0;
					}
					temp--;
				}
			}
		}
	}
	if (flag == 1) mapAdd();
}
void keyDeal()
{
	char key = _getch();
	switch (key)
	{
	   case'w':
	   case'W':
	   case 72:
	   moveUp();
	   break;
	   case's':
	   case'S':
	   case 80:
	   moveDown();
	   break;
	   case'a':
	   case'A':
	   case 75:
	   moveLeft();
	   break;
	   case'd':
	   case'D':
	   case 77:
	   moveRight();
	   break;
	}

}
void gameDraw()
{	setbkcolor(RGB(189,173,160));
	cleardevice();	
	int i, j,temp=0,temp0=0;
	for (i = 0; i < MAX_SIZE; i++)
	{
		for (j = 0; j < MAX_SIZE;j++)
		{
			int x = j * GRID_W + (j + 1) * INTERVAL;
			int y = i * GRID_W + (i + 1) * INTERVAL;
			int index = (int) log2((double)map[i][j]);
			COLORREF tcolor = arr[index];
	        setfillcolor(tcolor);
			solidroundrect(x, y, x + GRID_W, y + GRID_W,8,8);
			
			if (map[i][j] != 0)
			{
				settextstyle(50, 0, "微软雅黑");
				setbkmode(TRANSPARENT);
				settextcolor(RGB(119, 110, 101));
				char str[10] = "";
				sprintf_s(str, "%d", map[i][j]);//不会了，用的c
				int tw = textwidth(str);
				int th = textheight(str);
				int tx = (GRID_W - tw) / 2;
				int ty = (GRID_W - th) / 2;
				outtextxy(x + tx, y + ty, str);
			}
			else temp = 1;
		//	cout << map[i][j]; 
		}
		//cout << endl;
	}
	for (i = 0; i < MAX_SIZE - 1; i++)
	{
		for (j = 0; j < MAX_SIZE - 1; j++)
		{
			if (map[i][j] == map[i + 1][j] ||  map[i][j] == map[i][j + 1])
			{
				temp0 = 1;
				break;
			}
		}
	}
	for (i = 0; i < MAX_SIZE-1; i++)
	{
		if (map[MAX_SIZE - 1][i]== map[MAX_SIZE - 1][i+1])
		{
			temp0 = 1;
		}

		if (map[i][MAX_SIZE - 1] == map[i + 1][MAX_SIZE - 1])
		{
			temp0 = 1;
		}
	}
	//cout << endl;
	char strI[10] = "";
	sprintf_s(strI, "%d", score);
	settextstyle(25, 0, "黑体");
	outtextxy(WIN_SIZE - GRID_W - INTERVAL * 5, WIN_SIZE + 1 * INTERVAL, "您的得分：");
	settextstyle(35, 0, "Consolas");
	outtextxy(WIN_SIZE - GRID_W - INTERVAL*2, WIN_SIZE + 3* INTERVAL, strI);
	if (temp==0&&temp0==0) gameOver();
}
void gameInit()
{  
	int i;
	for (i = 0; i <2; )
	{
		int a = rand() % MAX_SIZE;
		int b = rand() % MAX_SIZE;
		if (map[a][b] == 0)
		{
			map[a][b] = creatNum();
			i++;
		}
	}
}
int main()
{
	initgraph(WIN_SIZE, WIN_SIZE+GRID_W+INTERVAL,SHOWCONSOLE);
	gameInit();
	while (1)
	{
		gameDraw();
	    keyDeal();
	}
		closegraph();
	return 0;
}