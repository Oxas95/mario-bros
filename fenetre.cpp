#include "fenetre.hpp"
#include <iostream>
#include <string>
#include "global.hpp"
#include "texture.hpp"
#include "string.h"

using namespace std;

Fenetre::Fenetre(){
	zoom_cases = 1;

	settings.depthBits = 0;
	settings.stencilBits = 0;
	settings.antialiasingLevel = 0;
	settings.majorVersion = 1;
	settings.minorVersion = 1;
	
	window = NULL;
	
	resize(zoom_cases);
}

void Fenetre::resize(const short zoom){
	if(window) window->close();
	if(zoom > 0){
		zoom_cases = zoom;
		this->largeur = sizeof(cases) * zoom_cases * nbCasesX;
		this->hauteur = sizeof(cases) * zoom_cases * nbCasesY;
		window = new sf::RenderWindow(sf::VideoMode(largeur, hauteur), "Super Mario Bros NES", sf::Style::Titlebar | sf::Style::Close, settings);
	}
}

Fenetre::~Fenetre(){
	close();
}

void Fenetre::close(){
	window->close();
	delete window;
	window = NULL;
}

bool Fenetre::isOpen(){
	return window->isOpen();
}

sf::RenderWindow& Fenetre::getWindow(){
	return *window;
}

sf::Font font;
bool fontLoaded = false;

float Fenetre::getFont(const char* str, int police){
	if(fontLoaded == false){
		if (!font.loadFromFile("dynasty.ttf"))
			return 0.f;
		fontLoaded = true;
	}
	if(str == NULL) return 0.0;
	
	sf::Text text;
	// select the font
	text.setFont(font); // font is a sf::Font
	// set the string to display
	text.setString(str);
	// set the character size
	text.setCharacterSize(police);
	
	sf::FloatRect fr = text.getLocalBounds();
	float largeurTexte = fr.width;
	return largeurTexte;
}

sf::Color Fenetre::getPixelColor(int x, int y){
	sf::Texture texture;
	texture.create(largeur, hauteur);
	texture.update(*window);
	sf::Image screenshot = texture.copyToImage();
	return screenshot.getPixel(x,y);
}

bool Fenetre::write(const char* str, int police, sf::Color color, int x, int y){
	if(fontLoaded == false){
		if (!font.loadFromFile("dynasty.ttf"))
			return false;
		fontLoaded = true;
	}
	sf::Text text;
	// select the font
	text.setFont(font); // font is a sf::Font
	// set the string to display
	text.setString(str);
	// set the character size
	text.setCharacterSize(police);
	// set the color
	text.setFillColor(color);
	
	text.setPosition(x,y);
	
	window->draw(text);
	
	return true;
}

void Fenetre::writeCases(const char* str,int x, int y){
	int size_str = strlen(str);
	int i;
	for (i = 0; i < size_str; i++){
		drawSpriteCases(x,y,textures::lettres[textures::getSpriteChar(str[i])]);
		x++;
	}
}

void Fenetre::writeCases(const char* str,sf::Vector2i pos){
	int size_str = strlen(str);
	int i;
	for (i = 0; i < size_str; i++){
		drawSpriteCases(pos,textures::lettres[textures::getSpriteChar(str[i])]);
		pos.x++;
	}
}

void Fenetre::writeCases(const char* str,sf::Vector2f pos){
	int size_str = strlen(str);
	int i;
	for (i = 0; i < size_str; i++){
		drawSpriteCases(pos,textures::lettres[textures::getSpriteChar(str[i])]);
		pos.x++;
	}
}

void Fenetre::drawRect(int x, int y, int largeur, int hauteur, sf::Color color){
	sf::RectangleShape rectangle(sf::Vector2f(largeur, hauteur));
	rectangle.setPosition(sf::Vector2f(x, y));
	rectangle.setFillColor(color);
	rectangle.setOutlineThickness(1);
	rectangle.setOutlineColor(sf::Color::Black);
	window->draw(rectangle);
}

void Fenetre::draw_fillRect(int x, int y, int largeur, int hauteur, sf::Color color){
	sf::RectangleShape rectangle(sf::Vector2f(largeur, hauteur));
	rectangle.setPosition(sf::Vector2f(x, y));
	rectangle.setFillColor(color);
	window->draw(rectangle);
}

void Fenetre::add_pix(int x, int y, sf::Color color){
	draw_fillRect(x,y,1,1,color);
}

void Fenetre::drawCircle(int x, int y, int rayon, sf::Color color){
	sf::CircleShape shape(rayon);
    shape.setFillColor(color);
    x -= rayon;
    y -= rayon;
    shape.setPosition(sf::Vector2f(x,y));
	window->draw(shape);
}

void Fenetre::clear(){
	window->clear();
}

void Fenetre::clear(sf::Color c){
	window->clear(c);
}

void Fenetre::draw(sf::Drawable& d){
	window->draw(d);
}

void Fenetre::display(){
	window->display();
}

void Fenetre::drawSprite(int x, int y, sf::Sprite& sprite){
	drawSprite(sf::Vector2f(x,y), sprite);
}

void Fenetre::drawSprite(sf::Vector2i posSprite, sf::Sprite& sprite){
	drawSprite(sf::Vector2f(posSprite.x,posSprite.y), sprite);
}

void Fenetre::drawSprite(sf::Vector2f posSprite, sf::Sprite& sprite){
	sprite.setPosition(posSprite);
	window->draw(sprite);
}

void Fenetre::drawSpriteCases(int x, int y, sf::Sprite& sprite){
	drawSpriteCases(sf::Vector2f(x,y), sprite);
}

void Fenetre::drawSpriteCases(sf::Vector2i posSprite, sf::Sprite& sprite){
	drawSpriteCases(sf::Vector2f(posSprite.x,posSprite.y), sprite);
}

void Fenetre::drawSpriteCases(sf::Vector2f posSprite, sf::Sprite& sprite){
	posSprite.x *= sizeof(cases);
	posSprite.y *= sizeof(cases);
	sprite.setPosition(posSprite);
	window->draw(sprite);
}

bool Fenetre::drawSprite(int x, int y, const char* file){
	sf::Texture texture;
	string str = "";
	if(file)str.append(file);

	if (!texture.loadFromFile(str)){
		return false;
	}
	
	sf::Sprite sprite;
	sprite.setTexture(texture);
	
	sprite.setPosition(sf::Vector2f(x,y));

	window->draw(sprite);
	return true;
}

//fonction prise dans uvsqgraphics
void Fenetre::draw_line(sf::Vector2i p1, sf::Vector2i p2, sf::Color coul) {
	int xmin, xmax;
	int ymin, ymax;
	int i,j;
	float a,b,ii,jj;
	
	if (p1.x < p2.x) {xmin=p1.x; xmax=p2.x;} else{xmin=p2.x; xmax=p1.x;}
	if (p1.y < p2.y) {ymin=p1.y; ymax=p2.y;} else{ymin=p2.y; ymax=p1.y;}
	
	if (xmin==xmax) for (j=ymin;j<=ymax;j++) add_pix(xmin,j,coul);
	if (ymin==ymax) for (i=xmin;i<=xmax;i++) add_pix(i,ymin,coul);
	
	
	// La variation la plus grande est en x
	if ((xmax-xmin >= ymax-ymin) && (ymax-ymin>0)) {
		a = (float)(p1.y-p2.y) / ((float)(p1.x-p2.x));
		b = p1.y - a*p1.x;
		for (i=xmin;i<=xmax;i++) {
			jj = a*i+b;
			j = jj;
			if (((jj-j) > 0.5) && (j < hauteur-1)) j++;
			add_pix(i,j,coul);
		}
	}
	
	// La variation la plus grande est en y
	if ((ymax-ymin > xmax-xmin) && (xmax-xmin>0)) {
		a = (float)(p1.y-p2.y) / ((float)(p1.x-p2.x));
		b = p1.y - a*p1.x;
		for (j=ymin;j<=ymax;j++) {
			ii = (j-b)/a;
			i = ii;
			if (((ii-i) > 0.5) && (i < largeur-1)) i++;
			add_pix(i,j,coul);
		}
	}
}

void Fenetre::draw_line(sf::Vector2f p1, sf::Vector2f p2, sf::Color color){
	draw_line(sf::Vector2i((double) p1.x, (double) p1.y), sf::Vector2i((double) p2.x, (double) p2.y), color);
}


//fonction prise dans uvsqgraphics
sf::Vector2i Fenetre::wait_clic(){
	bool encore = true;
	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	printf("En attente de clic GAUCHE ... %4d %4d\r",mousePos.x, mousePos.y); fflush(stdout);
	sf::Event event;
	while(encore && window->waitEvent(event)){
		if(event.type == sf::Event::Closed)
			close();
		if (event.type == sf::Event::MouseMoved){
			mousePos = sf::Mouse::getPosition(*window);
			printf("En attente de clic GAUCHE ... %4d %4d\r",mousePos.x, mousePos.y); fflush(stdout);
		}
		if (event.type == sf::Event::MouseButtonPressed){
			if (event.mouseButton.button == sf::Mouse::Left){
				mousePos = sf::Mouse::getPosition(*window);
				encore = false;
			}
		}
		window->display();
	}
	printf("Clic GAUCHE en %4d %4d               \n",mousePos.x, mousePos.y); fflush(stdout);
	return mousePos;
}

sf::Keyboard::Key Fenetre::getKey(bool& pressed){
	sf::Event event;
	while (window->pollEvent(event)){
		if (event.type == sf::Event::Closed){
			window->close();
		}
		if(event.type == sf::Event::KeyPressed){
			pressed = true;
			return event.key.code;
		}
		
		if(event.type == sf::Event::KeyReleased){
			pressed = false;
			return event.key.code;
		}
	}
	return sf::Keyboard::Unknown;
}

int Fenetre::getLargeur(){
	return largeur;
}

int Fenetre::getHauteur(){
	return hauteur;
}

short Fenetre::getZoom(){
	return zoom_cases;
}
