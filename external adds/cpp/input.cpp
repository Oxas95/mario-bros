#include "input.h"

bool findFocus = false;
int Input::nbInstance = 0;
int Input::nbInstanceActif = 0;
sf::Vector2i Input::clic(0,0);
int Input::focus = -1;
bool maj = false;

void Input::drawInput(){
	if(clic.x >= posInput.x && clic.x <= posInput.x + 200 && clic.y >= posInput.y && clic.y <= posInput.y + sizeText){
		focus = id;
		findFocus = true;
	}
	int reduce;
	string s;
	int sizeX;
	if(focus == id){
		sf::Event event;
		while (w->getWindow().pollEvent(event)){
			if (event.type == sf::Event::Closed){
				w->close();
			}
			else if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Return)clic.x = -10, focus = -1;
				if(cursor < maxChar - 1){
					if(event.key.code >= 0 && event.key.code <= 25){
						if(!maj) str[cursor++] = 'a' + event.key.code;
						else str[cursor++] = 'A' + event.key.code;
					}
					//if(event.key.code == sf::Keyboard::Space) str[cursor++] = ' ';
				}
				if(cursor > 0){
					if(event.key.code == sf::Keyboard::BackSpace) str[--cursor] = '\0';
				}
				if(event.key.code == sf::Keyboard::LShift) maj = true;
			}
			if(event.type == sf::Event::KeyReleased){
				if(event.key.code == sf::Keyboard::LShift) maj = false;
			}
			if (event.type == sf::Event::MouseButtonPressed){
				if (event.mouseButton.button == sf::Mouse::Left){
					clic = sf::Mouse::getPosition(w->getWindow());
					focus = -2;
				}
			}
		}
	}
	reduce = 0;
	sizeX = w->getFont(str, sizeText);
	s = str;
	while(sizeX > 200){
		reduce++;
		sizeX = w->getFont(s.substr(reduce,s.length()).c_str(), sizeText);
	}
	w->drawRect(posInput.x,posInput.y,200, sizeText, sf::Color(127,127,127));
	if(focus != id) w->drawRect(posInput.x,posInput.y,200, sizeText, sf::Color::White);
	w->write(s.substr(reduce,s.length()).c_str(),sizeText - 1, sf::Color::Black, posInput.x, posInput.y - sizeText / 8);
}

Input::Input(Fenetre* _w, sf::Vector2i posInput, int sizeText, int maxChar) {
	str = new char[maxChar + 1];
	for (int i = 0; i < maxChar + 1; i++){
		str[i] = '\0';
	}
	w = _w;
	nbInstanceActif++;
	id = nbInstance++;
	this->posInput = posInput;
	this->sizeText = sizeText; //sizeY
	this->maxChar = maxChar;
	cursor = 0;
}

Input::~Input(){
	delete[] str;
	nbInstanceActif--;
	if(nbInstanceActif == 0) focus = -1;
}

char* Input::getString(){
	return str;
}

sf::Keyboard::Key Input::get_clic(Fenetre& w){
	if(findFocus == false) focus = -1;
	if(focus == -1){
		sf::Event event;
		while (w.getWindow().pollEvent(event)){
			if (event.type == sf::Event::Closed){
				w.close();
			}
			if (event.type == sf::Event::MouseMoved){
				printf("En attente de clic GAUCHE ... %4d %4d\r",sf::Mouse::getPosition(w.getWindow()).x,sf::Mouse::getPosition(w.getWindow()).y); fflush(stdout);
			}
			if (event.type == sf::Event::MouseButtonPressed){
				if (event.mouseButton.button == sf::Mouse::Left){
					clic = sf::Mouse::getPosition(w.getWindow());
					printf("Clic GAUCHE en %4d %4d               \n",clic.x, clic.y); fflush(stdout);
				}
			}
			if(event.type == sf::Event::KeyPressed){
				clic.x = clic.y = -1;
				findFocus = false;
				return event.key.code;
			}
		}
	}
	findFocus = false;
	return sf::Keyboard::Unknown;
}
