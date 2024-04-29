#include <iostream>
#include "coordinates.h"
// #include "../character/character_builder.h"
using namespace std;
class CGameGrid {
	private:
		int **mGrid;
		int mSizeX;
		int mSizeY;
	public :
		CGameGrid(int sizeX=5, int sizeY=5);
		~CGameGrid();
		// void placePlayer(int index);
		// void  removePlayer(int index);
		void  removePlayer(int x, int y);
		void removePlayer(CCoordinates const &pos);
		string to_string() const;
		int getSizeX() const;
		int getSizeY() const;
		int *operator[](int x) const;
		int& operator[](CCoordinates const &pos) const;
		bool isInBound(CCoordinates &tmppos)const;
};