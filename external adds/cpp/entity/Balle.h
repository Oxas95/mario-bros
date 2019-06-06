

#ifndef Balle_h
#define Balle_h

#include "entity_ronde.h"

class Balle : public Entity_ronde{
	private :
	int dommage;
	int distance;
	
	public :
	Balle(int x, int y, int rayon, int vie);
	virtual ~Balle();
	virtual entityType getType();
	int get_dommage();
	int get_distance();

};

#endif // Balle_h
