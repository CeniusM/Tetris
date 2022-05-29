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
	if (col < 0 || col+1 >= cols || row-1 < 0)
		return false;

	return (board[row][col] != 1
		&& board[row-1][col] != 1
		&& board[row][col+1] != 1
		&& board[row - 1][col + 1] != 1);
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
			break;
		case Direction::Left:
			newPosition[1]--;
			break;
		case Direction::Right:
			newPosition[1]++;
			break;
	}

	bool canMove = IsPositionFree(newPosition[0], newPosition[1]);
	if (canMove)
	{
		ErasePiece();
		DrawPiece(newPosition, FieldState::Piece);
		return;
	}

	SettleAndNewPiece(newPosition);
}

void Tetris::SettleAndNewPiece(int position[2])
{
	DrawPiece(position, FieldState::Ground);
	AddNewPiece();
	IsTerminated = !IsPositionFree(currentPiecePosition[0], currentPiecePosition[1]);
	if (IsTerminated) return;
	DrawPiece(currentPiecePosition, FieldState::Piece);
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

void Tetris::DrawPiece(int newPosition[2], FieldState state)
{
	currentPiecePosition[0] = newPosition[0];
	currentPiecePosition[0] = newPosition[0];

	int row = newPosition[0];
	int col = newPosition[1];

	board[row][col] = (int)state;
	board[row - 1][col] = (int)state;
	board[row][col + 1] = (int)state;
	board[row - 1][col + 1] = (int)state;
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
	MovePiece(Direction::Right);
}

void Tetris::MoveLeft()
{
	MovePiece(Direction::Left);
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
