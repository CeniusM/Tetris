#include "Tetris.h";

Tetris::Tetris(int cols, int rows)
{
	this->rows = rows;
	this->cols = cols;

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
		board[row] = new int[cols];
}

Tetris::~Tetris()
{
}

void Tetris::Update()
{

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
