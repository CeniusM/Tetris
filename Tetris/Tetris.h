#pragma once

class Tetris
{
public:
	Tetris(int width, int height);
	~Tetris();

	void Start();

	void Update();

	void MoveRight();
	void MoveLeft();
	void RotateClockWise();
	void RotateCounterClockWise();
	void Dump();

	int** GetBoard();
	
private:
	int** board;




};