#pragma once
class Game_Control
{
public:
	bool pause = true;
	bool start = true;
	bool GO = false;

	void gameOver()
	{
		GO = true;
		pause = true;
	}
};