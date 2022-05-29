#include <Windows.h>

#include "TetrisGUI.h"

void TetrisGUI::PrintBoard()
{
	int reverseI = boardHeight - 1;
	for (int i = 0; i < boardHeight; i++)
	{
		for (int j = 0; j < boardWidth; j++)
		{
			if (board[i][j] == 0)
			{
				screen[(j << 1) + reverseI * screenWidth] = ' ';
				screen[(j << 1) + reverseI * screenWidth + 1] = ' ';
			}
			else
			{
				screen[(j << 1) + reverseI * screenWidth] = 0x2588;
				screen[(j << 1) + reverseI * screenWidth + 1] = 0x2588;
			}
		}
		reverseI--;
	}

	// Display Frame
	screen[screenWidth * screenHeight - 1] = '\0';
	WriteConsoleOutputCharacter(hConsole, screen, screenWidth * screenHeight, { 0,0 }, &dwBytesWritten);
}

void TetrisGUI::PrintEndScreen()
{
	for (int i = 0; i < boardHeight; i++)
	{
		for (int j = 0; j < boardWidth; j++)
		{
			if (i == j || j >> 1 == i || i >> 1 == j)
			{
				screen[(j << 1) + i * screenWidth] = 0x2588;
				screen[(j << 1) + i * screenWidth + 1] = 0x2588;
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

	screen = new wchar_t[screenWidth * screenHeight];
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