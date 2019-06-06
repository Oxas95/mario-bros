#include "graphics.h"
#include "paint.h"
#include "global.h"
#include "mario editor.h"
#include "mario bros.h"


void charger_touches(){
	param=fopen("parametre.txt","r");
	if(param==NULL){
		param=fopen("parametre.txt","w");
		fprintf(param,"%d %d %d %d %d %d",'z','s','q','d','i','o');
	}
	char b=fscanf(param,"%d %d %d %d %d %d",&keyc.up,&keyc.down,&keyc.left,&keyc.right,&keyc.run,&keyc.jump);
	printf("%d",b);
	fclose(param);
}

void parametre(){
	char touche=-1;
	int control[6]={-1,-1,-1,-1,-1,-1};
	POINT p={250,310};
	attendre(500);
	for(int i=0;i<6;i++){
		fill_screen(black);
		switch(i){
			case 0 : aff_pol("haut",30,p,white);   break;
			case 1 : aff_pol("bas",30,p,white);    break;
			case 2 : aff_pol("gauche",30,p,white); break;
			case 3 : aff_pol("droite",30,p,white); break;
			case 4 : aff_pol("courir",30,p,white); break;
			case 5 : aff_pol("sauter",30,p,white); break;
		}
		affiche_all();
		
		while(touche==-1)touche=getkey_down();
		control[i]=touche;
		touche=-1;
		
		attendre(1000);
	}
	
	param=fopen("parametre.txt","w+");
	fprintf(param,"%d %d %d %d %d %d",control[0],control[1],control[2],control[3],control[4],control[5]);
	keyc.up=control[0]; keyc.down=control[1]; keyc.left=control[2]; keyc.right=control[3]; keyc.run=control[4]; keyc.jump=control[5];
	fclose(param);
}


void efface_le_o(){
	POINT p1={0,0},p2={120,310};
	draw_fill_rectangle(p1,p2,ciel);
}



int main(){
	init_graphics(600,600);
	SDL_WM_SetCaption("Mario Bros",NULL);
	
	revenir_menu();
	POINT choix={80,300};
	char touche=-1;
	charger_touches();

	affiche_auto_off();
	while(1){
		
		efface_le_o();
		
		
		touche=getkey_down();
		if(touche==keyc.up){
			if(choix.y<300){
				choix.y+=80;
				attendre(200);
			}
		}
		if(touche==keyc.down){
			if(choix.y>60){
				choix.y-=80;
				attendre(200);
			}
		}
		aff_pol("o",30,choix,white);
		
		if(touche==SDLK_RETURN){
			switch(choix.y){
				case 300  : playing(); break;
				case 220  : mario_editor(); break;
				case 140  : parametre(); break;
				case 60   : exit(0); break;
				default : break;
			}
			revenir_menu();
		}
		affiche_all();
	}
}

