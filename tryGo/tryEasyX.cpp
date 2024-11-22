/*
 * @Author: LetMeFly
 * @Date: 2024-11-20 10:22:49
 * @LastEditors: LetMeFly.xyz
 * @LastEditTime: 2024-11-20 10:23:03
 */
#include <Let/graphics.h>
#include <conio.h>
 
int main()
{
	initgraph(640, 480);
	circle(320, 240, 100);
	getch();
	closegraph();
	return 0;
}