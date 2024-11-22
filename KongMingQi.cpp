
///////////////////////////////////////////////////
// �������ƣ����� ������
// ���뻷����Mictosoft Visual Studio 2022, EasyX_20200315(beta)
// �������ߣ�luoyh <2864292458@qq.com>
// �� �� �ţ�C�����о�
// �� �� �ţ�Version 1.0.0
// ����޸ģ�2024-11-18
//
#include<Let/graphics.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include <Windows.h>
#include <vector>
#include <stack>
#include <cstring>
#include <iostream>
using namespace std;

// #define UNICODE  // ֧�ֺ����L"΢���ź�"

#define PI acos(-1.0)

struct Button
{
  int X1;        // ���Ͻ�
  int Y1;
  int X2;        // ���½�
  int Y2;
  int size;      // �����С
  LPCTSTR str;    // ��Ӧ�ı�
};

Button button1 = { 90, 635, 605, 700, 40, TEXT("��ʼ��Ϸ") };
Button button2 = { 90, 700 + 10, 605, 765 + 10, 40, TEXT("��Ϸ˵��") };
Button button3 = { 90, 765 + 20, 605, 830 + 20, 40, TEXT("�˳�") };
bool WINDOWS(LPCTSTR str, IMAGE img, LPCTSTR str1, LPCTSTR str2);

void DrawButton(Button button, COLORREF color);
void DrawButtonT(Button button, COLORREF color);
void GradientFill(int left, int top, int right, int bottom, COLORREF startColor, COLORREF endColor);
int RETURN();
void HideSphere(float R, int alfa, int beta, int HideFlag, int X, int Y, COLORREF endColor);
// ���÷ֱ���Ϊ2560*1440���Ƽ���
int rW = GetSystemMetrics(SM_CXSCREEN); // ��Ļ��� ����
int rH = GetSystemMetrics(SM_CYSCREEN); // ��Ļ�߶� ����
// ȫ��
void Full_Screen();    // ȫ��
void DrawTXT();      // ����
void BianAN();      // �䰵��
void DrawLoge(int x, int y, int size, COLORREF color);
void DrawInit();    // ���Ƴ�ʼ����
void DrawKMQY(int x, int y, int size);    // ���ƿ�����
void BianLIANG();    // ����
void CheckForInput();
bool gameShouldContinue = false;
IMAGE img(rW, rH);
IMAGE img1(rW, rH);
// ��ͼƬ����ģ������
void Blur(IMAGE* pimg);
void INITCircle();
void MYCIRCLE(int x, int y);
// str������Ƶ��ַ���
// variable ����ÿ�εı���
// fors ÿ����Ҫѭ���Ĵ�������
// R ��Ȧ�İ뾶
// Radian �ۼӵĻ���
void DrawCircle(TCHAR str[25], int variable, int fors, int R, double Radian, int x, int y);    // ����һȦ�ַ�    
void DrawMouse(int x, int y);            // ������갴��
void DrawR(int x, int y);              // ���Ƴ���
void BeginGame();        // ��ʼ��Ϸ
void INstrucTionS();      // ��Ϸ����
bool EXIT();          // �˳�
// һ��Ȧ�Ľṹ��
struct TimeCircle
{
  int fors;                      // ÿһȦ�ֳɵķ���
  int R;                        // Ȧ�İ뾶
  double NextTime;                  // ��һ��ʱ��ʱ��
  double Radian;                    // �ۼӵĻ���
};
SYSTEMTIME ti;
TimeCircle TC[3];
TCHAR str[25];

// �����������������  
int getRandom(int min, int max)
{
  return rand() % (max - min + 1) + min;
}

// Point��  
class Point
{
public:
  int x, y;
  int xSpeed, ySpeed;
  int r;

  Point()
  {
    r = 3; // ��İ뾶  
    x = getRandom(0, getwidth() - r);
    y = getRandom(0, getheight() - r);
    xSpeed = getRandom(-3, 3);
    ySpeed = getRandom(-3, 3);
  }

  void draw()
{
    // ��������  
    x += xSpeed;
    y += ySpeed;

    // �����߽�ص�  
    if (x > getwidth() - r)
    {
      x = getwidth() - r;
      xSpeed = -xSpeed;
    }
    else if (x < 0)
    {
      x = 0;
      xSpeed = -xSpeed;
    }
    if (y > getheight() - r)
    {
      y = getheight() - r;
      ySpeed = -ySpeed;
    }
    else if (y < 0)
    {
      y = 0;
      ySpeed = -ySpeed;
    }

    // ���Ƶ�  
    setfillcolor(RGB(200, 200, 200));
    solidcircle(x, y, r);
  }
};

// Graph��  
class Graph
{
private:
  Point* points;
  int pointNumber;
  int maxDis;

public:
  Graph(int pointNum = 200, int maxDistance = 100)
  {
    pointNumber = pointNum;
    maxDis = maxDistance;
    points = new Point[pointNumber];
  }

  ~Graph()
  {
    delete[] points;
  }

  void draw()
{
    for (int i = 0; i < pointNumber; i++)
    {
      points[i].draw();

      for (int j = i + 1; j < pointNumber; j++)
      {
        int dx = points[i].x - points[j].x;
        int dy = points[i].y - points[j].y;
        int distance = sqrt(dx * dx + dy * dy);

        if (distance <= maxDis)
        {
          int NUM = 255 - static_cast<int>(distance * 255.0 / maxDis); // ȷ��NUM������  
          int offset = 50;
          setlinecolor(RGB(NUM + offset, NUM + offset, NUM + offset)); // ��NUM�ӽ�0ʱ����ɫ�ӽ���ɫ����NUM�ӽ�255ʱ����ɫ�ӽ���ɫ 
          setlinestyle(PS_SOLID, 1);
          line(points[i].x, points[i].y, points[j].x, points[j].y);
        }
      }
    }
  }
};
const int N = 7;
const int INVALID = 2;
const int PEG = 1;
const int EMPTY = 0;

struct Position
{
  int x, y;
  Position(int _x, int _y) : x(_x), y(_y)
  {}
};

struct Move
{
  Position pos;
  int dir;
  Move(Position _pos, int _dir) : pos(_pos), dir(_dir) {}
};

class PegSolitaire
{
private:
  int board[N][N];
  stack<Move> moveHistory;
  void drawBoard(int X, int Y)
{
    setlinecolor(WHITE);
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        int Mx = rW / 2 - 360 + j * 120;
        int My = rH / 2 - 360 + i * 120;

        if (board[i][j] == INVALID) continue;

        if (board[i][j] == PEG)
        {
          if (i == Y && j == X)
          {
            HideSphere(50, 30, 15, 1, Mx, My, YELLOW);
          }
          else
          {
            HideSphere(50, 30, 15, 1, Mx, My, WHITE);
          }
        }
        else if (board[i][j] == EMPTY)
        {
          setlinecolor(WHITE);
          circle(Mx, My, 50);
        }
      }
    }
    int pegCount = 0;
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        if (board[i][j] == PEG)
          pegCount++;
      }
    }

    HideSphere(30, 30, 15, 1, 2390, 80, WHITE);
    settextcolor(WHITE);
    settextstyle(60, 0, reinterpret_cast<LPCTSTR>("΢���ź�"), 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
    TCHAR s[20];
    _stprintf_s(s, _T(" X%d"), pegCount);
    outtextxy(2430, 60, s);
  }

  bool legalMove(int x, int y, int dir)
{
    int dx[] = { -2, 2, 0, 0 };
    int dy[] = { 0, 0, -2, 2 };
    int mx[] = { -1, 1, 0, 0 };
    int my[] = { 0, 0, -1, 1 };

    int nx = x + dx[dir];
    int ny = y + dy[dir];
    int mx1 = x + mx[dir];
    int my1 = y + my[dir];

    if (nx < 0 || ny < 0 || nx >= N || ny >= N) return false;
    if (board[nx][ny] != EMPTY) return false;
    if (board[mx1][my1] != PEG) return false;

    return true;
  }

  void makeMove(int x, int y, int dir)
{
    int dx[] = { -2, 2, 0, 0 };
    int dy[] = { 0, 0, -2, 2 };
    int mx[] = { -1, 1, 0, 0 };
    int my[] = { 0, 0, -1, 1 };

    int nx = x + dx[dir];
    int ny = y + dy[dir];
    int mx1 = x + mx[dir];
    int my1 = y + my[dir];

    board[x][y] = EMPTY;
    board[mx1][my1] = EMPTY;
    board[nx][ny] = PEG;

    moveHistory.push(Move(Position(x, y), dir));
  }

  void undoMove()
{
    if (moveHistory.empty()) return;

    Move lastMove = moveHistory.top();
    moveHistory.pop();

    int x = lastMove.pos.x;
    int y = lastMove.pos.y;
    int dir = lastMove.dir;

    int dx[] = { -2, 2, 0, 0 };
    int dy[] = { 0, 0, -2, 2 };
    int mx[] = { -1, 1, 0, 0 };
    int my[] = { 0, 0, -1, 1 };

    int nx = x + dx[dir];
    int ny = y + dy[dir];
    int mx1 = x + mx[dir];
    int my1 = y + my[dir];

    board[x][y] = PEG;
    board[mx1][my1] = PEG;
    board[nx][ny] = EMPTY;
  }

  bool isGameOver()
{
    for (int x = 0; x < N; ++x)
    {
      for (int y = 0; y < N; ++y)
      {
        if (board[x][y] == PEG)
        {
          for (int dir = 0; dir < 4; ++dir)
          {
            if (legalMove(x, y, dir)) return false;
          }
        }
      }
    }
    return true;
  }

  bool isWin()
{
    int pegCount = 0;
    for (int x = 0; x < N; ++x)
    {
      for (int y = 0; y < N; ++y)
      {
        if (board[x][y] == PEG) pegCount++;
      }
    }
    return pegCount == 1;
  }

  void resetBoard()
{
    int initialBoard[N][N] =
    {
      {2, 2, 1, 1, 1, 2, 2},
      {2, 2, 1, 1, 1, 2, 2},
      {1, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 0, 1, 1, 1},
      {1, 1, 1, 1, 1, 1, 1},
      {2, 2, 1, 1, 1, 2, 2},
      {2, 2, 1, 1, 1, 2, 2}
    };
    memcpy(board, initialBoard, sizeof(board));
    while (!moveHistory.empty()) moveHistory.pop();
  }

public:
  PegSolitaire()
  {
    resetBoard();
  }
  Graph g;
  void playGame()
{
    INITCircle();

    ExMessage msg;
    int DJNUM = 0;
    int Mx;
    int My;
    bool T = true;
    int x = 3;
    int y = 3;
    int dir = -1;
    drawBoard(x, y);
    bool JX = true;
    BeginBatchDraw();
    flushmessage();
    while (!isGameOver() && JX)
    {
      if (isWin())
      {
        IMAGE Mimg(rW, rH);

        // ���û�ͼĿ��Ϊ img ����
        SetWorkingImage(&Mimg);
        // ���»�ͼ������������� img ��������
        g.draw();
        drawBoard(y, x); // ÿ�β������ػ�����
        MYCIRCLE(rW / 2, rH / 2);
        DrawMouse(2300, 1360);
        DrawR(2120, 1360);
        // ���û�ͼĿ��Ϊ��ͼ����
        SetWorkingImage();
        if (!WINDOWS(_T("��ϲ��!��ս�ɹ�"), Mimg, _T("����һ��"), _T("�˳�")))
        {
          BeginGame();
        }
        break;
      }

      // ��ȡ��������
      // ��һ�λ�ȡ��ʼλ��
      // �ڶ��λ�ȡ��ֹλ�� ���㷽��
      //ExMessage m;    // ������Ϣ����

      while (peekmessage(&msg, EX_MOUSE | EX_KEY))  // �����ȡ������Ϣ��ִ��
      {
        switch (msg.message)
        {
        case WM_LBUTTONDOWN:
          if (msg.x > (rW / 2 - 420) && msg.x < (rW / 2 + 420) && msg.y>(rH / 2 - 420) && msg.y < (rH / 2 + 420))
          {
            DJNUM++;
            Mx = msg.x;
            My = msg.y;
          }

          break;
        case WM_RBUTTONUP:
        {

          JX = false;
        }
        break;
        //undoMove();  һ����������
        case WM_KEYDOWN:
          if (msg.vkcode == 0x52)
          {
              undoMove();
          }
          break;
        }
      }

      /*  cout << "������ x, y, ���� (0=��, 1=��, 2=��, 3=��): ";*/

      if (DJNUM == 1)        // ���µ�һ��
      {
        y = (Mx - (rW / 2 - 420)) / 120;
        x = (My - (rH / 2 - 420)) / 120;     // ��ȡ��ʼλ��
      }
      if (DJNUM == 2)        // ���µڶ��� ��ȡ����
      {
        int EndY = (Mx - (rW / 2 - 420)) / 120;
        int EndX = (My - (rH / 2 - 420)) / 120;
        if (EndX == x && EndY == (y - 2))
        {
          dir = 2;
        }
        if (EndX == x && EndY == (y + 2))
        {
          dir = 3;
        }
        if (EndY == y && EndX == (x - 2))
        {
          dir = 0;
        }
        if (EndY == y && EndX == (x + 2))
        {
          dir = 1;
        }
        T = false;
        DJNUM = 0;
        if (dir == -1)  // �ҵ�������
        {
          T = true;
          DJNUM = 0;
        }
      }

      if (!T)
      {
        if (legalMove(x, y, dir))
        {
          makeMove(x, y, dir);
          dir = -1;
          T = true;
        }
        else
        {
          /*cout << "�Ƿ��ƶ���" << endl;*/
        }
      }
      FlushBatchDraw();
      cleardevice();
      g.draw();
      drawBoard(y, x); // ÿ�β������ػ�����
      MYCIRCLE(rW / 2, rH / 2);
      DrawMouse(2300, 1360);
      DrawR(2120, 1360);
      /*  Sleep(20);*/

    }
    EndBatchDraw();

    if (!isWin())
    {
      int pegCount = 0;
      for (int i = 0; i < N; ++i)
      {
        for (int j = 0; j < N; ++j)
        {
          if (board[i][j] == PEG)
            pegCount++;
        }
      }
      TCHAR s[20];
      _stprintf_s(s, _T("��սʧ�ܣ���ʣ��%dö���ӣ�"), pegCount);
      IMAGE Mimg(rW, rH);

      // ���û�ͼĿ��Ϊ img ����
      SetWorkingImage(&Mimg);
      // ���»�ͼ������������� img ��������
      g.draw();
      drawBoard(y, x); // ÿ�β������ػ�����
      MYCIRCLE(rW / 2, rH / 2);
      DrawMouse(2300, 1360);
      DrawR(2120, 1360);
      // ���û�ͼĿ��Ϊ��ͼ����
      SetWorkingImage();
      if (!WINDOWS(s, Mimg, _T("����һ��"), _T("�˳�")))
      {
        BeginGame();
      }
    }
  }
};

int main()
{
  Full_Screen();
  DrawTXT();
  BianAN();
  // ������ ��ʾ ������
  DrawInit();
  BianLIANG();
  CheckForInput();
  // ������������������Ǽ��̻�����ꡣ������
  // ��ʼд��ť
  cleardevice();
  bool CTN = true;
  // ����Ƕ����⴦��һ��
  while (CTN)
  {
    int NUM = RETURN();        // ������
    switch (NUM)
    {
    case 0:BeginGame(); break;
    case 1:INstrucTionS(); break;
    case 2:CTN = EXIT(); break;
    }
  }
}

void Full_Screen()    // ȫ��
{
  HWND hwnd = initgraph(rW, rH);      // ��ʼ����ͼ���ڲ���ȡ���ھ������ EasyX Ϊ����
  LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE); // ��ȡ������Ϣ
  // ���ô�����Ϣ ��� ȡ�����������߿�
  SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);// ֱ���޸Ĵ�����ʽ
  SetWindowPos(hwnd, HWND_TOP, 0, 0, rW, rH, 0);
  setbkcolor(BLACK);
  cleardevice();      // ���ñ�����ɫΪ��ɫ
}

void DrawTXT()
{
  SetWorkingImage(&img);
  setlinecolor(RGB(51, 51, 51));
  settextcolor(RGB(51, 51, 51));
  setlinestyle(PS_SOLID | PS_ENDCAP_SQUARE | PS_JOIN_MITER, 3);
  rectangle(1080, 662, 1172, 776);
  setbkmode(TRANSPARENT);
  DrawLoge(1090, 680, 70, RGB(51, 51, 51));
  setlinecolor(WHITE);
  settextcolor(WHITE);
  setlinestyle(PS_SOLID | PS_ENDCAP_SQUARE | PS_JOIN_MITER, 4);
  rectangle(1080 - 6, 662 - 6, 1172 - 6, 776 - 6);
  DrawLoge(1090 - 4, 680 - 4, 70, WHITE);
  RECT r = { 1188,656,1480 + 60,726 };

  // �������Ч��Ϊ����� (VC6 / VC2008 / VC2010 / VC2012)
  LOGFONT f;
  gettextstyle(&f);            // ��ȡ��ǰ��������
  f.lfHeight = 80;            // ��������߶�Ϊ
  _tcscpy_s(f.lfFaceName, _T("����"));  // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
  f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ����� 
  settextstyle(&f);            // ����������ʽ
  drawtext(_T("C�����о�"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
  f.lfHeight = 45;            // ��������߶�Ϊ
  settextstyle(&f);            // ����������ʽ
  r = { 1188,743,1480 + 60,776 };
  drawtext(_T("C YUYAN YANJIU"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
  Sleep(1000);
  SetWorkingImage();
}

void BianAN()    // �䰵��
{
  // ��ȡ��ͼ���ں� img �������ʾ������ָ��
  DWORD* pbWnd = GetImageBuffer();
  DWORD* pbImg = GetImageBuffer(&img);

  // ����ԭͼƬÿ�������ɫ��ʵ���𽥱�����Ч��
  int r, g, b;
  for (int light = 1; light <= 64; light++)
  {
    for (int i = 0; i < rW * rH; i++)
    {
      r = (GetRValue(pbImg[i]) * light) >> 6;
      g = (GetGValue(pbImg[i]) * light) >> 6;
      b = (GetBValue(pbImg[i]) * light) >> 6;
      pbWnd[i] = RGB(r, g, b);
    }
    Sleep(20);
  }
  Sleep(1000);
  for (int light = 64; light >= 1; light--)
  {
    for (int i = 0; i < rW * rH; i++)
    {
      r = (GetRValue(pbImg[i]) * light) >> 6;
      g = (GetGValue(pbImg[i]) * light) >> 6;
      b = (GetBValue(pbImg[i]) * light) >> 6;
      pbWnd[i] = RGB(r, g, b);
    }
    Sleep(20);
  }
}

void DrawLoge(int x, int y, int size, COLORREF color)
{
  double JG = size / 16.0;
  setlinestyle(PS_SOLID | PS_ENDCAP_SQUARE | PS_JOIN_MITER, JG);
  circle(x + JG * 4, y + JG * 4, 2.5 * JG);
  circle(x + JG * 12, y + JG * 12, 2.5 * JG);
  setfillcolor(color);
  solidrectangle(x + JG * 8, y, x + size, y + JG * 8);
  solidrectangle(x, y + JG * 8, x + JG * 8, y + size);
  setfillcolor(BLACK);
  solidrectangle(x + JG * 3, y + JG * 9, x + JG * 5, y + JG * 15);
  solidrectangle(x + JG * 2, y + JG * 10, x + JG * 3, y + JG * 11);
  solidrectangle(x + JG * 2, y + JG * 14, x + JG * 6, y + JG * 15);
  solidrectangle(x + JG * 11, y + JG, x + JG * 13, y + JG * 7);
  solidrectangle(x + JG * 10, y + JG * 2, x + JG * 11, y + JG * 3);
  solidrectangle(x + JG * 10, y + JG * 6, x + JG * 14, y + JG * 7);
}

void DrawInit()
{
  SetWorkingImage(&img1);
  setbkmode(TRANSPARENT);
  settextcolor(WHITE);
  // �������Ч��Ϊ����� (VC6 / VC2008 / VC2010 / VC2012)
  LOGFONT f;
  gettextstyle(&f);            // ��ȡ��ǰ��������
  f.lfHeight = 300;            // ��������߶�Ϊ
  _tcscpy_s(f.lfFaceName, _T("��������"));  // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
  f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ����� 
  settextstyle(&f);            // ����������ʽ
  outtextxy(300, 400, _T("��"));
  outtextxy(500, 540, _T("��"));
  outtextxy(700, 680, _T("��"));
  DrawKMQY(1700, 690, 400);
  SetWorkingImage();
}

void DrawKMQY(int x, int y, int size)
{
  setlinecolor(WHITE);
  setlinestyle(PS_SOLID | PS_ENDCAP_SQUARE | PS_JOIN_MITER, 10);
  circle(x, y, size);
  int JG = size * 2 / 9.0;
  int R = JG - 50;
  setlinestyle(PS_SOLID | PS_ENDCAP_SQUARE | PS_JOIN_MITER, 4);
  circle(x, y, size + 14);
  int initialBoard[7][7] =
  {
    {2, 2, 1, 1, 1, 2, 2},
    {2, 2, 1, 1, 1, 2, 2},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1},
    {2, 2, 1, 1, 1, 2, 2},
    {2, 2, 1, 1, 1, 2, 2}
  };

  setfillcolor(WHITE);
  for (int i = 0; i < 7; ++i)
  {
    for (int j = 0; j < 7; ++j)
    {
      int X = x - JG * 3 + j * JG;
      int Y = y - JG * 3 + i * JG;

      if (initialBoard[i][j] == 2) continue;

      if (initialBoard[i][j] == 1)
      {
        solidcircle(X, Y, R);
      }
      else if (initialBoard[i][j] == 0)
      {
        circle(X, Y, R);
      }
    }
  }

  // �������Ч��Ϊ����� (VC6 / VC2008 / VC2010 / VC2012)
  LOGFONT f;
  gettextstyle(&f);              // ��ȡ��ǰ��������
  f.lfQuality = ANTIALIASED_QUALITY;      // �������Ч��Ϊ����� 
  f.lfHeight = 25;              // ��������߶�Ϊ
  _tcscpy_s(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
  settextcolor(RGB(120,120,120));
  settextstyle(&f);
  outtextxy(116, 1356, _T("? [2024] [΢�Ź��ںţ�C�����о�]. All rights reserved."));

  outtextxy(2200, 1335, _T("Version 1.0.0"));

}

void BianLIANG()    // ����
{
  // ��ȡ��ͼ���ں� img �������ʾ������ָ��
  DWORD* pbWnd = GetImageBuffer();
  DWORD* pbImg = GetImageBuffer(&img1);

  // ����ԭͼƬÿ�������ɫ��ʵ���𽥱�����Ч��
  int r, g, b;
  for (int light = 1; light <= 64; light++)
  {
    for (int i = 0; i < rW * rH; i++)
    {
      r = (GetRValue(pbImg[i]) * light) >> 6;
      g = (GetGValue(pbImg[i]) * light) >> 6;
      b = (GetBValue(pbImg[i]) * light) >> 6;
      pbWnd[i] = RGB(r, g, b);
    }
    Sleep(30);
  }
  // �������Ч��Ϊ����� (VC6 / VC2008 / VC2010 / VC2012)
  LOGFONT f;
  gettextstyle(&f);              // ��ȡ��ǰ��������
  f.lfQuality = ANTIALIASED_QUALITY;      // �������Ч��Ϊ����� 
  f.lfHeight = 30;              // ��������߶�Ϊ
  _tcscpy_s(f.lfFaceName, _T("����"));    // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
  settextcolor(GREEN);
  settextstyle(&f);
  outtextxy(500, 1000, _T("���������ʼ"));
}

void CheckForInput()
{
  ExMessage msg;

  // ��Ϸ����ѭ��
  while (true)
  {
    peekmessage(&msg, EX_MOUSE);
    if (msg.lbutton)
    {
      return;
    }
    else if (msg.rbutton)
    {
      return;
    }
    else if (msg.message == WM_KEYDOWN || msg.message == WM_SYSKEYDOWN)
    {
      return; // �˳�����
    }
  }
}

void DrawButton(Button button, COLORREF color)
{
  setbkmode(TRANSPARENT);
  if (color == WHITE)
  {
    settextcolor(color);
  }
  else
  {
    GradientFill(button.X1, button.Y1, button.X2, button.Y2, WHITE, BLACK);
    settextcolor(color);
  }
  LOGFONT f;
  gettextstyle(&f);            // ��ȡ��ǰ��������
  f.lfHeight = button.size;        // ��������߶�Ϊ
  _tcscpy_s(f.lfFaceName, _T("����"));  // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
  f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ����� 
  settextstyle(&f);            // ����������ʽ
  outtextxy(button.X1 + 35, button.Y1 + 15, button.str);
}

int RETURN()
{
  int NUM = 0;
  srand(time(NULL));
  Graph g;
  // ������������������Ϣ
  ExMessage msg;
  BeginBatchDraw();
  bool T = true;
  // ��Ϸ����ѭ��
  while (T)
  {
    FlushBatchDraw();
    cleardevice();
    g.draw();
    DrawButton(button1, WHITE);
    DrawButton(button2, WHITE);
    DrawButton(button3, WHITE);
    DrawKMQY(1700, 690, 400);
    while (peekmessage(&msg, EX_MOUSE))  // �����ȡ������Ϣ��ִ��
    {
      switch (msg.message)
      {
      case WM_MOUSEMOVE:
        if (msg.x > button1.X1 && msg.x<button1.X2 && msg.y>button1.Y1 && msg.y < button1.Y2)
        {
          NUM = 1;
        }
        if (msg.x > button2.X1 && msg.x<button2.X2 && msg.y>button2.Y1 && msg.y < button2.Y2)
        {
          NUM = 2;
        }
        if (msg.x > button3.X1 && msg.x<button3.X2 && msg.y>button3.Y1 && msg.y < button3.Y2)
        {
          NUM = 3;
        }
        break;
      case WM_LBUTTONDOWN:
        if (msg.x > button1.X1 && msg.x<button1.X2 && msg.y>button1.Y1 && msg.y < button1.Y2)
        {
          NUM = 4;
        }
        if (msg.x > button2.X1 && msg.x<button2.X2 && msg.y>button2.Y1 && msg.y < button2.Y2)
        {
          NUM = 5;
        }
        if (msg.x > button3.X1 && msg.x<button3.X2 && msg.y>button3.Y1 && msg.y < button3.Y2)
        {
          NUM = 6;
        }
        break;
      }
    }

    switch (NUM)
    {
    case 0:break;
    case 1:
      DrawButton(button1, BLACK);
      DrawButton(button2, WHITE);
      DrawButton(button3, WHITE);
      break;
    case 2:
      DrawButton(button1, WHITE);
      DrawButton(button2, BLACK);
      DrawButton(button3, WHITE);
      break;
    case 3:
      DrawButton(button1, WHITE);
      DrawButton(button2, WHITE);
      DrawButton(button3, BLACK);
      break;
    case 4:T = false; NUM = 0; break;    // ��ʼ��Ϸ
    case 5:T = false; NUM = 1; break;    // ��Ϸ˵��
    case 6:T = false; NUM = 2; break;    // �˳�
    }
    Sleep(20);
  }
  EndBatchDraw();
  return NUM;
}

void GradientFill(int left, int top, int right, int bottom, COLORREF startColor, COLORREF endColor)
{  // ����ˮƽ�ʹ�ֱ�����ϵ���ɫ�仯��   
  double dx = right - left;
  double dy = bottom - top;
  double redStep = (GetRValue(endColor) - GetRValue(startColor)) / dx;
  double greenStep = (GetGValue(endColor) - GetGValue(startColor)) / dx;
  double blueStep = (GetBValue(endColor) - GetBValue(startColor)) / dx;  // ����ÿ�����ص㣬����������ɫ    
  for (int x = left; x <= right; x++)
  {
    COLORREF currentColor = RGB(GetRValue(startColor) + (x - left) * redStep, GetGValue(startColor) + (x - left) * greenStep, GetBValue(startColor) + (x - left) * blueStep);
    setfillcolor(currentColor);    solidrectangle(x, top, x, bottom); // ��䵱ǰ�е���ɫ   
  }
}

void BeginGame()        // ��ʼ��Ϸ
{
  PegSolitaire game;
  game.playGame();

}
void INstrucTionS()        // ��Ϸ����
{
  Graph g;
  IMAGE img2(rW, rH);
  SetWorkingImage(&img2);
  g.draw();
  DrawButton(button1, WHITE);
  DrawButton(button2, WHITE);
  DrawButton(button3, WHITE);
  DrawKMQY(1700, 690, 400);
  SetWorkingImage();

  if (!WINDOWS(_T("��ϸ�淨����΢�Ź��ںţ�C�����о�"), img2, _T("ȷ��"), _T("����")))
  {
    system("start https://mp.weixin.qq.com/s/5Nj-Que4TVK0LWi44alrFg");
  }

}
bool EXIT()            // �˳�
{
  Graph g;
  IMAGE img2(rW, rH);
  SetWorkingImage(&img2);
  g.draw();
  DrawButton(button1, WHITE);
  DrawButton(button2, WHITE);
  DrawButton(button3, WHITE);
  DrawKMQY(1700, 690, 400);
  SetWorkingImage();
  return  WINDOWS(_T("ȷ���˳���������"), img2, _T("ȷ��"), _T("ȡ��"));
}

void DrawCircle(TCHAR str[25], int variable, int fors, int R, double Radian, int Mx, int My)
{
  settextcolor(variable ? HSLtoRGB((360.f / fors) * variable, 1, 0.5f) : WHITE);
  double a, x0, y0, w, h, x1, y1;
  int x, y;
  settextstyle(22, 0, reinterpret_cast<LPCTSTR>("΢���ź�"), variable * 3600 / fors, variable * 3600 / fors, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);

  a = (fors == 60) ? ((variable + 1) * PI * 2 / fors - Radian) : (variable * PI * 2 / fors);  // �����ַ������� a

  w = textwidth(str);                                      // �����ַ����� w���� h
  h = textheight(str);

  x1 = R * cos(a);                                      // ��������ַ��������Ͻ�λ��
  y1 = R * sin(a);

  x0 = x1 * cos(-a) - y1 * sin(-a);                              // ���ַ�����ԭ��˳ʱ����ת a ����
  y0 = y1 * cos(-a) + x1 * sin(-a);

  x0 -= w / 2;                                        // ���ַ���������ƫ�� w/2��h/2
  y0 += h / 2;                                        // ��ͼ��������Ϊ��

  x = (int)(x0 * cos(a) - y0 * sin(a));                            // ���ַ�����ԭ����ʱ����ת a ����
  y = (int)(y0 * cos(a) + x0 * sin(a));

  outtextxy(int(Mx + x + 0.5), int(My - y + 0.5), str);                    // ��ͼ��������Ϊ��
}

void INITCircle()
{
  for (int i = 0; i < 3; i++)
  {
    TC[i].R = (i + 1) * 50 + rH / 2 - 200;
    TC[i].Radian = 0;
    TC[i].NextTime = 0;

    switch (i)
    {
    case 0:TC[i].fors = 24; break;              // ʱ
    case 1:TC[i].fors = 60; break;              // ��
    case 2:TC[i].fors = 60; break;              // ��
    }
  }
}

void MYCIRCLE(int x, int y)
{
  GetLocalTime(&ti);
  for (int j = 0; j < 3; j++)
  {
    if (TC[1].NextTime != ti.wMinute)
    {
      TC[1].NextTime = ti.wMinute;
      TC[1].Radian = 0;
    }
    else
    {
      TC[1].Radian = TC[1].Radian + (2 * PI / TC[1].fors - TC[1].Radian) / 10;
    }

    if (TC[2].NextTime != ti.wSecond)
    {
      TC[2].NextTime = ti.wSecond;
      TC[2].Radian = 0;
    }
    else
    {
      TC[2].Radian = TC[2].Radian + (2 * PI / TC[2].fors - TC[2].Radian) / 10;
    }

    for (int i = 0; i < TC[j].fors; i++)
    {
      switch (j)
      {
      case 0: _stprintf_s(str, _T("%dʱ"), (i + ti.wHour) % TC[j].fors); break;
      case 1: _stprintf_s(str, _T("%d��"), (i + ti.wMinute) % TC[j].fors); break;
      case 2: _stprintf_s(str, _T("%d��"), (i + ti.wSecond) % TC[j].fors); break;
      }
      DrawCircle(str, i, TC[j].fors, TC[j].R, TC[j].Radian, x, y);;
    }
  }
  settextstyle(22, 0, reinterpret_cast<LPCTSTR>("΢���ź�"), 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
}

void HideSphere(float R, int alfa, int beta, int HideFlag, int X, int Y, COLORREF color)
{
  setlinecolor(color);
  int i, j, k;
  float x[4], y[4], z[4], x1[4], y1[4], z1[4], sx[4], sy[4];
  double a1, a2, b1, b2, c, d, xn, yn, zn, vn;
  c = alfa * PI / 180.0;
  d = beta * PI / 180.0;
  for (j = 0; j < 180; j = j + 20)
  {
    a1 = j * PI / 180.0;
    a2 = (j + 20) * PI / 180.0;
    for (i = 0; i < 360; i = i + 20)
    {
      b1 = i * PI / 180.0;
      b2 = (i + 20) * PI / 180.0;
      x[0] = R * sin(a1) * cos(b1); y[0] = R * sin(a1) * sin(b1); z[0] = R * cos(a1);
      x[1] = R * sin(a2) * cos(b1); y[1] = R * sin(a2) * sin(b1); z[1] = R * cos(a2);
      x[2] = R * sin(a2) * cos(b2); y[2] = R * sin(a2) * sin(b2); z[2] = R * cos(a2);
      x[3] = R * sin(a1) * cos(b2); y[3] = R * sin(a1) * sin(b2); z[3] = R * cos(a1);
      for (k = 0; k < 4; k++)
      {
        x1[k] = x[k] * cos(c) - y[k] * sin(c);
        y1[k] = x[k] * sin(c) * cos(d) + y[k] * cos(c) * sin(d) + z[k] * sin(d);
        z1[k] = -x[k] * sin(c) * sin(d) - y[k] * cos(c) * sin(d) + z[k] * cos(d);
        sx[k] = X - x1[k];
        sy[k] = Y - z1[k];
      }
      xn = (y1[2] - y1[0]) * (z1[3] - z1[1]) - (y1[3] - y1[1]) * (z1[2] - z1[0]);
      yn = -(x1[2] - x1[0]) * (z1[3] - z1[1]) + (x1[3] - x1[1]) * (z1[2] - z1[0]);
      zn = (x1[2] - x1[0]) * (y1[3] - y1[1]) - (x1[3] - x1[1]) * (y1[2] - y1[0]);
      vn = sqrt(xn * xn + yn * yn + zn * zn);
      xn = xn / vn;
      yn = yn / vn;
      zn = zn / vn;
      if (!HideFlag || yn >= 0.0)
      {
        moveto(sx[0], sy[0]);
        lineto(sx[1], sy[1]);
        lineto(sx[2], sy[2]);
        lineto(sx[3], sy[3]);
        lineto(sx[0], sy[0]);
      }
    }
  }
}

// ��ͼƬ����ģ������
void Blur(IMAGE* pimg)
{
  DWORD* pMem = GetImageBuffer(pimg);

  int  r, g, b;
  int m;
  int  num = 0;
  int  width = pimg->getwidth();
  int  height = pimg->getheight();
  int step = width - 1, f, t;


  // ���� 9 ����ϵ��
  int  cell[9] = { -(width + 1), -1, width - 1, -width, 0, width, -(width - 1), 1,  width + 1 };

  // ������ص��ȡ����
  for (int i = width * height - 1; i >= 0; i--)
  {
    // ���ñ���
    r = g = b = 0;
    m = 9;

    // ��������λ�ã�������Χ���ӵļ��㷶Χ
    if (step == width - 1)
      t = 5, m = 6;
    else
      t = 8;

    if (step == 0)
      f = 3, m = 6, step = width;
    else
      f = 0;

    step--;

    // �ۼ���Χ���ӵ���ɫֵ
    for (int n = f; n <= t; n++)
    {
      // λ�ö�λ
      num = i + cell[n];

      // �ж�λ��ֵ�Ƿ�Խ��
      if (num < 0 || num >= width * height)
        m--;            // ͳ��Խ��������
      else
      {
        // �ۼ���ɫֵ
        r += GetRValue(pMem[num]);
        g += GetGValue(pMem[num]);
        b += GetBValue(pMem[num]);
      }
    }
    // ��ƽ��ֵ��ֵ������
    pMem[i] = RGB(r / m, g / m, b / m);
  }
}

void DrawButtonT(Button button, COLORREF color)
{
  setbkmode(TRANSPARENT);
  RECT r = { button.X1, button.Y1, button.X2, button.Y2 };
  if (color == WHITE)
  {
    settextcolor(color);
    setfillcolor(RGB(30, 30, 30));
    setlinecolor(RGB(20, 20, 20));
    fillrectangle(button.X1, button.Y1, button.X2, button.Y2);
  }
  else
  {
    GradientFill(button.X1, button.Y1, button.X2, button.Y2, WHITE, BLACK);
    settextcolor(color);
  }

  LOGFONT f;
  gettextstyle(&f);            // ��ȡ��ǰ��������
  f.lfHeight = button.size;        // ��������߶�Ϊ
  _tcscpy_s(f.lfFaceName, _T("����"));  // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
  f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ����� 
  settextstyle(&f);            // ����������ʽ
  drawtext(button.str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void DrawMouse(int x, int y)            // ������갴��
{
  setfillcolor(RGB(107, 107, 107));
  solidellipse(x, y, x + 30, y + 40);
  setfillcolor(RGB(17, 17, 17));
  // ����
  solidpie(x + 1, y + 1, x + 30 - 1, y + 40 - 1, 0, 1.57);
  settextcolor(RGB(107, 107, 107));
  LOGFONT f;
  gettextstyle(&f);            // ��ȡ��ǰ��������
  f.lfHeight = 40;            // ��������߶�Ϊ
  _tcscpy_s(f.lfFaceName, _T("����"));  // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
  f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ����� 
  settextstyle(&f);            // ����������ʽ
  outtextxy(x + 45, y, _T("�˳�"));
}

void DrawR(int x, int y)            // ���Ƴ���
{
  setfillcolor(RGB(107, 107, 107));
  solidroundrect(x + 5, y + 5, x + 35, y + 35, 5, 5);
  settextcolor(RGB(17, 17, 17));
  settextstyle(30, 0, _T("����"));
  RECT r = { x, y, x + 40, y + 40 };
  drawtext(_T("R"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
  settextcolor(RGB(107, 107, 107));
  LOGFONT f;
  gettextstyle(&f);            // ��ȡ��ǰ��������
  f.lfHeight = 40;            // ��������߶�Ϊ
  _tcscpy_s(f.lfFaceName, _T("����"));  // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
  f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ����� 
  settextstyle(&f);            // ����������ʽ
  outtextxy(x + 45, y, _T("����"));
}

bool WINDOWS(LPCTSTR str, IMAGE img, LPCTSTR str1, LPCTSTR str2)
{
  for (int m = 0; m < 10; m++)
  {
    Blur(&img);
    // ��ʾ������ͼ��
  }
  // ���ƴ��ڰ�ť�ȣ���ʼѡ��
  setfillcolor(RGB(20, 20, 20));
  solidrectangle(744, 535, 1810, 815);

  LOGFONT f;
  gettextstyle(&f);            // ��ȡ��ǰ��������
  f.lfHeight = 40;            // ��������߶�Ϊ
  _tcscpy_s(f.lfFaceName, _T("����"));  // ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
  f.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ����� 
  settextstyle(&f);            // ����������ʽ
  RECT r = { 744,535,1810,815 };
  drawtext(str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
  Button button4 = { 744, 815, 744 + 533, 815 + 65, 40, str1 };
  Button button5 = { 744 + 533, 815, 1810,815 + 65, 40,str2 };
  DrawButtonT(button4, WHITE);
  DrawButtonT(button5, WHITE);
  ExMessage msg;
  BeginBatchDraw();
  bool T = true;
  bool R = true;
  int NUMS = 0;
  // ��Ϸ����ѭ��
  while (T)
  {
    FlushBatchDraw();
    cleardevice();
    putimage(0, 0, &img);
    setfillcolor(RGB(20, 20, 20));
    solidrectangle(744, 535, 1810, 815);
    drawtext(str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    DrawButtonT(button4, WHITE);
    DrawButtonT(button5, WHITE);
    while (peekmessage(&msg, EX_MOUSE))  // �����ȡ������Ϣ��ִ��
    {
      switch (msg.message)
      {
      case WM_MOUSEMOVE:
        if (msg.x > button4.X1 && msg.x<button4.X2 && msg.y>button4.Y1 && msg.y < button4.Y2)
        {
          NUMS = 1;
        }
        if (msg.x > button5.X1 && msg.x<button5.X2 && msg.y>button5.Y1 && msg.y < button5.Y2)
        {
          NUMS = 2;
        }
        break;
      case WM_LBUTTONDOWN:
        if (msg.x > button4.X1 && msg.x<button4.X2 && msg.y>button4.Y1 && msg.y < button4.Y2)
        {
          NUMS = 3;
        }
        if (msg.x > button5.X1 && msg.x<button5.X2 && msg.y>button5.Y1 && msg.y < button5.Y2)
        {
          NUMS = 4;
        }
        break;
      }
    }

    switch (NUMS)
    {
    case 0:break;
    case 1:
      DrawButtonT(button4, BLACK);
      DrawButtonT(button5, WHITE);
      break;
    case 2:
      DrawButtonT(button5, BLACK);
      DrawButtonT(button4, WHITE);
      break;
    case 3:
      T = false;
      R = false;  // ȷ���˳�
      break;
    case 4:
      T = false;
      R = true;
      break;    // ��ʼ��Ϸ
    }
    Sleep(20);
  }
  EndBatchDraw();
  return R;
}