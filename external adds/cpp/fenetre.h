#ifndef Fenetre_h
#define Fenetre_h

#include <SFML/Graphics.hpp>

using namespace sf;

class Fenetre{
	private:
		RenderWindow *window;
		int largeur;
		int hauteur;
		
	public:
		Fenetre(int largeur, int hauteur, std::string title);
		~Fenetre();
		void close();
		bool isOpen();
		RenderWindow& getWindow();
		sf::Color getPixelColor(int x, int y);
		bool write(const char* str, int police, sf::Color, int x, int y);
		float getFont(const char* text, int police);
		void drawRect(int x, int y, int largeur, int hauteur, sf::Color);
		void draw_fillRect(int x, int y, int largeur, int hauteur, sf::Color);
		void add_pix(int x, int y, sf::Color color);
		void drawCircle(int x, int y, int rayon, sf::Color);
		bool drawSprite(int x, int y, int Xsize, int Ysize, const char* file);
		bool drawSprite(sf::Vector2i position, sf::Vector2i beginTo, sf::Vector2i size, const char* file);
		void draw_line(sf::Vector2i p1, sf::Vector2i p2, sf::Color color);
		void draw_line(sf::Vector2f p1, sf::Vector2f p2, sf::Color color);
		sf::Vector2f wait_clic();
		int getLargeur();
		int getHauteur();
};

#endif //Fenetre_h
