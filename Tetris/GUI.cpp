#include <Windows.h>

#include "GUI.h"


void TetrisGUI::PrintBoard()
{
	for (int i = 0; i < boardWidth; i++)
	{
		for (int j = 0; j < boardHeight; j++)
		{
			if (board[i][j] == 0)
			{
				screen[i + j * boardWidth] = ' ';
				screen[i + j * boardWidth + 1] = ' ';
			}
			else
			{
				screen[i + j * boardWidth] = 0x2588;
				screen[i + j * boardWidth + 1] = 0x2588;
			}
		}
	}
}

void TetrisGUI::SetConsoleSize(int x, int y, int charWidth, int charHeight)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, x * charWidth + 40/*why i need +40, no clue*/, y * charHeight + 40, TRUE);
}

TetrisGUI::TetrisGUI(int** board, int width, int height)
{
	this->board = board;

	boardWidth = width;
	boardHeight = height;
	screenWidth = width * 2; // each square is 2 wide
	screenHeight = height;

	wchar_t* screen = new wchar_t[screenWidth * screenHeight];
	for (int i = 0; i < screenWidth; i++)
	{
		for (int j = 0; j < screenHeight; j++)
		{
			screen[i + j * screenWidth] = ' ';
		}
	}
	hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	dwBytesWritten = 0;

	SetConsoleSize(screenWidth, screenHeight, 8, 16);
}

TetrisGUI::~TetrisGUI()
{

}
