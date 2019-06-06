#ifndef arbre_h
#define arbre_h

#include "entity_ronde.h"

class Arbre : public Entity_ronde{
	private :
		
	public :
	Arbre(int x, int y, int rayon, int vie);
	virtual ~Arbre();
	virtual entityType getType();
	virtual void  save (FILE* fs  );
};

#endif // arbre_h
