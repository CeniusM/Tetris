#pragma once

#include <Windows.h>

class TetrisGUI
{
public:
	TetrisGUI(int** board, int width, int height);
	~TetrisGUI();

	void PrintBoard();
	void PrintEndScreen();

private:
	void SetConsoleSize(int x, int y, int charWidth, int charHeight);

	int** board;

	int boardWidth;
	int boardHeight;
	int screenWidth;
	int screenHeight;

	wchar_t* screen;
	HANDLE hConsole;
	DWORD dwBytesWritten;
};

/*

gradiants

█ full			= UTF-16 (hex) 0x2588 = alt 219
▓ sort of full	= UTF-16 (hex) 0x2593 = alt 178
▒ half			= UTF-16 (hex) 0x2592 = alt 177
░ low			= UTF-16 (hex) 0x2591 = alt 176

*/

/*

Ideer

to get a 2d grid of the screen you can maby do something like this

wchar_t** arr2d = new wchar_t*[nScreenHeight];
for (int i = 0; i < nScreenHeight; i++)
{
	arr2d[i] = &screen[i * nScreenWidth];
}


// this sould edit, right?
// screen[4 * nScreenHeight + 6 * nScreenWidth] = 'A';

arr2d[4][6] = 'A';

*/