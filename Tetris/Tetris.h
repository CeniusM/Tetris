#pragma once

enum class Direction { Down, Right, Left };

class Tetris
{
public:
	/// <summary>
	/// New pieces fall from the top (max row) to the bottom (row = 0).
	/// </summary>
	/// <param name="cols"></param>
	/// <param name="rows"></param>
	Tetris(int cols, int rows);
	~Tetris();

	void Update();

	void MoveRight();
	void MoveLeft();
	void RotateClockWise();
	void RotateCounterClockWise();
	void Dump();

	int** GetBoard();

	/// <summary>
	/// 1 if the game has terminated.
	/// 0 otherwise.
	/// </summary>
	int IsTerminated;
private:
	int rows;
	int cols;
	int** board;
	int currentPiecePosition[2];
	int ticksElapsed;

	void InitializeBoard();
	void AddNewPiece();
	void MovePiece(Direction direction);
	bool IsPositionFree(int cols, int rows);
	void ErasePiece();
	void DrawPiece(int newPosition[2]);
};
