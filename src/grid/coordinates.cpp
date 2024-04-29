#include "coordinates.h"
CCoordinates::CCoordinates(const int _x, const int _y)
{
	x = _x;
	y = _y;
}
CCoordinates::~CCoordinates(){}
CCoordinates CCoordinates::operator+(CCoordinates const &pos) const
{
	return CCoordinates(x + pos.x, y + pos.y);
}

CCoordinates CCoordinates::operator-(CCoordinates const &pos) const
{
	return CCoordinates(x - pos.x, y - pos.y);
}

bool CCoordinates::operator==(CCoordinates const &pos) const
{
	return (x == pos.x) && (y == pos.y);
}

int CCoordinates::distance(CCoordinates const &pos1, CCoordinates const &pos2)
{
	return abs(pos1.x - pos2.x) + abs(pos1.y - pos2.y);
}
string CCoordinates::to_string() const
{
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}