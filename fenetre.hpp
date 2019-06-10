#ifndef Fenetre_hpp
#define Fenetre_hpp

#include <SFML/Graphics.hpp>

class Fenetre{
	private:
		sf::RenderWindow *window;
		sf::ContextSettings settings;
		int largeur;
		int hauteur;
		short zoom_cases;
		
	public:
		Fenetre();
		void resize(const short zoom);
		~Fenetre();
		void close();
		bool isOpen();
		sf::RenderWindow& getWindow();
		sf::Color getPixelColor(int x, int y);
		bool write(const char* str, int police, sf::Color, int x, int y);
		void writeCases(const char* str,int x, int y);
		void writeCases(const char* str,sf::Vector2i);
		void writeCases(const char* str,sf::Vector2f);
		float getFont(const char* text, int police);
		void drawRect(int x, int y, int largeur, int hauteur, sf::Color);
		void draw_fillRect(int x, int y, int largeur, int hauteur, sf::Color);
		void add_pix(int x, int y, sf::Color color);
		void drawCircle(int x, int y, int rayon, sf::Color);
		void clear();
		void clear(sf::Color);
		void draw(sf::Drawable&);
		void display();
		void drawSprite(int x, int y, sf::Sprite& sprite);
		void drawSprite(sf::Vector2i posSprite, sf::Sprite& sprite);
		void drawSprite(sf::Vector2f posSprite, sf::Sprite& sprite);
		void drawSpriteCases(int x, int y, sf::Sprite& sprite);
		void drawSpriteCases(sf::Vector2i posSprite, sf::Sprite& sprite);
		void drawSpriteCases(sf::Vector2f posSprite, sf::Sprite& sprite);
		bool drawSprite(int x, int y, const char* file);
		void draw_line(sf::Vector2i p1, sf::Vector2i p2, sf::Color color);
		void draw_line(sf::Vector2f p1, sf::Vector2f p2, sf::Color color);
		sf::Vector2i wait_clic();
		sf::Keyboard::Key getKey(bool& pressed);
		int getLargeur();
		int getHauteur();
		short getZoom();
};

#endif //Fenetre_hpp
