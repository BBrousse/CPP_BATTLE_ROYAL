#include "gunner.h"
CGunner::CGunner(int index) : CShooter(index)
{
	mClass = GUNNER;
	mHpMax = 13;
	mHp = mHpMax;
	mAtk = 15;
	mMvt = 3;
	mAtkRng = 4;
	// mX = 0;
	// mY = 0;
	mIndex = index;
	mCacAtk=4;
	mMaxShots = 3;
	mShots = 3;
	mNeedReloading=false;
}

bool CGunner::can_shoot() const
{
	return mShots > 0;
}

CGunner::~CGunner()
{
	cout << "A gunner has been deleted" << endl;
}

string CGunner::to_string() const
{
	return mNeedReloading && (mShots > 0) ? CShooter::to_string() + " will reaload" : CShooter::to_string();
}


void CGunner::doPlayerTurn(CGameGrid &grid, vector<CCharacter *>&characlist)
{
	// cout << "turn_start " << std::to_string(mIndex) << endl;
	move(grid);
	if(mNeedReloading && mShots > 0){
		cout << std::to_string(mIndex) + " is reloading";
		reloading();
	}
	else{
		vector<int> foes = checkFoeInRange(grid);
		if (foes.size() > 0)
		{
			int target = foes[(rand() % foes.size())];
			cout << std::to_string(mIndex) + " attacks " + std::to_string(target) << endl;
			attack(*characlist[target], grid);
			if (mShots > 0)
			{
				mNeedReloading = true;
			}
		}
	}
	// cout << "turn_end " << std::to_string(mIndex) << endl;
}

void CGunner::reloading(){
	mNeedReloading=false;
}