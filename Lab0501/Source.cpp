#include<stdio.h>
#include<windows.h>
#include<conio.h>
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{	gotoxy(x, y);setcolor(2, 4); printf("<-0->"); }
void delete_ship(int x,int y)
{	gotoxy(x, y);setcolor(0, 0); printf("      ");}
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
int main()
{
	setcursor(0);
	int x = 38, y = 20;
	draw_ship(x, y);
	char ch = '.';
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') {
				do {
					delete_ship(x, y); draw_ship(--x, y); Sleep(100);
					if (_kbhit()) { ch = _getch(); }
				} while (ch != 's' && x > 0);
			}
			if (ch == 'd')
			{
				do {
					delete_ship(x, y); draw_ship(++x, y); Sleep(100);
					if (_kbhit()) { ch = _getch(); }
				} while (ch != 's' && x < 80);
			}
			fflush(stdin);
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}