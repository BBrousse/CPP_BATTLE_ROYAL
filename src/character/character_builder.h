#pragma once
#include "fighter/dwarf.h"
#include "shooter/gunner.h"
#include "shooter/archer.h"

struct CCharacterBuilder
{
	static CCharacter *generate(ECharacterClasse char_class, int index =0);
	template <typename T>
	static T *generateCharacter(int index = 0){
		return new T(index);
	}
};