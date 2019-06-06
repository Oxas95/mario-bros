#ifndef Joueur_h
#define Joueur_h

#include "entity_ronde.h"
#include "Balle.h"

class Joueur : public Entity_ronde{
	private :
		sf::RectangleShape rectangle;
		Balle *balle;
	public :
		Joueur(int x, int y, int vie, bool bleu);
		virtual ~Joueur();
		virtual void draw(Fenetre& w);
		virtual void drawAt(Fenetre& w, sf::Vector2i);
		virtual void setPosition(int x, int y);
		void setRotation (int i);
		float getRotation();
		virtual entityType getType();
		virtual void  save (FILE* fs  );
		Balle& get_balle();
		void set_balle(int x, int y, int rayon, int vie);
};

#endif // Joueur_h
