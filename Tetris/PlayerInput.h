#pragma once

class PlayerInput
{
public:
	PlayerInput(char rotateClockWise, char rotateCounterClockWise, char right, char left, char down, char dump);
	~PlayerInput();

	void Update();

	char rotateClockWiseKey;
	int rotateClockWiseCoolDown{};
	bool rotateClockWise{};

	char rotateCounterClockWiseKey;
	int rotateCounterClockWiseCoolDown{};
	bool rotateCounterClockWise{};

	char rightKey;
	int rightCoolDown{};
	bool right{};

	char leftKey;
	int leftCoolDown{};
	bool left{};

	char downKey;
	int downCoolDown{};
	bool down{};

	char dumpKey;
	int dumpCoolDown{};
	bool dump{};

	

private:

};