
///////////////////////////////////////////////////
// 程序名称：黑神话 孔明棋
// 编译环境：Mictosoft Visual Studio 2022, EasyX_20200315(beta)
// 作　　者：luoyh <2864292458@qq.com>
// 公 众 号：C语言研究
// 版 本 号：Version 1.0.0
// 最后修改：2024-11-18
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

// #define UNICODE  // 支持后面的L"微软雅黑"

#define PI acos(-1.0)

struct Button
{
  int X1;        // 左上角
  int Y1;
  int X2;        // 右下角
  int Y2;
  int size;      // 字体大小
  LPCTSTR str;    // 对应文本
};

Button button1 = { 90, 635, 605, 700, 40, TEXT("开始游戏") };
Button button2 = { 90, 700 + 10, 605, 765 + 10, 40, TEXT("游戏说明") };
Button button3 = { 90, 765 + 20, 605, 830 + 20, 40, TEXT("退出") };
bool WINDOWS(LPCTSTR str, IMAGE img, LPCTSTR str1, LPCTSTR str2);

void DrawButton(Button button, COLORREF color);
void DrawButtonT(Button button, COLORREF color);
void GradientFill(int left, int top, int right, int bottom, COLORREF startColor, COLORREF endColor);
int RETURN();
void HideSphere(float R, int alfa, int beta, int HideFlag, int X, int Y, COLORREF endColor);
// 设置分辨率为2560*1440（推荐）
int rW = GetSystemMetrics(SM_CXSCREEN); // 屏幕宽度 像素
int rH = GetSystemMetrics(SM_CYSCREEN); // 屏幕高度 像素
// 全屏
void Full_Screen();    // 全屏
void DrawTXT();      // 绘制
void BianAN();      // 变暗淡
void DrawLoge(int x, int y, int size, COLORREF color);
void DrawInit();    // 绘制初始界面
void DrawKMQY(int x, int y, int size);    // 绘制孔明棋
void BianLIANG();    // 变亮
void CheckForInput();
bool gameShouldContinue = false;
IMAGE img(rW, rH);
IMAGE img1(rW, rH);
// 将图片进行模糊处理
void Blur(IMAGE* pimg);
void INITCircle();
void MYCIRCLE(int x, int y);
// str代表绘制的字符串
// variable 代表每次的变量
// fors 每次需要循环的次数总数
// R 该圈的半径
// Radian 累加的弧度
void DrawCircle(TCHAR str[25], int variable, int fors, int R, double Radian, int x, int y);    // 绘制一圈字符    
void DrawMouse(int x, int y);            // 绘制鼠标按键
void DrawR(int x, int y);              // 绘制撤销
void BeginGame();        // 开始游戏
void INstrucTionS();      // 游戏介绍
bool EXIT();          // 退出
// 一个圈的结构体
struct TimeCircle
{
  int fors;                      // 每一圈分成的份数
  int R;                        // 圈的半径
  double NextTime;                  // 上一个时刻时间
  double Radian;                    // 累加的弧度
};
SYSTEMTIME ti;
TimeCircle TC[3];
TCHAR str[25];

// 设置随机数产生方法  
int getRandom(int min, int max)
{
  return rand() % (max - min + 1) + min;
}

// Point类  
class Point
{
public:
  int x, y;
  int xSpeed, ySpeed;
  int r;

  Point()
  {
    r = 3; // 点的半径  
    x = getRandom(0, getwidth() - r);
    y = getRandom(0, getheight() - r);
    xSpeed = getRandom(-3, 3);
    ySpeed = getRandom(-3, 3);
  }

  void draw()
{
    // 更新坐标  
    x += xSpeed;
    y += ySpeed;

    // 超出边界回弹  
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

    // 绘制点  
    setfillcolor(RGB(200, 200, 200));
    solidcircle(x, y, r);
  }
};

// Graph类  
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
          int NUM = 255 - static_cast<int>(distance * 255.0 / maxDis); // 确保NUM是整数  
          int offset = 50;
          setlinecolor(RGB(NUM + offset, NUM + offset, NUM + offset)); // 当NUM接近0时，颜色接近黑色；当NUM接近255时，颜色接近白色 
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
    settextstyle(60, 0, reinterpret_cast<LPCTSTR>("微软雅黑"), 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
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

        // 设置绘图目标为 img 对象
        SetWorkingImage(&Mimg);
        // 以下绘图操作都会绘制在 img 对象上面
        g.draw();
        drawBoard(y, x); // 每次操作后重绘棋盘
        MYCIRCLE(rW / 2, rH / 2);
        DrawMouse(2300, 1360);
        DrawR(2120, 1360);
        // 设置绘图目标为绘图窗口
        SetWorkingImage();
        if (!WINDOWS(_T("恭喜你!挑战成功"), Mimg, _T("再来一局"), _T("退出")))
        {
          BeginGame();
        }
        break;
      }

      // 获取坐标两次
      // 第一次获取起始位置
      // 第二次获取终止位置 计算方向
      //ExMessage m;    // 定义消息变量

      while (peekmessage(&msg, EX_MOUSE | EX_KEY))  // 如果获取到了消息就执行
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
        //undoMove();  一个撤销功能
        case WM_KEYDOWN:
          if (msg.vkcode == 0x52)
          {
              undoMove();
          }
          break;
        }
      }

      /*  cout << "请输入 x, y, 方向 (0=北, 1=南, 2=西, 3=东): ";*/

      if (DJNUM == 1)        // 按下第一次
      {
        y = (Mx - (rW / 2 - 420)) / 120;
        x = (My - (rH / 2 - 420)) / 120;     // 获取起始位置
      }
      if (DJNUM == 2)        // 按下第二次 获取方向
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
        if (dir == -1)  // 乱点击的情况
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
          /*cout << "非法移动！" << endl;*/
        }
      }
      FlushBatchDraw();
      cleardevice();
      g.draw();
      drawBoard(y, x); // 每次操作后重绘棋盘
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
      _stprintf_s(s, _T("挑战失败，还剩余%d枚棋子！"), pegCount);
      IMAGE Mimg(rW, rH);

      // 设置绘图目标为 img 对象
      SetWorkingImage(&Mimg);
      // 以下绘图操作都会绘制在 img 对象上面
      g.draw();
      drawBoard(y, x); // 每次操作后重绘棋盘
      MYCIRCLE(rW / 2, rH / 2);
      DrawMouse(2300, 1360);
      DrawR(2120, 1360);
      // 设置绘图目标为绘图窗口
      SetWorkingImage();
      if (!WINDOWS(s, Mimg, _T("再来一局"), _T("退出")))
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
  // 变亮度 显示 孔明棋
  DrawInit();
  BianLIANG();
  CheckForInput();
  // 按任意键继续，不管是键盘还是鼠标。都继续
  // 开始写按钮
  cleardevice();
  bool CTN = true;
  // 字体角度问题处理一下
  while (CTN)
  {
    int NUM = RETURN();        // 鼠标操作
    switch (NUM)
    {
    case 0:BeginGame(); break;
    case 1:INstrucTionS(); break;
    case 2:CTN = EXIT(); break;
    }
  }
}

void Full_Screen()    // 全屏
{
  HWND hwnd = initgraph(rW, rH);      // 初始化绘图窗口并获取窗口句柄（以 EasyX 为例）
  LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE); // 获取窗口信息
  // 设置窗口信息 最大化 取消标题栏及边框
  SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);// 直接修改窗口样式
  SetWindowPos(hwnd, HWND_TOP, 0, 0, rW, rH, 0);
  setbkcolor(BLACK);
  cleardevice();      // 设置背景颜色为黑色
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

  // 设置输出效果为抗锯齿 (VC6 / VC2008 / VC2010 / VC2012)
  LOGFONT f;
  gettextstyle(&f);            // 获取当前字体设置
  f.lfHeight = 80;            // 设置字体高度为
  _tcscpy_s(f.lfFaceName, _T("等线"));  // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
  f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿 
  settextstyle(&f);            // 设置字体样式
  drawtext(_T("C语言研究"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
  f.lfHeight = 45;            // 设置字体高度为
  settextstyle(&f);            // 设置字体样式
  r = { 1188,743,1480 + 60,776 };
  drawtext(_T("C YUYAN YANJIU"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
  Sleep(1000);
  SetWorkingImage();
}

void BianAN()    // 变暗淡
{
  // 获取绘图窗口和 img 对象的显示缓冲区指针
  DWORD* pbWnd = GetImageBuffer();
  DWORD* pbImg = GetImageBuffer(&img);

  // 计算原图片每个点的颜色，实现逐渐变量的效果
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
  // 设置输出效果为抗锯齿 (VC6 / VC2008 / VC2010 / VC2012)
  LOGFONT f;
  gettextstyle(&f);            // 获取当前字体设置
  f.lfHeight = 300;            // 设置字体高度为
  _tcscpy_s(f.lfFaceName, _T("方正舒体"));  // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
  f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿 
  settextstyle(&f);            // 设置字体样式
  outtextxy(300, 400, _T("孔"));
  outtextxy(500, 540, _T("明"));
  outtextxy(700, 680, _T("棋"));
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

  // 设置输出效果为抗锯齿 (VC6 / VC2008 / VC2010 / VC2012)
  LOGFONT f;
  gettextstyle(&f);              // 获取当前字体设置
  f.lfQuality = ANTIALIASED_QUALITY;      // 设置输出效果为抗锯齿 
  f.lfHeight = 25;              // 设置字体高度为
  _tcscpy_s(f.lfFaceName, _T("楷体"));    // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
  settextcolor(RGB(120,120,120));
  settextstyle(&f);
  outtextxy(116, 1356, _T("? [2024] [微信公众号：C语言研究]. All rights reserved."));

  outtextxy(2200, 1335, _T("Version 1.0.0"));

}

void BianLIANG()    // 变亮
{
  // 获取绘图窗口和 img 对象的显示缓冲区指针
  DWORD* pbWnd = GetImageBuffer();
  DWORD* pbImg = GetImageBuffer(&img1);

  // 计算原图片每个点的颜色，实现逐渐变量的效果
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
  // 设置输出效果为抗锯齿 (VC6 / VC2008 / VC2010 / VC2012)
  LOGFONT f;
  gettextstyle(&f);              // 获取当前字体设置
  f.lfQuality = ANTIALIASED_QUALITY;      // 设置输出效果为抗锯齿 
  f.lfHeight = 30;              // 设置字体高度为
  _tcscpy_s(f.lfFaceName, _T("楷体"));    // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
  settextcolor(GREEN);
  settextstyle(&f);
  outtextxy(500, 1000, _T("按任意键开始"));
}

void CheckForInput()
{
  ExMessage msg;

  // 游戏的主循环
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
      return; // 退出函数
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
  gettextstyle(&f);            // 获取当前字体设置
  f.lfHeight = button.size;        // 设置字体高度为
  _tcscpy_s(f.lfFaceName, _T("楷体"));  // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
  f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿 
  settextstyle(&f);            // 设置字体样式
  outtextxy(button.X1 + 35, button.Y1 + 15, button.str);
}

int RETURN()
{
  int NUM = 0;
  srand(time(NULL));
  Graph g;
  // 定义变量，保存鼠标消息
  ExMessage msg;
  BeginBatchDraw();
  bool T = true;
  // 游戏的主循环
  while (T)
  {
    FlushBatchDraw();
    cleardevice();
    g.draw();
    DrawButton(button1, WHITE);
    DrawButton(button2, WHITE);
    DrawButton(button3, WHITE);
    DrawKMQY(1700, 690, 400);
    while (peekmessage(&msg, EX_MOUSE))  // 如果获取到了消息就执行
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
    case 4:T = false; NUM = 0; break;    // 开始游戏
    case 5:T = false; NUM = 1; break;    // 游戏说明
    case 6:T = false; NUM = 2; break;    // 退出
    }
    Sleep(20);
  }
  EndBatchDraw();
  return NUM;
}

void GradientFill(int left, int top, int right, int bottom, COLORREF startColor, COLORREF endColor)
{  // 计算水平和垂直方向上的颜色变化量   
  double dx = right - left;
  double dy = bottom - top;
  double redStep = (GetRValue(endColor) - GetRValue(startColor)) / dx;
  double greenStep = (GetGValue(endColor) - GetGValue(startColor)) / dx;
  double blueStep = (GetBValue(endColor) - GetBValue(startColor)) / dx;  // 遍历每个像素点，并设置其颜色    
  for (int x = left; x <= right; x++)
  {
    COLORREF currentColor = RGB(GetRValue(startColor) + (x - left) * redStep, GetGValue(startColor) + (x - left) * greenStep, GetBValue(startColor) + (x - left) * blueStep);
    setfillcolor(currentColor);    solidrectangle(x, top, x, bottom); // 填充当前列的颜色   
  }
}

void BeginGame()        // 开始游戏
{
  PegSolitaire game;
  game.playGame();

}
void INstrucTionS()        // 游戏介绍
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

  if (!WINDOWS(_T("详细玩法，见微信公众号：C语言研究"), img2, _T("确定"), _T("返回")))
  {
    system("start https://mp.weixin.qq.com/s/5Nj-Que4TVK0LWi44alrFg");
  }

}
bool EXIT()            // 退出
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
  return  WINDOWS(_T("确定退出至桌面吗？"), img2, _T("确定"), _T("取消"));
}

void DrawCircle(TCHAR str[25], int variable, int fors, int R, double Radian, int Mx, int My)
{
  settextcolor(variable ? HSLtoRGB((360.f / fors) * variable, 1, 0.5f) : WHITE);
  double a, x0, y0, w, h, x1, y1;
  int x, y;
  settextstyle(22, 0, reinterpret_cast<LPCTSTR>("微软雅黑"), variable * 3600 / fors, variable * 3600 / fors, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);

  a = (fors == 60) ? ((variable + 1) * PI * 2 / fors - Radian) : (variable * PI * 2 / fors);  // 计算字符串弧度 a

  w = textwidth(str);                                      // 计算字符串宽 w、高 h
  h = textheight(str);

  x1 = R * cos(a);                                      // 计算输出字符串的左上角位置
  y1 = R * sin(a);

  x0 = x1 * cos(-a) - y1 * sin(-a);                              // 将字符串绕原点顺时针旋转 a 弧度
  y0 = y1 * cos(-a) + x1 * sin(-a);

  x0 -= w / 2;                                        // 将字符串向左上偏移 w/2、h/2
  y0 += h / 2;                                        // 绘图坐标向下为正

  x = (int)(x0 * cos(a) - y0 * sin(a));                            // 将字符串绕原点逆时针旋转 a 弧度
  y = (int)(y0 * cos(a) + x0 * sin(a));

  outtextxy(int(Mx + x + 0.5), int(My - y + 0.5), str);                    // 绘图坐标向下为正
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
    case 0:TC[i].fors = 24; break;              // 时
    case 1:TC[i].fors = 60; break;              // 分
    case 2:TC[i].fors = 60; break;              // 秒
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
      case 0: _stprintf_s(str, _T("%d时"), (i + ti.wHour) % TC[j].fors); break;
      case 1: _stprintf_s(str, _T("%d分"), (i + ti.wMinute) % TC[j].fors); break;
      case 2: _stprintf_s(str, _T("%d秒"), (i + ti.wSecond) % TC[j].fors); break;
      }
      DrawCircle(str, i, TC[j].fors, TC[j].R, TC[j].Radian, x, y);;
    }
  }
  settextstyle(22, 0, reinterpret_cast<LPCTSTR>("微软雅黑"), 0, 0, 0, false, false, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH);
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

// 将图片进行模糊处理
void Blur(IMAGE* pimg)
{
  DWORD* pMem = GetImageBuffer(pimg);

  int  r, g, b;
  int m;
  int  num = 0;
  int  width = pimg->getwidth();
  int  height = pimg->getheight();
  int step = width - 1, f, t;


  // 计算 9 格方向系数
  int  cell[9] = { -(width + 1), -1, width - 1, -width, 0, width, -(width - 1), 1,  width + 1 };

  // 逐个像素点读取计算
  for (int i = width * height - 1; i >= 0; i--)
  {
    // 重置变量
    r = g = b = 0;
    m = 9;

    // 根据像素位置，决定周围格子的计算范围
    if (step == width - 1)
      t = 5, m = 6;
    else
      t = 8;

    if (step == 0)
      f = 3, m = 6, step = width;
    else
      f = 0;

    step--;

    // 累加周围格子的颜色值
    for (int n = f; n <= t; n++)
    {
      // 位置定位
      num = i + cell[n];

      // 判断位置值是否越界
      if (num < 0 || num >= width * height)
        m--;            // 统计越界像素数
      else
      {
        // 累加颜色值
        r += GetRValue(pMem[num]);
        g += GetGValue(pMem[num]);
        b += GetBValue(pMem[num]);
      }
    }
    // 将平均值赋值该像素
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
  gettextstyle(&f);            // 获取当前字体设置
  f.lfHeight = button.size;        // 设置字体高度为
  _tcscpy_s(f.lfFaceName, _T("楷体"));  // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
  f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿 
  settextstyle(&f);            // 设置字体样式
  drawtext(button.str, &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void DrawMouse(int x, int y)            // 绘制鼠标按键
{
  setfillcolor(RGB(107, 107, 107));
  solidellipse(x, y, x + 30, y + 40);
  setfillcolor(RGB(17, 17, 17));
  // 扇形
  solidpie(x + 1, y + 1, x + 30 - 1, y + 40 - 1, 0, 1.57);
  settextcolor(RGB(107, 107, 107));
  LOGFONT f;
  gettextstyle(&f);            // 获取当前字体设置
  f.lfHeight = 40;            // 设置字体高度为
  _tcscpy_s(f.lfFaceName, _T("楷体"));  // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
  f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿 
  settextstyle(&f);            // 设置字体样式
  outtextxy(x + 45, y, _T("退出"));
}

void DrawR(int x, int y)            // 绘制撤销
{
  setfillcolor(RGB(107, 107, 107));
  solidroundrect(x + 5, y + 5, x + 35, y + 35, 5, 5);
  settextcolor(RGB(17, 17, 17));
  settextstyle(30, 0, _T("宋体"));
  RECT r = { x, y, x + 40, y + 40 };
  drawtext(_T("R"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
  settextcolor(RGB(107, 107, 107));
  LOGFONT f;
  gettextstyle(&f);            // 获取当前字体设置
  f.lfHeight = 40;            // 设置字体高度为
  _tcscpy_s(f.lfFaceName, _T("楷体"));  // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
  f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿 
  settextstyle(&f);            // 设置字体样式
  outtextxy(x + 45, y, _T("撤回"));
}

bool WINDOWS(LPCTSTR str, IMAGE img, LPCTSTR str1, LPCTSTR str2)
{
  for (int m = 0; m < 10; m++)
  {
    Blur(&img);
    // 显示处理后的图像
  }
  // 绘制窗口按钮等，开始选择
  setfillcolor(RGB(20, 20, 20));
  solidrectangle(744, 535, 1810, 815);

  LOGFONT f;
  gettextstyle(&f);            // 获取当前字体设置
  f.lfHeight = 40;            // 设置字体高度为
  _tcscpy_s(f.lfFaceName, _T("楷体"));  // 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
  f.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿 
  settextstyle(&f);            // 设置字体样式
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
  // 游戏的主循环
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
    while (peekmessage(&msg, EX_MOUSE))  // 如果获取到了消息就执行
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
      R = false;  // 确定退出
      break;
    case 4:
      T = false;
      R = true;
      break;    // 开始游戏
    }
    Sleep(20);
  }
  EndBatchDraw();
  return R;
}