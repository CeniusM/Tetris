#pragma once

class PlayerInput
{
public:
	PlayerInput(char rotateClockWise, char rotateCounterClockWise, char right, char left, char dump);
	~PlayerInput();

	void Update();

	char rotateClockWiseKey;
	int rotateClockWiseCoolDown{};
	int rotateClockWise{};

	char rotateCounterClockWiseKey;
	int rotateCounterClockWiseCoolDown{};
	int rotateCounterClockWise{};

	char rightKey;
	int rightCoolDown{};
	int right{};

	char leftKey;
	int leftCoolDown{};
	int left{};

	char dumpKey;
	int dumpCoolDown{};
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