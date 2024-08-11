
#pragma once
#include "MazeObject.h"

#define IMG_TRAP_INACTIVE "res/Images/SpikeTrapInactive.png"
#define IMG_TRAP_ACTIVE "res/Images/SpikeTrapActive.png"

class MazeTrap :
	public MazeObject
{
private:
	int maxTrapTime;
	int curTrapTime;
	static SDL_Texture * trapActiveTexture;
	static SDL_Texture * trapInactiveTexture;
public:
	
	MazeTrap(std::shared_ptr<Room> room);
	~MazeTrap();

	//Increments trap time and checks if trap state must change each cycle
	//Gia co thoi gian cua bay va kiem tra trang thai cua bay phai thay doi moi vong lap
	void NextCycle()
	{
		curTrapTime++;
		if (curTrapTime > maxTrapTime)
		{ 
			curTrapTime = 0;
		}
		SetTrapTexture();
	}
	
	//Sets trap texture based off of current trap state
	//Thay doi cau truc cua bay dua tren trang thai hien tai cua chung
	void SetTrapTexture()
	{
		if(curTrapTime == 0)
		{
			curObjRoom->roomTypes.push_back(Trap);
			curObjTexture = trapActiveTexture;
		}
		else 
		{
			auto roomTypeIter = std::find(begin((curObjRoom)->roomTypes), end((curObjRoom)->roomTypes), Trap);
			if (roomTypeIter != end(curObjRoom->roomTypes))
			{
				curObjRoom->roomTypes.erase(roomTypeIter);
				curObjTexture = trapInactiveTexture;
			}
		}
	}
};

