#include "game_core.h"
// CGameCore::CGameCore()
// {
// 	mGameGrid=new CGameGrid(5,5);
// 	mGameGrid=new CGameGrid(5,5);
// }

CGameCore::CGameCore(int playerNumber, int sizeX, int sizeY)
{
	mGameGrid = CGameGrid(sizeX, sizeY);
	// TO DO add ctrls
	mPlayerNumber = playerNumber;
	// mCharacters = new CCharacter *[mPlayerNumber];
	// mCharacters = new CCharacter *[mPlayerNumber];
}

void CGameCore::placePlayer(int index)
{
	bool placed = false;
	int x = 0;
	int y = 0;
	while (!placed)
	{
		x = rand() % mGameGrid.getSizeX();
		y = rand() % mGameGrid.getSizeY();
		if (mGameGrid[x][y] == -1)
		{
			mGameGrid[x][y] = index;
			placed = true;
			mCharacters[index]->updatePosition(x, y);
		}
	}
}

CGameCore CGameCore::initGame(int playerNumber, int sizeX, int sizeY)
{
	CGameCore gc = *(new CGameCore(playerNumber, sizeX, sizeY));
	for (int i = 0; i < playerNumber; i++)
	{
		cout << "add player start " << std::to_string(i) << endl;
		ECharacterClasse char_class = (ECharacterClasse)(rand() % ENDCLASSES);
		gc.mCharacters.push_back(CCharacterBuilder::generate(char_class, i));
		// gc.mCharacters[i] = CCharacterBuilder::generate(char_class,i);
		cout << "place  player" << std::to_string(i) << endl;
		gc.placePlayer(i);
		cout << "init members end " << std::to_string(i) << endl;
	}
	cout << "add player end" << endl;
	return gc;
}
void CGameCore::runGame()
{
	bool end = false;
	cout << std::to_string(mPlayerNumber) <<endl;
	while (!end)
	{
		mTurnNumber++;
		doTurn();
		if (checkState()){
		// if (mTurnNumber==20){
			end = true;
		}
	}
}
void CGameCore::cleanCorps()
{
	for (int i = 0; i < mPlayerNumber; i++)
	{
		if (mCharacters[i]->isDead())
		{
			// cout << std::to_string(i)+" is dead" <<endl;
			if (mCharacters[i]->getX()!=-1){
				removePlayer(*(mCharacters[i]));
				mCharacters[i]->updatePosition(-1,-1);
			}
		}
	}
}

void CGameCore::doTurn()
{
	for (int i = 0; i < mPlayerNumber; i++)
	{
		if (!mCharacters[i]->isDead())
		{
			mCharacters[i]->doPlayerTurn(mGameGrid, mCharacters);
		}
		cleanCorps();
	}
	printState();
}
void CGameCore::removePlayer(CCharacter &foe)
{
	mGameGrid[foe.getX()][foe.getY()] =-1;
}


bool CGameCore::checkState() {
	int alives = 0;
	for (int i = 0; i < mPlayerNumber; i++)
	{
		if(!mCharacters[i]->isDead()){
			alives++;
		}
	}
	return alives < 2;
}
void CGameCore::endGame() {}
void CGameCore::cleanGame() {
	for(int i=0; i< mPlayerNumber; i++){
		delete mCharacters[i];
	}
}
string CGameCore::to_string() const
{
	return "";
}

void CGameCore::printGameGrid() const
{
	for (int y = 0; y < mGameGrid.getSizeY(); y++)
	{
		for (int x = 0; x < mGameGrid.getSizeX(); x++)
		{
			// cout << std::to_string(x) + ", " + std::to_string(y) << endl;
			if (mGameGrid[x][y] == -1)
			{
				cout << "*";
			}
			else
			{
				/*print character class symbole*/
				cout << std::to_string(mGameGrid[x][y]);
			}
		}
		cout << endl;
	}
}

void CGameCore::printPlayerList() const
{
	for (int i = 0; i < mPlayerNumber; i++)
	{
		cout << mCharacters[i]->to_string() << endl;
	}
}

void CGameCore::printState() const
{
	cout << "------------------" << endl;
	cout << "------ "+std::to_string(mTurnNumber)+" --------" << endl;
	printPlayerList();
	printGameGrid();
	cout << "------------------" << endl;
}