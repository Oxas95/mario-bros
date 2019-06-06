#ifndef jouer_h
#define jouer_h

#include "fenetre.h"
#include "entity/Joueur.h"

#define Jb c.getJoueurBleu()
#define Jr c.getJoueurRouge()

#define IAb c.getIABleu()
#define IAr c.getIARouge()

#define PI 3.14159265

void drawFond(Fenetre& w, Joueur& J, int largeur, int hauteur);
void JoueurVie (Fenetre& w,int J_vie);
void option(Fenetre& w);

#endif //jouer_h
