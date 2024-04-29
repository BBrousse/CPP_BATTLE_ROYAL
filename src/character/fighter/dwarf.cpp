#include "dwarf.h"
CDwarf::CDwarf(int index) : CFighter(index)
{
	mClass = DWARF;
	mHpMax = 40;
	mHp = mHpMax;
	mAtk = 5;
	mMvt = 2;
	mAtkRng = 1;
	// mX = 0;
	// mY = 0;
	mIndex = index;
	mTrunDrunked = 0;
	mBeersMax = 2;
	mBeers = mBeersMax;
}

string CDwarf::to_string() const
{
	string str = CCharacter::to_string();
	if (mTrunDrunked > 0)
	{
		str += ", drunked:" + std::to_string(mTrunDrunked) + "/3";
	}
	return str + ", Beers: " + std::to_string(mBeers) + "/" + std::to_string(mBeersMax);
}

CDwarf::~CDwarf()
{
	cout << "A dwarf has been deleted" << endl;
}

void CDwarf::drinkBeer()
{
	mBeers--;
	mTrunDrunked = 3;
	mAtk = 10;
	mMvt = 6;
	mHp += 3;
	if (mHp > mHpMax)
	{
		mHp = mHpMax;
	}
	cout << std::to_string(mIndex) + ": drinks some beers, and is now fully drunked and ready" << endl;
}

void CDwarf::soberUp()
{
	mAtk = 5;
	mMvt = 2;
	cout << std::to_string(mIndex) + ": is now sober";
	if (mHp < mHpMax)
	{
		cout << " and would like to have some beers... again";
	}
	cout << endl;
}

void CDwarf::doPlayerTurn(CGameGrid &grid, vector<CCharacter *> &characlist)
{
	cout << "turn_start " << std::to_string(mIndex) << endl;
	if ((mHp < mHpMax) && (mTrunDrunked == 0) && (mBeers > 0))
	{
		drinkBeer();
	}
	move(grid);

	vector<int> foes = checkFoeInRange(grid);
	if (foes.size() > 0)
	{
		int target = foes[(rand() % foes.size())];
		cout << std::to_string(mIndex) + " attacks " + std::to_string(target) << endl;
		attack(*characlist[target], grid);
	}
	if (mTrunDrunked > 0)
	{
		foes.clear();
		foes = checkFoeInRange(grid);
		if (foes.size() > 0)
		{
			int target = foes[(rand() % foes.size())];
			cout << std::to_string(mIndex) + " attacks " + std::to_string(target) << endl;
			attack(*characlist[target],grid);
		}
	}
	if (mTrunDrunked > 0)
	{
		mTrunDrunked--;
	}
	if (mTrunDrunked == 0)
	{
		soberUp();
	}
	cout << "turn_end " << std::to_string(mIndex) << endl;
}