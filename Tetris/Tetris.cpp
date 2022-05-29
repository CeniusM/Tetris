#include "Tetris.h"


Tetris::Tetris(int cols, int rows)
{
	this->rows = rows;
	this->cols = cols;

	ticksElapsed = 0;
	IsTerminated = 0;
	InitializeBoard();
	AddNewPiece();
}

void Tetris::AddNewPiece()
{
	currentPiecePosition[0] = rows;
	currentPiecePosition[1] = cols / 2;
}

bool Tetris::IsPositionFree(int col, int row)
{
	return (board[row][col] == 0
		&& board[row-1][col] == 0
		&& board[row][col+1] == 0
		&& board[row - 1][col + 1] == 0);
}

void Tetris::InitializeBoard()
{
	board = new int* [rows];
	for (int row = 0; row < rows; row++)
		board[row] = new int[cols] {}; // Curly brackets to initialize values to 0
}

void Tetris::MovePiece(Direction direction)
{
	int newPosition[2]{};
	newPosition[0] = currentPiecePosition[0];
	newPosition[1] = currentPiecePosition[1];

	switch (direction)
	{
		case Direction::Down:
			newPosition[0]--;
			bool canMove = IsPositionFree(newPosition[0], newPosition[1]);
			if (!canMove)
			{
				IsTerminated = true;
				return;
			}
			ErasePiece();
			DrawPiece(newPosition);
	}
}

void Tetris::ErasePiece()
{
	int row = currentPiecePosition[0];
	int col = currentPiecePosition[1];

	board[row][col] = 0;
	board[row - 1][col] = 0;
	board[row][col + 1] = 0;
	board[row - 1][col + 1] = 0;
}

void Tetris::DrawPiece(int newPosition[2])
{
	currentPiecePosition[0] = newPosition[0];
	currentPiecePosition[0] = newPosition[0];

	int row = newPosition[0];
	int col = newPosition[1];

	board[row][col] = 2;
	board[row - 1][col] = 2;
	board[row][col + 1] = 2;
	board[row - 1][col + 1] = 2;
}

Tetris::~Tetris()
{
}

void Tetris::Update()
{
	ticksElapsed++;
	if (ticksElapsed % 100 != 0) return;

	MovePiece(Direction::Down);
}

void Tetris::MoveRight()
{
}

void Tetris::MoveLeft()
{
}

void Tetris::RotateClockWise()
{
}

void Tetris::RotateCounterClockWise()
{
}

void Tetris::Dump()
{
}

int** Tetris::GetBoard()
{
	return board;
}
