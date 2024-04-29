#pragma once
#include "../character/character_builder.h"

class CGameCore
{
	private :
		// static CGameCore* game_core;
		CGameGrid mGameGrid;
		// CCharacter** mCharacters;
		vector<CCharacter *> mCharacters {};
		int mPlayerNumber;
		int mTurnNumber;

	public :
		// CGameCore();
		CGameCore( int playerNumber,  int sizeX,  int sizeY) ;
		static CGameCore initGame( int playerNumber,  int x,  int y);
		void runGame();
		void doTurn();
		bool checkState();
		void endGame();
		void cleanGame();
		void placePlayer(int index);
		string to_string() const;
		void printGameGrid()const;
		void printPlayerList()const;
		void printState()const;
		void removePlayer(CCharacter &foe);
		void cleanCorps();
};