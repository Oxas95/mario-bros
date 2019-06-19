#include "carte.hpp"
#include "global.h"

Carte::Carte(){
    usingArray = false;
    debut = NULL;
    tab_carte = NULL;
    size = 0;
}

Carte::Carte(const char* path){
    usingArray = true;
    debut = NULL;
}

Carte::~Carte(){
    int i;
    if(usingArray){
        for(i = 0; i < size; i++){
            delete [] tab_carte[i];
        }
        delete [] tab_carte;
    }
    else {
        for(i = 0; i < size; i++){
            while (debut){
                delete [] debut.tab;
                debut = debut->next;            
            }
        }
    }
}

bool Carte::ajoutBlock(Block* b, int x, int y){
    int i = 0;
    if(usingArray){
        if(y < 0 || y >= nbCasesY){
            delete b;
            return false;
        }
        if(x < 0 || x >= size){
            delete b;
            return false;
        }
        tab_carte[x][y] = b;
    }
    else {
        Colonne* copie = debut;
        while (copie && i < x){
            copie = copie->next;
            i++;
        }
        if(!copie || i < x - 1){
            delete b;
            return false;
        }
        copie->tab[y] = b;
    }
    return true;
}

bool Carte::suppBlock(int x, int y){
    int i = 0;
    if(usingArray){
        if(y < 0 || y >= nbCasesY)  return false;
        if(x < 0 || x >= size)      return false;
        delete tab_carte[x][y];
        tab_carte[x][y] = NULL;
    }
    else {
        Colonne* copie = debut;
        while (copie && i < x){
            copie = copie->next;
            i++;
        }
        if(!copie || i < x - 1)     return false;
        delete copie->tab[y];
        copie->tab[y] = NULL;
    }
    return true;
}

void Carte::ajoutColonne(){
    int i;
    if(!debut){
        debut = new Colonne();
        debut->next = NULL;
        for(i = 0; i < nbCasesY; i++)   debut->tab[i] = NULL;
    }
    else {
        Colonne* copie = debut;
        while(copie->next)  copie = copie->next;
        copie->next = new Colonne();
        copie->next->next = NULL;
        for(i = 0; i < nbCasesY; i++)   copie->next->tab[i] = NULL;
    }
}

void Carte::suppColonne(){
    int i;
    if(debut){
        if(debut->next){
            Colonne* copie = debut;
            while(copie->next->next)  copie = copie->next;
            for(i = 0; i < nbCasesY; i++)   delete copie->next->tab[i];
            delete copie->next;
            copie->next = NULL;
        }
        else {
            for(i = 0; i < nbCasesY; i++)   delete debut->tab[i];
            delete debut;
            debut = NULL;
        }
    }
}


/*void Carte::drawAroundJoueur(Fenetre& w, sf::Vector2i posMario){
	sf::Vector2i point, min, max;
	
	//on dessine en decalé en mettant le joueur rouge au centre de la fenetre
	min.x = jr->getPosition().x + jb->get_rayon() - w.getLargeur() / 2;
	min.y = jr->getPosition().y + jb->get_rayon() - w.getHauteur() / 2;
	max.x = min.x + w.getLargeur();
	max.y = min.y + w.getHauteur();
	
	for (unsigned int i = 0; i < entity.size(); i++){ //on dessine les entités qui sont autour
		e_ronde = (Entity_ronde*)entity[i];
		if(e_ronde->getPosition().x + e_ronde->get_rayon() * 2 > min.x && e_ronde->getPosition().x < max.x 
		&& e_ronde->getPosition().y + e_ronde->get_rayon() * 2 > min.y && e_ronde->getPosition().y < max.y){
			point.x = entity[i]->getPosition().x - min.x;
			point.y = entity[i]->getPosition().y - min.y;
			entity[i]->drawAt(w, point);
		}
	}
}*/
