#include <chrono>
#include <thread>
#include <algorithm>

#include "Tetris.h"
#include "TetrisGUI.h"
#include "Game.h"

void GameLoop()
{
	Tetris tetrisGame(gameWidth, gameHeight);
	TetrisGUI gui(tetrisGame.GetBoard(), gameWidth, gameHeight);

	while (true)
	{
		// timer
		auto start = std::chrono::high_resolution_clock::now();


		// player inputs, Check if high-order bit is set (1 << 15)
		if (GetKeyState('A') & 0x8000)
		{
			tetrisGame.MoveLeft();
		}
		if (GetKeyState('D') & 0x8000)
		{
			tetrisGame.MoveRight();
		}
		if (GetKeyState('W') & 0x8000)
		{
			tetrisGame.RotateClockWise();
		}
		if (GetKeyState('S') & 0x8000)
		{
			tetrisGame.RotateCounterClockWise();
		}
		if (GetKeyState(' ') & 0x8000)
		{
			tetrisGame.Dump();
		}

		tetrisGame.Update();
		gui.PrintBoard();

		// timer / game speed, 100 times a second
		auto finish = std::chrono::high_resolution_clock::now();
		auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
		long long mDelay = 10000 - microseconds.count();
		if (mDelay > 0)
			std::this_thread::sleep_for(std::chrono::microseconds(mDelay));
	}
}