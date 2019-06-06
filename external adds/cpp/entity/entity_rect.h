#ifndef Entity_rect_h
#define Entity_rect_h

#include "Entity.h"

class Entity_rect : public Entity{
	protected :
		sf::Vector2i size;
	public :
		Entity_rect();
		virtual ~Entity_rect();
		Entity_rect(int x, int y,int sizeX,int sizeY,  int vie);
		sf::Vector2i &get_size();
		virtual void setPosition(int x, int y);
		virtual entityType getType() = 0;
		virtual entityType getPrimaryType();
		virtual void save (FILE  * fs  );
};

#endif // Entity_rect
