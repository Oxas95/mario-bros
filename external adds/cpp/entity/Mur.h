#ifndef Mur_h
#define Mur_h

#include "entity_rect.h"

class Mur : public Entity_rect{
	private :
		
	public :
	Mur(int x, int y, int sizeX,int sizeY, int vie);
	virtual ~Mur();
	virtual entityType getType();
	virtual void  save (FILE* fs  );
};

#endif // Mur_h
