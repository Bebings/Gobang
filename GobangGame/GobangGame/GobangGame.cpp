#include <iostream>
#include <graphics.h>
#include<atltrace.h>
using namespace std;

#define TRACE ATLTRACE   //TRACE("%d \n");
#define CHESSNUM 5   //宏定义5就是五子棋  6  就六子棋

int a[15][15] = { 0 }; //定义棋盘的全局变量
MOUSEMSG mouse; //定义鼠标的全局变量


//自定义的子函数
void init();		//初始化界面
void put(int penson, int x, int y); //在二位数组将元素置为非空，相当于放下棋子
void drow_Black(int x, int y);		//画黑棋
void drow_White(int x, int y);		//画白棋
int change(short k);				//将棋盘与二位数组映射，方便判断输赢
void show(int person);				//胜利时显示的界面
bool Check_Win(int person, int x, int y);	//调用各种函数，判断是否胜利
bool Check_LeftAndRight(int person, int x, int y);	//检索棋盘左右是否五颗相连
bool Check_TopAndButton(int person, int x, int y);	//检索棋盘上下是否五颗相连
bool Check_LeftAndDiagonal(int person, int x, int y);	//检索棋盘左斜是否五颗相连
bool Check_RightAndDiagonal(int person, int x, int y);	//检索棋盘右斜是否五颗相连



//放下棋子
void put(int penson, int x, int y)
{
	//玩家1则置为1，玩家2则置为2
	if (penson == 1)
	{
		a[x][y] = 1;
	}
	else
	{
		a[x][y] = 2;
	}
}

//画黑键
void drow_Black(int x, int y)
{
	setfillcolor(BLACK);
	int x1 = 50 + x * 30 + 15;
	int y1 = 50 + y * 30 + 15;
	fillcircle(x1, y1, 10);
}

//画白键
void drow_White(int x, int y)
{
	setfillcolor(WHITE);
	int x1 = 50 + x * 30 + 15;
	int y1 = 50 + y * 30 + 15;
	fillcircle(x1, y1, 10);
}

//棋盘与二维数组的映射
int change(short k)
{
	int n = (k - 50) / 30;
	int n1 = (k - 50) % 30;
	if (n1 > 0)
	{
		n = n + 1;
	}
	return n - 1;
}

//展示胜利框
void show(int person)
{
	settextcolor(RGB(60, 100, 150));//设置字体颜色
	settextstyle(80, 20, _T("微软雅黑"));
	if (person == 1)
	{
		outtextxy(130, 350, _T("黑色方,你赢了!"));
		
	}
	else
	{
		outtextxy(130, 350, _T("白色方,你赢了!"));
	}
	    outtextxy(130, 430, _T("按空格键继续! "));
}

//检索左右abs(x - i)
bool Check_LeftAndRight(int person, int x, int y) 
{
	int count = 0;
	int flag[15] = { 0 };
	//左右同时检索
	for (int i = 0; i < 15; i++)
	{
		if (x - i >= 0 && (a[x - i][y] == person))
		{
			flag[x - i] = person;
		}
		if ((x +i) < 15 && (a[x + i][y]== person))
		{
			flag[x + i] = person;
		}
	}

	for (size_t i = 0; i < 15; i++)
	{
		if (flag[i] != 0)
		{
			count++;
		}
		else
		{
			count = 0;
		}
			
		if (count >= CHESSNUM)
		{
			return true;
		}

	}
	return false;
}

//检索上下
bool Check_TopAndButton(int person, int x, int y)
{
	int count = 0;
	int flag[15] = { 0 };
	//上下同时检索
	for (int i = 0; i < 15; i++)
	{
		if (y - i >= 0 && (a[x][y - i] == person))
		{
			flag[y - i] = person;
		}

		if ((y + i) < 15 && (a[x][y + i] == person))
		{
			flag[y + i] = person;
		}
	}

	for (size_t i = 0; i < 15; i++)
	{
		if (flag[i] != 0)
		{
			count++;
		}
		else
		{
			count = 0;
		}
			
		if (count >= CHESSNUM)
		{
			return true;
		}
	}
	return false;
}
//检索左倾斜角
bool Check_LeftAndDiagonal(int person, int x, int y)
{
	int count = 0;
	int flag[15] = { 0 };

	for (int i = 0; i <= 15; i++)
	{
		if (x - i >= 0 && y - i >= 0 && (a[x - i][y - i] == person))
		{
			flag[x - i] = person;
		}
		if (x + i < 15 && y + i < 15 && (a[x + i][y + i] == person))
		{
			flag[x + i] = person;
		}
	}

	for (size_t i = 0; i < 15; i++)
	{
		if (flag[i] != 0)
		{
			count++;
		}
		else
		{
			count = 0;
		}

		if (count >= CHESSNUM)
		{
			return true;
		}
	}
	return false;
}

//检索右倾斜角
bool Check_RightAndDiagonal(int person, int x, int y)
{
	int count = 0;
	int flag[15] = { 0 };
	//倾斜上下同时检索
	for (int i = 0; i <= 15; i++)
	{
		if (x + i < 15 && y - i >= 0 && a[x + i][y - i] == person)
		{
			flag[x + i] = person;
		}
		if (x - i >= 0 && y + i < 15 && a[x - i][y + i] == person)
		{
			flag[x - i] = person;
		}
	}

	for (size_t i = 0; i < 15; i++)
	{
		if (flag[i] != 0)
		{
			count++;
		}
		else
		{
			count = 0;
		}

		if (count >= CHESSNUM)
		{
			return true;
		}
	}
	return false;
}

//判断是否胜利
bool Check_Win(int person, int x, int y)
{
	//检查左右
	if (Check_LeftAndRight(person, x, y))
	{
		return true;
	}
	//检查上下
	else if (Check_TopAndButton(person, x, y))
	{
		return true;
	}
	//检查左斜
	else if (Check_LeftAndDiagonal(person, x, y))
	{
		return true;
	}
	//检查右斜
	else if (Check_RightAndDiagonal(person, x, y))
	{
		return true;
	}
	else
	{
		return false;
	}
}


//画面初始化
void init()
{
	loadimage(NULL, "1.png");				//背景图片
	//给幕布画线
	setlinecolor(BLACK);
	setbkcolor(WHITE);     //背景颜色
	for (int i = 50; i <= 500; i += 30)// 画线
		line(50, i, 500, i);
	for (int i = 50; i <= 500; i += 30)
		line(i, 50, i, 500);

	memset(a, 0, sizeof(a)); //清空数组数据
	FlushMouseMsgBuffer();// 清空鼠标消息缓冲区
}

int main()
{
	//加载画面
	initgraph(720, 600); // 初始图形化界面，宽高	
	init();//加载画面
	int x, y;
	int person = 1;
	while (true)
	{
		mouse = GetMouseMsg();// 获取一个鼠标消息。如果没有，就等待
		if (mouse.uMsg == WM_LBUTTONDOWN)	//是否按鼠标左键
		{
			x = change(mouse.x);
			y = change(mouse.y);
			if (x >= 0 && x < 15 && y >= 0 && y < 15)
			{
				if (a[x][y] == 0)
				{
					if (person == 1)
					{	//画黑键
						drow_Black(x, y);
						//给数组位置赋值
						put(person, x, y);
						//判断是否胜利
						if (Check_Win(person, x, y))
						{
							show(person);
							system("pause");						
							init();//加载画面
						}
						person = 2;
					}
					else
					{
						drow_White(x, y);
						//给数组位置赋值
						put(person, x, y);
						//判断是否胜利
						if (Check_Win(person, x, y))
						{
							show(person);
							system("pause");
							init();//加载画面
						}
						person = 1;
					}
				}
			}
			else  //重新开始对局
			{
				person = 1;
				init();//加载画面
			}
		}
	}
	return 0;
}