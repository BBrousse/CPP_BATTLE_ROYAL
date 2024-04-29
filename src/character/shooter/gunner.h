#pragma once
#include "shooter.h"

class CGunner : public CShooter
{
protected :
	bool mNeedReloading;
public:
	CGunner(int index = 0);
	~CGunner();
	bool can_shoot() const;
	string to_string() const;
	void doPlayerTurn(CGameGrid &grid, vector<CCharacter *> &characlist);
	void reloading();
};