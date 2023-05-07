
#pragma once
#include "MazeObject.h"

#define IMG_MAZEKEY "res/Images/Key.png"
class MazeKey :
	public MazeObject
{
private:
	static SDL_Texture * keyTexture;
public:
	MazeKey(std::shared_ptr<Room> room);
	~MazeKey();
};

