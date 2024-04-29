#include "character_builder.h"

CCharacter *CCharacterBuilder::generate(ECharacterClasse char_class,int index)
{
	switch (char_class)
	{
	case NONE :
		return generateCharacter<CCharacter>(index);
	case FIGHTER :
		return generateCharacter<CFighter>(index);
	case SHOOTER :
		return generateCharacter<CShooter>(index);
	case GUNNER :
		return generateCharacter<CGunner>(index);
	case DWARF :
		return generateCharacter<CDwarf>(index);
	case ARCHER :
		return generateCharacter<CArcher>(index);

	default:
		break;
	}
	return NULL;
}
