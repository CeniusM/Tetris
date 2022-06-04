#include "Tetris.h"


Tetris::Tetris(int cols, int rows)
{
	this->rows = rows;
	this->cols = cols;

	points = 0;
	ticksElapsed = 0;
	IsTerminated = 0;
	InitializeBoard();
	AddNewPiece();
}

void Tetris::AddNewPiece()
{
	currentPiecePosition[0] = rows-1;
	currentPiecePosition[1] = (cols-1) / 2;
}

/// <summary>
/// IMPORTANT: Temp solution based on a 2x2 piece!
/// </summary>
bool Tetris::IsPositionFree(int row, int col)
{
	if (col < 0 || col+1 >= cols || row < 2) //  row-1 <= 0
		return false;

	return (board[row][col] != FieldState::Ground
		&& board[row-1][col] != FieldState::Ground
		&& board[row][col+1] != FieldState::Ground
		&& board[row - 1][col + 1] != FieldState::Ground);
}

void Tetris::InitializeBoard()
{
	board = new Field* [rows];
	for (int row = 0; row < rows; row++)
		board[row] = new Field[cols] {}; // Curly brackets to initialize values to 0
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
	}
	else if(direction == Direction::Down)
		SettleAndNewPiece(currentPiecePosition);
}

void Tetris::SettleAndNewPiece(int position[2])
{
	DrawPiece(position, FieldState::Ground);

	// another 2x2 hard code
	CheckAndEraseLine(position[0]);
	CheckAndEraseLine(position[0] - 1);

	AddNewPiece();
	IsTerminated = !IsPositionFree(currentPiecePosition[0], currentPiecePosition[1]);
	if (IsTerminated) return;
	DrawPiece(currentPiecePosition, FieldState::Piece);
}

void Tetris::CheckAndEraseLine(int row)
{
	//check and rmove line
	for (int i = 0; i < cols; i++)
		if (board[row][i] == FieldState::Empty)
			return;
	for (int i = 0; i < cols; i++)
		board[row][i] = FieldState::Empty;

	// move everthing a line down
	for (int i = row; i < rows - 1; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = board[i + 1][j];
		}
	}
	for (int i = 0; i < cols; i++)
		board[rows - 1][i] = 0;
	points += 100;
}

void Tetris::ErasePiece()
{
	int row = currentPiecePosition[0];
	int col = currentPiecePosition[1];

	board[row][col] = (int)FieldState::Empty;
	board[row - 1][col] = (int)FieldState::Empty;
	board[row][col + 1] = (int)FieldState::Empty;
	board[row - 1][col + 1] = (int)FieldState::Empty;
}

void Tetris::DrawPiece(int newPosition[2], int state)
{
	currentPiecePosition[0] = newPosition[0];
	currentPiecePosition[1] = newPosition[1];

	int row = newPosition[0];
	int col = newPosition[1];

	board[row][col] = state;
	board[row - 1][col] = state;
	board[row][col + 1] = state;
	board[row - 1][col + 1] = state;
}

Tetris::~Tetris()
{
}

void Tetris::Update()
{
	if (IsTerminated) return;

	ticksElapsed++;
	if (ticksElapsed % 25 != 0)
	{
		//ticksElapsed = 0;
		return;
	}

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

void Tetris::Down()
{
	MovePiece(Direction::Down);
}

void Tetris::Dump()
{
}

Field** Tetris::GetBoard()
{
	return board;
}
