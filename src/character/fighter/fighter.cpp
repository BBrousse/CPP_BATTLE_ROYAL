#include "fighter.h"
CFighter::CFighter(int index ):CCharacter(index)
{
	mClass = FIGHTER;
	mHpMax = 30;
	mHp = mHpMax;
	mAtk = 6;
	mMvt = 4;
	mAtkRng = 1;
	// mX = 0;
	// mY = 0;
	mIndex=index;
}
CFighter::~CFighter() {
	cout << "A fighter has been deleted" << endl;
}