#include <Windows.h>

#include "TetrisGUI.h"
#include "GameSettings.h"

void TetrisGUI::DrawSquare(int x, int y, wchar_t c)
{
	for (int i = 0; i < GameSettings::peiceHeight; i++) // height
	{
		for (int j = 0; j < GameSettings::peiceWidth; j++) // width
		{
			screen[x + j + (y+i) * screenWidth] = c;
		}
	}
};

void TetrisGUI::PrintBoard()
{
	int reverseI = boardHeight - 1;
	for (int i = 0; i < boardHeight; i++)
	{
		for (int j = 0; j < boardWidth; j++)
		{
			DrawSquare(j * GameSettings::peiceWidth, i * GameSettings::peiceHeight, board[reverseI][j] == 0 ? ' ' : 0x2588);
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
			else
			{
				screen[(j << 1) + i * screenWidth] = 'X';
				screen[(j << 1) + i * screenWidth + 1] = 'X';
			}
		}
	}
}

void TetrisGUI::SetConsoleSize(int x, int y, int charWidth, int charHeight)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, x * charWidth + GameSettings::plusSomethingDumb/*why i need +40 ish, no clue*/, y * charHeight + GameSettings::plusSomethingDumb, TRUE);
}

TetrisGUI::TetrisGUI(Field** board, int width, int height)
{
	this->board = board;

	boardWidth = width;
	boardHeight = height;
	screenWidth = width * GameSettings::peiceWidth; // each square is 4 wide
	screenHeight = height * GameSettings::peiceHeight; // each square is 2 heigh

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