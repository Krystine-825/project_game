
#pragma once
#include "MazeObject.h"
#define IMG_MAZEDOOR "res/Images/Lock.png"
class MazeDoor :
	public MazeObject
{
private:
	static SDL_Texture * doorTexture;
public:
	MazeDoor(std::shared_ptr<Room> setRoom);
	~MazeDoor();
};

