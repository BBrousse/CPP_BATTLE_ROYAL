#include "shooter.h"
CShooter::CShooter(int index) : CCharacter(index)
{
	mClass = SHOOTER;
	mHpMax = 15;
	mHp = mHpMax;
	mAtk = 7;
	mCacAtk=3;
	mMvt = 4;
	mAtkRng = 3;
	// mX = 0;
	// mY = 0;
	mIndex = index;
	mMaxShots = 5;
	mShots = 5;
}

bool CShooter::can_shoot() const
{
	return mShots > 0;
}

CShooter::~CShooter()
{
	cout << "A shooter has been deleted" << endl;
}

string CShooter::to_string() const
{
	return CCharacter::to_string() + ",cacAtk:" + std::to_string(mCacAtk) + ", Shots:" + std::to_string(mShots) + "/" + std::to_string(mMaxShots);
}



bool CShooter::attack(CCharacter &foe,CGameGrid &grid)
{
	
	int dmg=0;
	if (can_shoot())
	{
		mShots--;
		if (mShots == 0)
		{
			mAtkRng = 1;
		}
		dmg=mAtk;
	}
	else{
		mAtkRng = 1;
		dmg = mCacAtk;
	}
	if (!foe.takeDamage(dmg))
	{
		foe.onDeath(grid);
		return true;
	}
	return false;
}
