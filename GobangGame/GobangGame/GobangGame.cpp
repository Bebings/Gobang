#include <iostream>
#include <graphics.h>
#include<atltrace.h>
using namespace std;

#define TRACE ATLTRACE   //TRACE("%d \n");
#define CHESSNUM 5   //�궨��5����������  6  ��������

int a[15][15] = { 0 }; //�������̵�ȫ�ֱ���
MOUSEMSG mouse; //��������ȫ�ֱ���


//�Զ�����Ӻ���
void init();		//��ʼ������
void put(int penson, int x, int y); //�ڶ�λ���齫Ԫ����Ϊ�ǿգ��൱�ڷ�������
void drow_Black(int x, int y);		//������
void drow_White(int x, int y);		//������
int change(short k);				//���������λ����ӳ�䣬�����ж���Ӯ
void show(int person);				//ʤ��ʱ��ʾ�Ľ���
bool Check_Win(int person, int x, int y);	//���ø��ֺ������ж��Ƿ�ʤ��
bool Check_LeftAndRight(int person, int x, int y);	//�������������Ƿ��������
bool Check_TopAndButton(int person, int x, int y);	//�������������Ƿ��������
bool Check_LeftAndDiagonal(int person, int x, int y);	//����������б�Ƿ��������
bool Check_RightAndDiagonal(int person, int x, int y);	//����������б�Ƿ��������



//��������
void put(int penson, int x, int y)
{
	//���1����Ϊ1�����2����Ϊ2
	if (penson == 1)
	{
		a[x][y] = 1;
	}
	else
	{
		a[x][y] = 2;
	}
}

//���ڼ�
void drow_Black(int x, int y)
{
	setfillcolor(BLACK);
	int x1 = 50 + x * 30 + 15;
	int y1 = 50 + y * 30 + 15;
	fillcircle(x1, y1, 10);
}

//���׼�
void drow_White(int x, int y)
{
	setfillcolor(WHITE);
	int x1 = 50 + x * 30 + 15;
	int y1 = 50 + y * 30 + 15;
	fillcircle(x1, y1, 10);
}

//�������ά�����ӳ��
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

//չʾʤ����
void show(int person)
{
	settextcolor(RGB(60, 100, 150));//����������ɫ
	settextstyle(80, 20, _T("΢���ź�"));
	if (person == 1)
	{
		outtextxy(130, 350, _T("��ɫ��,��Ӯ��!"));
		
	}
	else
	{
		outtextxy(130, 350, _T("��ɫ��,��Ӯ��!"));
	}
	    outtextxy(130, 430, _T("���ո������! "));
}

//��������abs(x - i)
bool Check_LeftAndRight(int person, int x, int y) 
{
	int count = 0;
	int flag[15] = { 0 };
	//����ͬʱ����
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

//��������
bool Check_TopAndButton(int person, int x, int y)
{
	int count = 0;
	int flag[15] = { 0 };
	//����ͬʱ����
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
//��������б��
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

//��������б��
bool Check_RightAndDiagonal(int person, int x, int y)
{
	int count = 0;
	int flag[15] = { 0 };
	//��б����ͬʱ����
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

//�ж��Ƿ�ʤ��
bool Check_Win(int person, int x, int y)
{
	//�������
	if (Check_LeftAndRight(person, x, y))
	{
		return true;
	}
	//�������
	else if (Check_TopAndButton(person, x, y))
	{
		return true;
	}
	//�����б
	else if (Check_LeftAndDiagonal(person, x, y))
	{
		return true;
	}
	//�����б
	else if (Check_RightAndDiagonal(person, x, y))
	{
		return true;
	}
	else
	{
		return false;
	}
}


//�����ʼ��
void init()
{
	loadimage(NULL, "1.png");				//����ͼƬ
	//��Ļ������
	setlinecolor(BLACK);
	setbkcolor(WHITE);     //������ɫ
	for (int i = 50; i <= 500; i += 30)// ����
		line(50, i, 500, i);
	for (int i = 50; i <= 500; i += 30)
		line(i, 50, i, 500);

	memset(a, 0, sizeof(a)); //�����������
	FlushMouseMsgBuffer();// ��������Ϣ������
}

int main()
{
	//���ػ���
	initgraph(720, 600); // ��ʼͼ�λ����棬���	
	init();//���ػ���
	int x, y;
	int person = 1;
	while (true)
	{
		mouse = GetMouseMsg();// ��ȡһ�������Ϣ�����û�У��͵ȴ�
		if (mouse.uMsg == WM_LBUTTONDOWN)	//�Ƿ�������
		{
			x = change(mouse.x);
			y = change(mouse.y);
			if (x >= 0 && x < 15 && y >= 0 && y < 15)
			{
				if (a[x][y] == 0)
				{
					if (person == 1)
					{	//���ڼ�
						drow_Black(x, y);
						//������λ�ø�ֵ
						put(person, x, y);
						//�ж��Ƿ�ʤ��
						if (Check_Win(person, x, y))
						{
							show(person);
							system("pause");						
							init();//���ػ���
						}
						person = 2;
					}
					else
					{
						drow_White(x, y);
						//������λ�ø�ֵ
						put(person, x, y);
						//�ж��Ƿ�ʤ��
						if (Check_Win(person, x, y))
						{
							show(person);
							system("pause");
							init();//���ػ���
						}
						person = 1;
					}
				}
			}
			else  //���¿�ʼ�Ծ�
			{
				person = 1;
				init();//���ػ���
			}
		}
	}
	return 0;
}