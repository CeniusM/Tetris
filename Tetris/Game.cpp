#include <chrono>
#include <thread>
#include <algorithm>

#include "Tetris.h"
#include "TetrisGUI.h"
#include "Game.h"
#include "PlayerInput.h"

void GameLoop()
{
	Tetris tetrisGame(gameWidth, gameHeight);
	TetrisGUI gui(tetrisGame.GetBoard(), gameWidth, gameHeight);
	PlayerInput playerInput('W', '?', 'D', 'A', 'S', ' ');

	while (true)
	{
		// timer
		auto start = std::chrono::high_resolution_clock::now();

		playerInput.Update();
		if (playerInput.rotateClockWise)
		{
			tetrisGame.RotateClockWise();
		}
		if (playerInput.rotateCounterClockWiseKey)
		{
			tetrisGame.RotateCounterClockWise();
		}
		if (playerInput.right)
		{
			tetrisGame.MoveRight();
		}
		if (playerInput.left)
		{
			tetrisGame.MoveLeft();
		}
		if (playerInput.down)
		{
			tetrisGame.Down();
		}
		if (playerInput.dump)
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


		// debuging
		//std::this_thread::sleep_for(std::chrono::microseconds(100));

		if (tetrisGame.IsTerminated)
			break;
	}


}