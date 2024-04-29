#include "character.h"
string charClassToString(ECharacterClasse char_class)
{
	switch (char_class)
	{
	case NONE:
		return "No Class";
	case FIGHTER:
		return "Fighter";
	case SHOOTER:
		return "Shooter";
	case KNIGHT:
		return "Knight";
	case ARCHER:
		return "Archer";
	case GUNNER:
		return "Gunner";
	case SOLDIER:
		return "Soldier";
	case DWARF:
		return "Dwarf";

	default:
		return "Undef";
	}
	return "Undef";
}

CCharacter::~CCharacter()
{
	cout << "A character has been deleted" << endl;
}

CCharacter::CCharacter(int index)
{
	mClass = NONE;
	mHpMax = 10;
	mHp = mHpMax;
	mAtk = 3;
	mMvt = 4;
	mAtkRng = 1;
	// mX = 0;
	// mY = 0;
	mIndex = index;
}

void CCharacter::updatePosition(int x, int y)
{
	mPos=CCoordinates(x,y);
}

void CCharacter::updatePosition(CCoordinates pos)
{
	// mX = pos.x;
	// mY = pos.y;
	mPos=pos;
}

void CCharacter::dostep(CGameGrid &grid, int x, int y)
{
	// int newx = mX + x;
	// int newy = mY + y;
	CCoordinates step(x,y);
	grid[mPos+step] = grid[mPos];
	grid[mPos] = -1;
	mPos= mPos +step;
}

void CCharacter::dostep(CGameGrid &grid, CCoordinates pos)
{
	grid[mPos + pos] = grid[mPos];
	grid[mPos] = -1;
	mPos = mPos + pos;
}

void CCharacter::move(CGameGrid &grid)
{
	// cout << "start moving" << endl;

	int mvt_left = mMvt;
	while (mvt_left > 0)
	{
		int mvx = 0;
		int mvy = 0;
		EDirection dir = (EDirection)(rand() % EDIREND);
		// cout << std::to_string(dir) << endl;
		// cout << "pouet" << endl;
		// cout << "SIZEX - 1 : " + std::to_string(grid.getSizeX() - 1) << endl;
		// cout << "SIZEY - 1 : " + std::to_string(grid.getSizeY() - 1) << endl;
		// cout << std::to_string(mX) + ", " + std::to_string(mY) << endl;
		// cout << std::to_string(mvx) + ", " + std::to_string(mvy) << endl;
		switch (dir)
		{
		case LEFT:
			if (mPos.x > 0)
			{
				if (grid[mPos.x - 1][mPos.y] == -1)
				{
					mvx = -1;
				}
			}
			break;
		case UP:
			if (mPos.y > 0)
			{
				if (grid[mPos.x][mPos.y - 1] == -1)
				{
					mvy = -1;
				}
			}
			break;
		case RIGHT:
			if (mPos.x < (grid.getSizeX() - 1))
			{
				if (grid[mPos.x + 1][mPos.y] == -1)
				{
					mvx = 1;
				}
			}
			break;
		case DOWN:
			if (mPos.y < (grid.getSizeY() - 1))
			{
				if (grid[mPos.x][mPos.y + 1] == -1)
				{
					mvy = 1;
				}
			}
			break;
		case NO_MOVE:
			mvt_left--;
			break;
		default:
			break;
		}
		if (mvx != 0 || mvy != 0)
		{
			mvt_left--;
			dostep(grid, mvx, mvy);
		}
	}
	// cout << "end moving" << endl;
}

int CCharacter::testCase(CGameGrid &grid, CCoordinates const &pos1, CCoordinates const &pos2) const
{
	CCoordinates tmp = pos1+pos2;
	if (tmp.x < 0 || tmp.y < 0 || tmp.x >= grid.getSizeX() || tmp.y >= grid.getSizeY()){
		return -1;
	}
	
	return grid[tmp];
}

int CCharacter::testCase(CGameGrid &grid, int mX, int mY, int i, int j)
{
	if (((i < 0) && ((mX + i) < 0)) || ((i > 0) && ((mX + i) >= grid.getSizeX())))
	{
		return -1;
	}
	if (((j < 0) && ((mY + j) < 0)) || ((j > 0) && ((mY + j) >= grid.getSizeY())))
	{
		return -1;
	}

	return grid[mX + i][mY + j];
}

vector<int> CCharacter::checkFoeInRange(CGameGrid &grid)
{
	// cout << "start searching" << endl;
	vector<int> l = {};
	int tmp = -1;
	for (int j = 0; j <= mAtkRng; j++)
	{
		for (int i = 0; i <= (mAtkRng - j); i++)
		{
			/*
			 * do not check character position
			 * and out of range
			 */
			vector<CCoordinates> rng_shift { CCoordinates(-i, -j), CCoordinates(i, -j), CCoordinates(i, j), CCoordinates(-i, j) };
			if (i + j != 0)
			{
				for(int k =0; k < 4; k++){
					tmp = testCase(grid, mPos, rng_shift[k]);
					if (tmp != -1)
					{
						l.push_back(tmp);
					}
				}
			}
		}
		/*no foe FOUND*/
		
	}
	// cout << "end searching" << endl;
	// return l.size() > 0 ? l.front() : -1;
	return l;
}

bool CCharacter::isDead() const
{
	return mHp < 1;
}

bool CCharacter::takeDamage(int dmg)
{
	mHp -= dmg;
	if (mHp < 1)
	{
		mHp = 0;
		/**is dead**/
		return false;
	}
	return true;
}

void CCharacter::onDeath(CGameGrid &grid)
{
	grid.removePlayer(mPos);
	updatePosition(-1,-1);
}

bool CCharacter::attack(CCharacter &foe,CGameGrid &grid)
{
	if(!foe.takeDamage(mAtk)){
		foe.onDeath(grid);
		return true;
	}
	return false;;
}

string CCharacter::to_string() const
{
	string str = "Index:" + std::to_string(mIndex) + ", " + charClassToString(mClass);
	str += ", " + std::to_string(mHp) + "/" + std::to_string(mHpMax) + "";
	str += ", atk:" + std::to_string(mAtk) + ", mvt:" + std::to_string(mMvt) + ", atkrng: " + std::to_string(mAtkRng);
	str += ", at: " + mPos.to_string();

	return str;
}

ECharacterClasse CCharacter::getCharClass() const
{
	return mClass;
}

int CCharacter::getHpMax() const
{
	return mHpMax;
}

int CCharacter::getHp() const
{
	return mHp;
}

int CCharacter::getAtk() const
{
	return mAtk;
}

int CCharacter::getMvt() const
{
	return mMvt;
}
int CCharacter::getAtkRng() const
{
	return mAtkRng;
}

int CCharacter::getX() const
{
	return mPos.x;
}
int CCharacter::getY() const
{
	return mPos.y;
}

CCoordinates CCharacter::getPos() const
{
	return mPos;
}

	bool CCharacter::selectAndAttack(CGameGrid &grid, vector<CCharacter *>&characlist, vector<int> &foes)
{
	int target = foes[(rand() % foes.size())];
	cout << std::to_string(mIndex) + " attacks " + std::to_string(target) << endl;
	return attack(*characlist[target], grid);
}

void CCharacter::doPlayerTurn(CGameGrid &grid, vector<CCharacter *>&characlist)
{
	// cout << "turn_start " << std::to_string(mIndex) << endl; 
	move(grid);
	vector<int> foes = checkFoeInRange(grid);
	if (foes.size() > 0)
	{
		selectAndAttack(grid, characlist, foes);
	}
	// cout << "turn_end " << std::to_string(mIndex) << endl;
}

void CCharacter::checkAccessibleCase(CGameGrid &grid)
{
	vector<CCoordinates> canaccess {mPos};
	vector<CCoordinates> dir_coord { CCoordinates(1, 0), CCoordinates(0, 1) , CCoordinates(-1, 0), CCoordinates(0, -1)};
	auto it = canaccess.begin(); // first case to test;
	auto itend = canaccess.end();
	for(int i =0; i< mMvt;i++){
		for (it; it != itend; it++)
		{
			for(int i =0; i < 4; i++){
				CCoordinates tmppos = *it + dir_coord[i];
				if (grid.isInBound(dir_coord[i]))
				{
					if(grid[tmppos] == -1)
					{
						canaccess.push_back(tmppos);
					}
				}
			}
		}
		it=itend;
		itend = canaccess.end();
	}
}