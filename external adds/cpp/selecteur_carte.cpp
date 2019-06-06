#include "selecteur_carte.h"
#include "Carte.h"
#include <iostream>
#include <string.h>
#include <string>
#include <unistd.h>

using namespace std;

namespace Selecteur {

vector <string> liste_cartes(){
	vector <string> nomCartes;
	char* cstr = new char[37] (); //30 : taille max d'un nom de carte, 6 : taille de ".carte", 1 pour '\0' 
	cstr[0] = '\0';
	system("ls -1 Saves/ > liste_cartes.txt");
	
	string str;
	
	FILE* lc_txt = NULL;
	if( (lc_txt = fopen("liste_cartes.txt", "r"))){
		while(fscanf(lc_txt, "%36s",cstr) == 1){
			str = ""; str.append(cstr);
			if(str.length() > 6){
				if((str.substr(str.length() - 6,str.length())) == ".carte"){
					nomCartes.push_back(str);
				}
			}
		}
		fclose(lc_txt);
	}
	system("rm -f liste_cartes.txt");
	return nomCartes;
}

void insert_in_tab(vector <Carte*> & tabCartes, vector<string> nomCartes, Fenetre& w){
	Carte* c = NULL;
	for (unsigned int i = 0; i < nomCartes.size(); i++){
		c = new Carte(nomCartes[i].substr(0,nomCartes[i].length() - 6).c_str(), false, false, false);
		tabCartes.push_back(c);
	}
}

void supprimer_carte(vector <Carte*> & tabCartes, int& i){
	vector <Carte*> tmp;
	Carte* toSupp = NULL;
	unsigned int j;
	for(j = 0; j < (unsigned)i; j++){
		tmp.push_back(tabCartes[j]);
	}
	toSupp = tabCartes[j++];
	for(; j < tabCartes.size(); j++){
		tmp.push_back(tabCartes[j]);
	}
	delete toSupp;
	tabCartes.clear();
	for(j = 0; j < tmp.size(); j++){
		tabCartes.push_back(tmp[j]);
	}
	tmp.clear();
	i = 0;
	if(tabCartes.size() == 0) i = -1;
}

sf::Keyboard::Key keyPressed(Fenetre& w){
	sf::Event event;
	while (w.getWindow().pollEvent(event)){
		if (event.type == sf::Event::Closed){
			w.close();
		}
		if(event.type == sf::Event::KeyPressed){
			return event.key.code;
		}
	}
	return sf::Keyboard::Unknown;
}

void gestionTouches(sf::Keyboard::Key touche, vector <Carte*> & tabCartes, vector <string> nomCartes, int &i){
	if(touche == sf::Keyboard::Left && i > 0) i--;
	
	if(touche == sf::Keyboard::Right && i < (int)(nomCartes.size() - 1)) i++;
}

const char* select_carte(Fenetre& w){
	
	vector <Carte*> tabCartes;
	vector <string> nomCartes = liste_cartes();
	insert_in_tab(tabCartes, nomCartes, w);
	
	int i = (tabCartes.size() > 0)? 0 : -1;
	sf::Keyboard::Key touche = sf::Keyboard::R;
	
	while(w.isOpen() && touche != sf::Keyboard::Return && i != -1){
		touche = keyPressed(w);
		gestionTouches(touche, tabCartes, nomCartes, i);
		w.getWindow().clear();
		
		if(i != -1) tabCartes[i]->drawMiniature(w);
		else w.write("Aucune carte n'existe", 50, sf::Color::White, 50, 225);
		w.write("[Entree] : valider", 20, sf::Color::White, 10, w.getHauteur() - 40);
		w.getWindow().display();
	}
	
	if(i == -1)return NULL;
	else {
		char* str = new char[nomCartes[i].length() + 1](); str[0] = '\0';
		strcpy(str,nomCartes[i].c_str());
		return str;
	} 
}


}//namespace Select
