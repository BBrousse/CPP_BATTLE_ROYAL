#include "weapon.h"
struct CRandedWeapon : CWeapon
{
	int mMaxShots;
	int mNbShoots;
	CRandedWeapon(string mName = "dagger", int mAtk = 3, int mRange = 4,int mMaxShots = 5);
	~CRandedWeapon();
	bool canShoot();
};