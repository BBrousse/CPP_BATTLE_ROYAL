#pragma once
#include <vector>
#include "../weapon/weapon.h"
#include "../grid/game_grid.h"
typedef enum character_class
{
	NONE=-1,
	FIGHTER=0,
	SHOOTER,
	GUNNER,
	DWARF,
	ARCHER,
	ENDCLASSES,
	KNIGHT,
	SOLDIER
} ECharacterClasse;
typedef enum direction_e{
	LEFT, UP, RIGHT, DOWN, NO_MOVE, EDIREND
} EDirection;

string charClassToString(ECharacterClasse char_class);

class CCharacter
{
	protected :
		ECharacterClasse mClass;
		int mHp;
		int mHpMax;
		int mAtk;
		int mMvt;
		int mAtkRng;
		// int mX;
		// int mY;
		CCoordinates mPos;
		int mIndex;

	public :
		CCharacter(int index = 0);
		virtual ~CCharacter();
		void updatePosition(int x , int y );
		void updatePosition(CCoordinates pos);
		void dostep(CGameGrid &grid, int x, int y);
		void dostep(CGameGrid &grid, CCoordinates pos);
		void move(CGameGrid &grid);
		virtual bool attack(CCharacter &foe, CGameGrid &grid);
		bool isDead() const;
		bool takeDamage(int dmg);
		// int checkFoeInRange(CGameGrid &grid);
		vector<int> checkFoeInRange(CGameGrid &grid);
		virtual string to_string() const;
		ECharacterClasse getCharClass() const;
		int getHp() const;
		int getHpMax() const;
		int getAtk() const;
		int getMvt() const;
		int getAtkRng() const;
		int getX() const;
		int getY() const;
		CCoordinates getPos() const;
		void onDeath(CGameGrid &grid);
		virtual void doPlayerTurn(CGameGrid &grid, vector<CCharacter *>&characlist);
		int testCase(CGameGrid &grid, int mX, int mY, int i, int j);
		int testCase(CGameGrid &grid, CCoordinates const &pos1, CCoordinates const &pos2) const;
		bool selectAndAttack(CGameGrid &grid, vector<CCharacter *>&characlist, vector<int> &foes);
		void checkAccessibleCase(CGameGrid &grid);
};