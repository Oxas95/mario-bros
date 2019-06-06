#include "fenetre.h"
#include <iostream>
#include <string>

using namespace std;

Fenetre::Fenetre(int largeur, int hauteur, string title){
	this->largeur = largeur;
	this->hauteur = hauteur;
	
	window = new RenderWindow(VideoMode(largeur, hauteur), title, sf::Style::Titlebar | sf::Style::Close);
	window->setVerticalSyncEnabled(false);
}

Fenetre::~Fenetre(){
	close();
	delete window;
}

void Fenetre::close(){
	window->close();
}

bool Fenetre::isOpen(){
	return window->isOpen();
}

RenderWindow& Fenetre::getWindow(){
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

bool Fenetre::drawSprite(int x, int y, int Xsize, int Ysize, const char* file){
	sf::Texture texture;
	string str = "Textures/";
	if(file)str.append(file);

	if (!texture.loadFromFile(str)){
		return false;
	}
	
	sf::Sprite sprite;
	sprite.setTexture(texture);
	
	sprite.setTextureRect(sf::IntRect(0, 0, Xsize, Ysize));
	
	sprite.setPosition(sf::Vector2f(x,y));

	window->draw(sprite);
	return true;
}

bool Fenetre::drawSprite(sf::Vector2i position, sf::Vector2i beginTo, sf::Vector2i size, const char* file){
	sf::Texture texture;
	string str = "Textures/";
	if(file)str.append(file);

	if (!texture.loadFromFile(str)){
		return false;
	}
	
	sf::Sprite sprite;
	sprite.setTexture(texture);
	
	sprite.setTextureRect(sf::IntRect(beginTo.x, beginTo.y, size.x, size.y));
	
	sprite.setPosition(sf::Vector2f(position.x, position.y));

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
sf::Vector2f Fenetre::wait_clic(){
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
	}
	printf("Clic GAUCHE en %4d %4d               \n",mousePos.x, mousePos.y); fflush(stdout);
	return sf::Vector2f(mousePos.x,mousePos.y);
}

int Fenetre::getLargeur(){
	return largeur;
}

int Fenetre::getHauteur(){
	return hauteur;
}
