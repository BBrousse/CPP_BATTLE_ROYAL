#pragma once
#include "shooter.h"

class CArcher : public CShooter
{
protected :
	int mMultiShots;
	int mMultiShotsAtk;

public:
	CArcher(int index = 0);
	~CArcher();
	void doPlayerTurn(CGameGrid &grid, vector<CCharacter *> &characlist);
};