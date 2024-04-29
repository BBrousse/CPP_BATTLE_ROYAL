#pragma once
#include "fighter.h"

class CDwarf : public CFighter
{
	private:
		int mTrunDrunked;
		int mBeersMax;
		int mBeers;

	public:
		CDwarf(int index = 0);
		~CDwarf();
		void drinkBeer();
		void soberUp();
		void doPlayerTurn(CGameGrid &grid, vector<CCharacter *> &characlist);
		string to_string() const;
};
