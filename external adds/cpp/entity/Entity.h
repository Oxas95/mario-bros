#ifndef Entity_h
#define Entity_h

#define petit 1
#define moyen 2
#define grand 3

enum entityType{
	ronde,
	rect,
	arbre,
	cactus,
	rocher,
	tronc,
	mur,
	balle,
	joueur,
	joueurBleu,
	joueurRouge
};

#include "../fenetre.h"

class Entity{
	protected :
		int vie;
		sf::Vector2i position;
		sf::Texture texture; //pour garder la texture en mémoire sinon sprite devient invalide
		sf::Sprite sprite; //variable contenant le sprite a afficher
		
	public :
		Entity();
		virtual ~Entity();
		Entity(int x, int y);
		bool degats(int); //infliger des degats à l'entité, retourne faux si les points de vies atteignent 0
		void set_texture(const char* name);
		virtual void draw(Fenetre& w);
		virtual void drawAt(Fenetre& w, sf::Vector2i);
		sf::Vector2i getPosition();
		virtual void setPosition(int x, int y);
		int getVie();
		void setVie(int);
		sf::Sprite& getSprite();
		virtual entityType getType() = 0;
		virtual entityType getPrimaryType() = 0;
		virtual void  save (FILE* fs  );
};

#endif //Entity_h
