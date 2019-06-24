#include "carte.hpp"
#include "global.hpp"

Carte::Carte() : joueur(3,24){
    usingArray = false;
    debut = NULL;
    tab_carte = NULL;
    background = NULL;
    int i;
    size = 0;
    for(i = 0; i < nbCasesX; i++) ajoutColonne();

}

Carte::Carte(const char* path){
    usingArray = true;
    debut = NULL;

    //temporaire
    tab_carte = NULL;
    background = NULL;
    size = 0;
    ////////////
}

Carte::~Carte(){
    int i,j;
    if(usingArray){
        for(i = 0; i < size; i++){
            for(j = 0; j < nbCasesY; j++) 
                if(tab_carte[i][j]) delete tab_carte[i][j];
            delete [] tab_carte[i];
        }
        delete [] tab_carte;
    }
    else {
        Colonne* copie;
        while(debut){
            for(j = 0; j < nbCasesY; j++) 
                if(debut->tab[j]){ 
                    delete debut->tab[j];
                }
            copie = debut->next;
            delete debut;
            debut = copie;
        }
    }
    listeBlocks* copie = background;
    while(background){
        copie = background->next;
        delete background->backgroundBlock;
        delete background;
        background = copie;
    }
}

//recherche l'indice du dernier block en collision avec b dans la liste, ou -1 si pas de collision
int collision(listeBlocks* liste, Block* b){
    if(liste){
        int i = 0, j;
        while(1){
            if(liste->backgroundBlock->isHitted(b)) {
                j = collision(liste->next, b);
                if(j != -1) return j;
                return i;
            }
            else if (!liste->next) return -1;
            liste = liste->next;
            i++;
        }
    }
    else return -1;
}

//ajout au début sauf s'il y a collision dans ce cas, l'ajout se fait apres l'indice indiquant une collision
listeBlocks* ajoutBlockBackground(listeBlocks* liste, Block* b){
    listeBlocks* nouveau = new listeBlocks();
    nouveau->backgroundBlock = b;

    if(liste){
        int i = collision(liste,b),j;
        if(i > -1){
            listeBlocks* copie = liste;
            for(j = 0; j < i - 1; j++) copie = copie->next;
            listeBlocks* suivant = copie->next;
            copie->next = nouveau;
            nouveau->next = suivant;
            return liste;
        }
    }
    nouveau->next = liste;
    return nouveau;
}

void Carte::ajoutBlock(Block* b, bool isBlockBackground){
    int i = 0;
    if(b){
        if(isBlockBackground){
            //ajout trié si pas de collision, sinon apres la/les collision(s)
            listeBlocks *copie = background;
            if(background){
                if(b->getPosition().x < copie->backgroundBlock->getPosition().x){
                    background = ajoutBlockBackground(copie, b);
                }
                else {
                    if(background->next){
                        while(copie->next->next && b->getPosition().x >= copie->next->backgroundBlock->getPosition().x) copie = copie->next;
                        copie->next = ajoutBlockBackground(copie->next, b);
                    }
                    else copie->next = ajoutBlockBackground(copie->next, b);
                }
            }
            else background = ajoutBlockBackground(background,b);
        }
        else if(usingArray && tab_carte){
            if(b->getPosition().y < 0 || b->getPosition().y >= nbCasesY)      delete b;
            else if(b->getPosition().x < 0 || b->getPosition().x >= size)     delete b;

            else if(tab_carte[b->getPosition().x][b->getPosition().y])        delete b;
            else tab_carte[b->getPosition().x][b->getPosition().y] = b;
        }
        else if(debut) {
            Colonne* copie = debut;
            while (copie && i < b->getPosition().x){
                copie = copie->next;
                i++;
            }
            if(!copie)                                                        delete b;
            else copie->tab[b->getPosition().y] = b;
        }
    }
}

void Carte::suppBlock(bool isBlockBackground, int x, int y){
    suppBlock(isBlockBackground,sf::Vector2i(x,y));
}

void Carte::suppBlock(bool isBlockBackground, sf::Vector2i pos){
    if(isBlockBackground){
        if(background){
            if(background->next){
                listeBlocks* copie = background;
                while(copie->next->next && copie->next->backgroundBlock->getPosition() != pos) copie = copie->next;
                if(copie->next->backgroundBlock->getPosition() == pos){
                    listeBlocks* supp = copie->next;
                    copie->next = copie->next->next;
                    delete supp->backgroundBlock;
                    delete supp;
                }
            }
            else if(background->backgroundBlock->getPosition() == pos){
                delete background;
                background = NULL;
            }
        }
    }
    else if(usingArray && tab_carte){
        if(pos.y >= 0 || pos.y < nbCasesY){
            if(pos.x >= 0 || pos.x < size){
                if(tab_carte[pos.x][pos.y]){
                    delete tab_carte[pos.x][pos.y];
                    tab_carte[pos.x][pos.y] = NULL;
                }
            }
        }
    }
    else if(debut){
        int i = 0;
        Colonne* copie = debut;
        while (copie && i < pos.x){
            copie = copie->next;
            i++;
        }
        if(i == pos.x - 1){
            if(copie->tab[pos.y]){
                delete copie->tab[pos.y];
                copie->tab[pos.y] = NULL;
            }
        }
    }
}

void Carte::ajoutColonne(){
	printf("ajout Colonne size : %d\n",size + 1);
    int i;
    if(debut){
        Colonne* copie = debut;
        while(copie->next) copie = copie->next;
        copie->next = new Colonne();
        copie->next->next = NULL;
        for(i = 0; i < nbCasesY; i++) copie->next->tab[i] = NULL;
    }
    else {
        debut = new Colonne();
        for(i = 0; i < nbCasesY; i++) debut->tab[i] = NULL;
        debut->next = NULL;
    }
    size++;
}

bool Carte::ajoutColonne(int posX){
    if(posX >= size) return false;
    if(posX == size -1){
        ajoutColonne();
        return true;
    }
    int i;
    if(posX == 0){
        Colonne* nouveau = new Colonne();
        for(i = 0; i < nbCasesY; i++) nouveau->tab[i] = NULL;
        nouveau->next = debut;
        debut = nouveau;
        size++;
        return true;
    }
    else {
        Colonne* copie = debut;
        for(i = 0; i < posX - 1; i++) copie = copie->next;
        for(i = 0; i < nbCasesY; i++) if(copie->next->tab[i]) return false;
        Colonne* nouveau = new Colonne();
        for(i = 0; i < nbCasesY; i++) nouveau->tab[i] = NULL;
        Colonne* suivant = copie->next;
        copie->next = nouveau;
        nouveau->next = suivant;
        size++;
        return true;
    } 
}

bool Carte::suppColonne(){
    int i;
    if(size > nbCasesX){
        Colonne* copie = debut;
        while(copie->next->next)  copie = copie->next;
        for(i = 0; i < nbCasesY; i++) if(copie->next->tab[i]) return false;
        for(i = 0; i < nbCasesY; i++) if(copie->tab[i]) return false;

        if(background){
            listeBlocks* copie = background;
            while(copie->next && copie->backgroundBlock->getPosition().x < size) copie = copie->next;
            if(copie) return false;
        }

        delete copie->next;
        copie->next = NULL;
        
        size--;
        return true;
    }
    return false;
}

void Carte::draw(Fenetre& w){
    int i,j;
    if(debut){
        Colonne* copie = debut;
        for(i = 0; i < size; i ++){
            for(j = 0; j < nbCasesY; j++)
                if(copie->tab[j]) copie->tab[j]->drawAtCases(w,copie->tab[j]->getPosition().x, copie->tab[j]->getPosition().y);
				if(copie) copie = copie->next;
				else printf("erreur size, i = %d, size = %d",i,size);
        }
    }
    joueur.drawAt(w,joueur.getPosition().x * w.getZoom(), joueur.getPosition().y * w.getZoom());
}

/*void Carte::drawAroundJoueur(Fenetre& w, sf::Vector2i posMario){
	sf::Vector2i point, min, max;
	
	//on dessine en decalé en mettant le joueur rouge au centre de la fenetre
	min.x = posMario.x + sizeof(bigcases) - w.getLargeur() / 2;
	min.y = posMario.y + sizeof(bigcases) - w.getHauteur() / 2;
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
