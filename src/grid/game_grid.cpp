#include "game_grid.h"
CGameGrid::CGameGrid(int sizeX, int sizeY)
{
	mSizeX = sizeX;
	mSizeY = sizeY;
	mGrid = new int *[sizeX];
	for (int i = 0; i < sizeX; i++)
	{
		mGrid[i] = new int[sizeY];
		for(int j =0; j < sizeY; j++){
			mGrid[i][j]=-1;
		}
	}
}
CGameGrid::~CGameGrid()
{
	cout << "delete grid" << endl;
}

void CGameGrid::removePlayer(int x, int y)
{
	mGrid[x][y] = -1;
}

void CGameGrid::removePlayer(CCoordinates const &pos)
{
	mGrid[pos.x][pos.y] = -1;
}

string CGameGrid::to_string() const
{
	string str="";
	for (int y = 0; y < mSizeY; y++)
	{
		for (int x = 0; x < mSizeX; x++)
		{
			if (mGrid[x][y] == -1)
			{
				str+= "*";
			}
			else
			{
				str += std::to_string(mGrid[x][y]);
			}
		}
		str += "\n";
	}
	return str;
}

int CGameGrid::getSizeX() const
{
	return mSizeX;
}
int CGameGrid::getSizeY() const{
	return mSizeY;
}

int *CGameGrid::operator[](int x) const
{
	return mGrid[x];
}

int& CGameGrid::operator[](CCoordinates const &pos) const
{
	return mGrid[pos.x][pos.y];
}

bool CGameGrid::isInBound(CCoordinates &tmppos)const
{
	return (tmppos.x > -1) && (tmppos.y > -1) &&( tmppos.x < mSizeX) && (tmppos.y < mSizeY);
}