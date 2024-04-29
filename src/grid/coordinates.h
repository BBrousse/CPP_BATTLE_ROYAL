#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct CCoordinates
{
	int x;
	int y;
	CCoordinates(const int _x=0, const int _y=0);
	virtual ~CCoordinates();
	// static vector<CCoordinates> DIRECTIONS;
	CCoordinates operator + (CCoordinates const &pos)const ;
	CCoordinates operator - (CCoordinates const &pos)const ;

	bool operator == (CCoordinates const &pos)const ;

	static int distance(CCoordinates const &pos1, CCoordinates const &pos2);

	string to_string() const;
};
