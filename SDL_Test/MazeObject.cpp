#include "MazeObject.h"

using namespace std;

MazeObject::MazeObject(shared_ptr<Room> room) :
	curObjRoom(room),
	objRenderer(room->roomRenderer),
	objPos(room->roomPos)
{
	SetObjectRect(&room->roomRect);
}

MazeObject::MazeObject(const MazeObject &other): 
	objRect(other.objRect),
	objRenderer(other.objRenderer),
	objPos(other.objPos),
	curObjRoom(other.curObjRoom)
{	
}

MazeObject::MazeObject()
{
}

MazeObject::~MazeObject()
{
}
