#ifndef input_h
#define input_h

#include "fenetre.h"
#include <iostream>
#include <string>

using namespace std;

class Input{
    private :
        char* str;
        int id;
        static int nbInstance;
        static int nbInstanceActif;
        static int focus;
        sf::Vector2i posInput;
        int sizeText; //sizeY
        int maxChar;
        Fenetre *w;
        int cursor;
    public :
        static sf::Vector2i clic;
		
        Input(Fenetre* w, sf::Vector2i posInput, int sizeText, int maxChar);
        ~Input();
        char* getString();
        void drawInput();
        static sf::Keyboard::Key get_clic(Fenetre& w);
};


#endif //input_h
