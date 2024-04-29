#pragma once
#include "../../weapon/ranged_weapon.h"
#include "../character.h"

class CShooter : public CCharacter
{
protected :
	int mMaxShots;
	int mShots;
	int mCacAtk;
public:
	CShooter(int index = 0);
	virtual ~CShooter();
	bool can_shoot() const;
	virtual string to_string() const;
	bool attack(CCharacter &foe, CGameGrid &grid);
	// void doPlayerTurn(CGameGrid &grid, CCharacter **&characlist);
};