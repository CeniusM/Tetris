#include <Windows.h>

#include "PlayerInput.h"

// called 100 times a second
void PlayerInput::Update()
{
	// here will all the logic go for how when you can press the difrent buttons
	// so like if you hold right it dosent just in 100ms go to the complete other side

	// player inputs, Check if high-order bit is set (1 << 15)
	if (GetKeyState(rotateClockWiseKey) & 0x8000)
	{
		// in progress
	}

	if (GetKeyState(rotateCounterClockWiseKey) & 0x8000)
	{
		// in progress
	}

	if (GetKeyState(rightKey) & 0x8000)
	{
		if (rightCoolDown > 0)
		{
			right = false;
			rightCoolDown -= 1;
		}
		else
		{
			rightCoolDown = 7;
			right = true;
		}
	}
	else
	{
		right = false;
		rightCoolDown = 0;
	}

	if (GetKeyState(leftKey) & 0x8000)
	{
		if (leftCoolDown > 0)
		{
			left = false;
			leftCoolDown -= 1;
		}
		else
		{
			left = true;
			leftCoolDown = 7;
		}
	}
	else
	{
		left = false;
		leftCoolDown = 0;
	}



	if (GetKeyState(downKey) & 0x8000)
	{
		if (downCoolDown > 0)
		{
			down = false;
			downCoolDown -= 1;
		}
		else
		{
			down = true;
			downCoolDown = 2;
		}
	}
	else
	{
		down = false;
		downCoolDown = 0;
	}

	if (GetKeyState(dumpKey) & 0x8000)
	{
		// in progress
	}
	

}

PlayerInput::PlayerInput(char rotateClockWise, char rotateCounterClockWise, char right, char left, char down, char dump)
{
	this->rotateClockWiseKey = rotateClockWise;
	this->rotateCounterClockWiseKey = rotateCounterClockWise;
	this->rightKey = right;
	this->leftKey = left;
	this->downKey = down;
	this->dumpKey = dump;
}

PlayerInput::~PlayerInput()
{
}