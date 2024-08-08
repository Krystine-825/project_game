
#pragma once
#include "MazeObject.h"
#include "Room.h"

#define IMG_PLAYER_RIGHT "res/Images/PlayerRight.png"
#define IMG_PLAYER_LEFT "res/Images/PlayerLeft.png"
#define IMG_PLAYER_UP "res/Images/PlayerUp.png"
#define IMG_PLAYER_DOWN "res/Images/PlayerDown.png"

class Player :
	public MazeObject
{
private:
	static SDL_Texture * playerTextures[4];
	std::shared_ptr<Room> startRoom;
public:
	int playerLives = 10;

	Player(std::shared_ptr<Room> setRoom, SDL_Renderer * renderer);
	Player();
	~Player();
	
	bool hasKey = false;

	//Quay ve diem xuat phat
	void SetPlayerToStart(std::shared_ptr<Room> room)
	{
		hasKey = false;
		SetStartRoom(room);
	}

	void ResetPlayer(std::shared_ptr<Room> room, int lives)
	{
		playerLives = lives;
		SetPlayerToStart(room);
	}

	void SetStartRoom(std::shared_ptr<Room> room)
	{
		startRoom = room;
		SetObjRoom(room);
	}

	//Di chuyen nguoi choi bang phim mui ten. Tra ve true neu nhu thanh cong, khong thi nguoc lai
	bool PlayerMove(SDL_Keycode key, SDL_Renderer * renderer)
	{
		bool successfulMove = false;
		Coordinate testPos = objPos;
		
		switch (key)
		{
		case SDLK_UP:
			testPos.yPos--;
			break;
		case SDLK_DOWN:
			testPos.yPos++;
			break;
		case SDLK_LEFT:
			testPos.xPos--;
			break;
		case SDLK_RIGHT:
			testPos.xPos++;
			break;
		default:
			std::cout << "Not a valid input!" << std::endl;
			return successfulMove;
			break;
		}

		//Sets cau truc cua nguoi choi dua tren input cua phim
		curObjTexture = playerTextures[key % 4];

		//Check if the room the player is trying to move to is one of the connected rooms
		//Kiem tra khong gian nguoi choi dang di chuyen là 1 trong nhung khong gian duoc lien ket tao nen me cung
		auto iter = std::find_if(begin(curObjRoom->connectRooms), end(curObjRoom->connectRooms), [&testPos](std::shared_ptr<Room> nextRoom) {
			return nextRoom->roomPos == testPos;
		});

		//if it is, move to that room and increase the step count
		//Neu la vay, di chuyen toi khong gian day va tang so buoc
		if (iter != std::end(curObjRoom->connectRooms))
		{
			SetObjRoom(*iter);
			successfulMove = true;
		}
		else
		{
			std::cout << "Can't Move That Way" << std::endl;
			successfulMove = false;
		}
		return successfulMove;
	}

	//an obstacle (Trap or Guard)
	//Mot vat the (Bay hoac Linh Canh)
	bool CheckForObjects()
	{
		//Pick Up Key
		//Nhat chia khoa
		if (std::find(begin(curObjRoom->roomTypes), end(curObjRoom->roomTypes), Key) != end(curObjRoom->roomTypes))
		{
			hasKey = true;
			std::cout << "Picked Up Key" << std::endl;
		}
		//Reset player Position and reduce lives count if it is a trap or guard
		//Quay ve diem xuat phat va giam so mang nguoi choi neu nguoi choi dung phai bay hoac linh canh
		if (std::find(begin(curObjRoom->roomTypes ), end(curObjRoom->roomTypes), Trap) != end(curObjRoom->roomTypes))
		{
			SetObjRoom(startRoom);
			std::cout << "Hit a trap" << std::endl;
			playerLives--;
			return true;
		}
		else if (std::find(begin(curObjRoom->roomTypes), end(curObjRoom->roomTypes), Guard) != end(curObjRoom->roomTypes))
		{
			SetObjRoom(startRoom);
			std::cout << "Hit a guard" << std::endl;
			playerLives--;
			return true;
		}
		return false;
	}
	
	
};

