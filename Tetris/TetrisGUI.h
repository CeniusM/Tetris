#pragma once

#include <Windows.h>

class TetrisGUI
{
public:
	TetrisGUI(int** board, int width, int height);
	~TetrisGUI();

	void PrintBoard();

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