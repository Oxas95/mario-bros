#include "carte.hpp"
#include "global.hpp"

Carte::Carte(){
    usingArray = false;
    debut = NULL;
    tab_carte = NULL;
    background = NULL;
    size = 0;
    sizeListe = 0;
}

Carte::Carte(const char* path){
    usingArray = true;
    debut = NULL;

    //temporaire
    tab_carte = NULL;
    background = NULL;
    size = 0;
    sizeListe = 0;
    ////////////
}

Carte::~Carte(){
    int i,j;
    if(usingArray){
        for(i = 0; i < size; i++){
            for(j = 0; j < nbCasesY; j++)   delete tab_carte[i][j];
            delete [] tab_carte[i];
        }
        delete [] tab_carte;
    }
    else 
        for(i = 0; i < size; i++)
            while (debut)
                suppColonne();
}

void Carte::ajoutBlock(Block* b, bool isBlockBackground){
    int i = 0;
    if(b){
        if(isBlockBackground){
            //ajout trié si pas de collision, sinon apres celui avec collision
        }
        else if(usingArray && tab_carte){
            if(b->getPosition().y < 0 || b->getPosition().y >= nbCasesY)      delete b;
            else if(b->getPosition().x < 0 || b->getPosition().x >= size)     delete b;

            else if(tab_carte[b->getPosition().x][b->getPosition().y])        delete b;
            else tab_carte[b->getPosition().x][b->getPosition().y] = b;
        }
        else {
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
    int i = 0;
    if(isBlockBackground){
        if(background){
            if(background->next){
                listeBlocks* copie = background;
                while(copie->next->next && copie->next->backgroundBlock->getPosition() != pos) copie = copie->next;
                if(copie->next){
                    if(copie->next->backgroundBlock->getPosition() == pos){
                        listeBlocks* supp = copie->next;
                        copie->next = copie->next->next;
                        delete supp;
                    }
                }
            }
            else if(background->backgroundBlock->getPosition() == pos){
                delete background;
                background = NULL;
            }
        }
    }
    else if(usingArray){
        if(pos.y >= 0 || pos.y < nbCasesY)
            if(pos.x >= 0 || pos.x < size)
                if(tab_carte[pos.x][pos.y]){
                    delete tab_carte[pos.x][pos.y];
                    tab_carte[pos.x][pos.y] = NULL;
                }
    }
    else {
        Colonne* copie = debut;
        while (copie && i < pos.x){
            copie = copie->next;
            i++;
        }
        if(!(!copie || i < pos.x - 1)){
            delete copie->tab[pos.y];
            copie->tab[pos.y] = NULL;
        }
    }
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
    size++;
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
        size--;
    }
    
    if(background){
        if(background->next){
            listeBlocks* copie = background;
            while(copie->next->next && copie->next->backgroundBlock->getPosition().x <= size) copie = copie->next;
            if(copie->next->next){
                liste_block* copie2 = copie;
                copie2 = copie->next;
                delete copie->next;
                copie->next = NULL;
                while(copie2) {
                    copie = copie2;
                    copie2 = copie2->next;
                    delete copie;
                }
            }
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
