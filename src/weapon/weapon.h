#pragma once
#include <iostream>
using namespace std;
struct CWeapon
{
	string mName;
	int mAtk;
	int mRange;
	CWeapon(string name = "dagger", int atk = 3, int range = 1);
	virtual ~CWeapon();
};

