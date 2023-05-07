
#pragma once
struct Coordinate
{
public:
	int xPos;
	int yPos;
	Coordinate(int x, int y);
	Coordinate();
	~Coordinate();

	bool operator ==(const Coordinate &other) const
	{
		if (xPos == other.xPos && yPos == other.yPos)
			return true;
		else
			return false;
	}
	
	bool operator !=(const Coordinate &other) const
	{
		if (xPos != other.xPos || yPos != other.yPos)
			return true;
		else
			return false;
	}
};

