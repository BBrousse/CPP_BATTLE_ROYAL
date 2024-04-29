#include "ranged_weapon.h"
CRandedWeapon::CRandedWeapon(string name, int atk, int range, int maxShots) : CWeapon(name, atk, range)
{
	mMaxShots=maxShots;
	mNbShoots=maxShots;
}

CRandedWeapon::~CRandedWeapon(){}

bool CRandedWeapon::canShoot()
{
	return mNbShoots == 0 ? false : true ;
}