

#pragma once
#include "SDL_rect.h"
#include "Coordinate.h"
#include "SDL_image.h"
#include "Room.h"
#include <cmath>
#include <memory>

enum objectTypes {key, door, trap, guard};
class MazeObject
{
protected:
	SDL_Rect objRect;
	std::shared_ptr<Room> curObjRoom;
	SDL_Texture* curObjTexture = NULL;
	SDL_Renderer* objRenderer = NULL;
public:
	Coordinate objPos;

	//Constructors and Destructors
	MazeObject(std::shared_ptr<Room> room);
	MazeObject(const MazeObject &other);
	MazeObject();
	~MazeObject();

	//Public Functions

	//Function that should be called every time the game is updated
	virtual void NextCycle()
	{}

	//Sets the object's variables based off its room
	void SetObjRoom(std::shared_ptr<Room> setRoom)
	{
		curObjRoom = setRoom;
		objPos = setRoom->roomPos;
		SetObjectRect(&setRoom->roomRect);
	}

	//Sets the Rect Area for the Object
	void SetObjectRect(SDL_Rect * rect)
	{
		objRect = 
		{ 
			rect->x + rect->w / 4,
			rect->y + rect->h / 4,
			(rect->w) / 2,
			(rect->h) / 2 
		};
	}

	//Add this object to the renderer
	void AddObjToRenderer()
	{
		SDL_RenderCopy(objRenderer, curObjTexture, NULL, &objRect);
	}
};

