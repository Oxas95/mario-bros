#include <iostream>
#include <unistd.h>
#include "fenetre.h"
#include "input.h"
#include "editeur.h"
#include "jouer.h"

using namespace std;

int fenetreMenu(Fenetre& window){
	int choix = -1;
	while (window.isOpen() && choix < 0){
        sf::Event event;
        while (window.getWindow().pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
                choix = 0;
			}
            if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Up && choix < -1) choix++;
				if(event.key.code == sf::Keyboard::Down && choix > -3 ) choix--;
				if(event.key.code == sf::Keyboard::Return) choix = -choix;
			}
        }
        window.getWindow().clear(sf::Color(160,62,35));
        
		window.drawSprite(0,0,600,500,"fond.png");

        window.write("Jouer une partie", 40, sf::Color::Black, 170, 100);
        window.write("Creer une carte", 40, sf::Color::Black, 180, 220);
		window.write("Quitter", 40,sf::Color::Black,240,340);
        
        if(choix == -1){
			window.write(">", 40, sf::Color::Black, 120, 100);
		}
		else if(choix == -2){
			window.write(">", 40, sf::Color::Black, 120, 220);
		}
		else if(choix == -3){
			window.write(">", 40, sf::Color::Black, 120, 340);
		}
        
        window.getWindow().display();
    }
	if(choix == 3) choix = 0;
    return choix;
}

int main(int argc, char *argv[]){
    int choix = -1;
    Fenetre window(600,500, "Bataille en Forêt");
    while(choix != 0 && window.isOpen()){
		choix = fenetreMenu(window);
		if(choix == 1){
			cout << "lancement d'une partie\n";
			//jouer
			option(window);
		}
		else if(choix == 2){
			//editeur de carte
			cout << "lancement de l'éditeur de cartes\n";
			editeur(window);
		}
	}
	cout << "l'utilisateur a quitté\n";
}
