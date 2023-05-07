
#pragma once
#include "MazeObject.h"
#include "Room.h"

#define IMG_GUARD "res/Images/Guard.png"
class MazeGuard :
	public MazeObject
{
private:
	static SDL_Texture * guardTexture;
	std::shared_ptr<Room> guardCenterRoomPtr;
	std::shared_ptr<Room> guardCurRoomPtr;
	std::vector<std::shared_ptr<Room>>::iterator guardIter;
	
public:
	
	MazeGuard(std::shared_ptr<Room> setRoom);
	~MazeGuard();

	//Updates Guard Location Each Cycle
	void NextCycle()
	{
		//Find current guard room
		auto roomTypesIter = std::find(begin((*guardIter)->roomTypes), end((*guardIter)->roomTypes), Guard);
		
		//Remove the "Guard" type from the roomTypes
		if (roomTypesIter != end((*guardIter)->roomTypes))
			(*guardIter)->roomTypes.erase(roomTypesIter);
		
		//Move guard to next spot
		std::advance(guardIter, 1);
		if (guardIter == std::end(guardCenterRoomPtr->connectRooms))
			guardIter = std::begin(guardCenterRoomPtr->connectRooms);
		
		//Change that room type to have "Guard"
		(*guardIter)->roomTypes.push_back(Guard);

		SetObjRoom(*guardIter);
	}

};

