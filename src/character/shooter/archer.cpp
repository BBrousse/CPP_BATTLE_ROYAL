#include "archer.h"
CArcher::CArcher(int index) : CShooter(index)
{
	mClass = ARCHER;
	mHpMax = 15;
	mHp = mHpMax;
	mAtk = 8;
	mCacAtk = 3;
	mMvt = 4;
	mAtkRng = 3;
	// mX = 0;
	// mY = 0;
	mIndex = index;
	mMaxShots = 10;
	mShots = 10;
	mMultiShots = 3;
	mMultiShotsAtk = 4;
}

CArcher::~CArcher()
{
	cout << "A archer has been deleted" << endl;
}

void CArcher::doPlayerTurn(CGameGrid &grid, vector<CCharacter *> &characlist)
{
	// cout << "turn_start " << std::to_string(mIndex) << endl;
	move(grid);
	if (mShots > 2 && (rand() % 100) < 25)
	{
		mAtk = mMultiShotsAtk;
		for (int i = 0; i < mMultiShots; i++)
		{
			vector<int> foes = checkFoeInRange(grid);
			if (foes.size() > 0)
			{
				int target = foes[(rand() % foes.size())];
				cout << std::to_string(mIndex) + " attacks " + std::to_string(target) << endl;
				attack(*characlist[target], grid);
			}
			foes.clear();
		}
	}else{
		mAtk = 8;
		vector<int> foes = checkFoeInRange(grid);
		if (foes.size() > 0)
		{
			int target = foes[(rand() % foes.size())];
			cout << std::to_string(mIndex) + " attacks " + std::to_string(target) << endl;
			attack(*characlist[target], grid);
		}
	}
	// cout << "turn_end " << std::to_string(mIndex) << endl;
}