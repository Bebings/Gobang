#include <iostream>
#include <graphics.h>
using namespace std;

int CheckerBoard[15][15] = { 0 }; //�������̵�ȫ�ֱ���
MOUSEMSG mouse; //��������ȫ�ֱ���

//���ڼ�
void drow_Black(int x, int y)
{
	setfillcolor(BLACK);
	fillcircle(x, y, 10);
}
//���׼�
void drow_White(int x, int y)
{
	setfillcolor(WHITE);
	fillcircle(x, y, 10);
}

int main()
{
	//���ػ���
	initgraph(720, 600); // ��ʼͼ�λ����棬���	
	loadimage(NULL, "1.png");				//����ͼƬ
	FlushMouseMsgBuffer();// ��������Ϣ������
	while (1)
	{
		mouse = GetMouseMsg();// ��ȡһ�������Ϣ�����û�У��͵ȴ�
		if (mouse.uMsg == WM_LBUTTONDOWN)	//�Ƿ�������
		{
			drow_Black(mouse.x, mouse.y);
		}
		if (mouse.uMsg == WM_RBUTTONDOWN)	//�Ƿ�������
		{
			drow_White(mouse.x, mouse.y);
		}
	}
}