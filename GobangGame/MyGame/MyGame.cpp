#include <iostream>
#include <graphics.h>
using namespace std;

int CheckerBoard[15][15] = { 0 }; //定义棋盘的全局变量
MOUSEMSG mouse; //定义鼠标的全局变量

//画黑键
void drow_Black(int x, int y)
{
	setfillcolor(BLACK);
	fillcircle(x, y, 10);
}
//画白键
void drow_White(int x, int y)
{
	setfillcolor(WHITE);
	fillcircle(x, y, 10);
}

int main()
{
	//加载画面
	initgraph(720, 600); // 初始图形化界面，宽高	
	loadimage(NULL, "1.png");				//背景图片
	FlushMouseMsgBuffer();// 清空鼠标消息缓冲区
	while (1)
	{
		mouse = GetMouseMsg();// 获取一个鼠标消息。如果没有，就等待
		if (mouse.uMsg == WM_LBUTTONDOWN)	//是否按鼠标左键
		{
			drow_Black(mouse.x, mouse.y);
		}
		if (mouse.uMsg == WM_RBUTTONDOWN)	//是否按鼠标左键
		{
			drow_White(mouse.x, mouse.y);
		}
	}
}