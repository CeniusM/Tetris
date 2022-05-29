#pragma once

class PlayerInput
{
public:
	PlayerInput(char rotateClockWise, char rotateCounterClockWise, char right, char left, char dump);
	~PlayerInput();

	void Update();

	char rotateClockWiseKey;
	int rotateClockWise{};

	char rotateCounterClockWiseKey;
	int rotateCounterClockWise{};

	char rightKey;
	int right{};

	char leftKey;
	int left{};

	char dumpKey;
	int dump{};

	

private:

};

PlayerInput::PlayerInput(char rotateClockWise, char rotateCounterClockWise, char right, char left, char dump)
{
	this->rotateClockWiseKey = rotateClockWise;
	this->rotateCounterClockWiseKey = rotateCounterClockWise;
	this->rightKey = right;
	this->leftKey = left;
	this->dumpKey = dump;
}

PlayerInput::~PlayerInput()
{
}