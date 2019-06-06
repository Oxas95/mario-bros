#ifndef Entity_ronde_h
#define Entity_ronde_h

#include "Entity.h"

class Entity_ronde : public Entity{
	protected :
		int rayon;
		sf::Vector2i centre;
	public :
		Entity_ronde();
		virtual ~Entity_ronde();
		Entity_ronde(int x, int y, int rayon, int vie);
		int get_rayon();
		virtual void setPosition(int x, int y);
		virtual entityType getType() = 0;
		virtual entityType getPrimaryType();
		virtual void save (FILE * fs  );
};

#endif // Entity_ronde
