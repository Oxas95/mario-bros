#include "uvsqgraphics.h"
#include "paint.h"
#define cases 16*4

#define id_mario 1
#define id_brick 2
#define id_background 3


typedef struct mouvementkey {
	char up;
	char left;
	char right;
	char down;
	char vite;
} keymove;

typedef struct info_block{
	POINT p;
	POINT p_h;
	int id;
} block;

keymove key;


void getkey(){
	SDL_Event event;
	
	while (SDL_PollEvent(&event)) {
		
		if (event.type == SDL_QUIT) exit(0);
		
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
				case SDLK_ESCAPE : exit(0);
				case SDLK_LEFT   : key.left=1; break;
				case SDLK_RIGHT  : key.right=1; break;
				case SDLK_SPACE  : key.up=1; break;
				case SDLK_DOWN   : key.down=1; break;
				case SDLK_a      : key.vite=1; break;
				case SDLK_p      : wait_clic(); break;
				default          : break;
			}
		}
		if (event.type == SDL_KEYUP) {
			switch (event.key.keysym.sym) {
				case SDLK_LEFT   : key.left=0; break;
				case SDLK_RIGHT  : key.right=0; break;
				case SDLK_SPACE  : key.up=0; break;
				case SDLK_DOWN   : key.down=0; break;
				case SDLK_a      : key.vite=0; break;
				default          : break;
			}
		}
	}
}

void calcul_position(block *b,int x,int y){
	
	
	b->p.x=(x-1)*cases;
	b->p.y=(y-1)*cases;
	
	b->p_h.x=b->p.x+cases-1;
	b->p_h.y=b->p.y+cases-1;
	
	
	if(b->id==id_mario){
		b->p_h.x=b->p.x+cases-16;
	}
}

void replace_haut(block *mario, block *bloc){

	bloc->p_h.x=bloc->p.x+cases-1;
	bloc->p_h.y=bloc->p.y+cases-1;
	
	mario->p_h.x=mario->p.x+cases-16;
	mario->p_h.y=mario->p.y+cases-1;
}

int main(){
	key.up=key.down=key.left=key.right=key.vite=0;
	init_graphics(cases*15,cases*10);
	SDL_WM_SetCaption("Super Mario Bros PC",NULL);
	COULEUR ciel=couleur_RGB(92,148,252);
	fill_screen(ciel);
	affiche_auto_off();
	
	
	block mario, test;
	
	test.id=id_background;
	mario.id=id_mario;
	
	calcul_position(&test,6,4);
	calcul_position(&mario,6,5);
	
	char tombe=0;
	while(1){
		getkey();
		fill_screen(ciel);
		if(!key.up){//si l'utilisateur ne saute pas il tombe
			mario.p.y-=4;
			tombe=1;
			attendre(8);
		}
		
		
		
		if(key.up){//sauter
			mario.p.y+=4;
			tombe=1;
			attendre(4);	
		}
		
		//deplacer a gauche et a droite
		if(key.left)mario.p.x-=2;
		if(key.right)mario.p.x+=2;
		
		replace_haut(&mario,&test);
		
		
		//collision haut
		if(mario.p.y==test.p_h.y-3 && mario.p_h.x>=test.p.x && mario.p_h.x<=test.p_h.x && key.up==0){
			mario.p.y=test.p_h.y+1;tombe=0;
		}
		if(mario.p.y==test.p_h.y-3 && mario.p.x>=test.p.x && mario.p.x<=test.p_h.x && key.up==0){
			mario.p.y=test.p_h.y+1;tombe=0;
		}
		
		
		//collision bas
		if(mario.p_h.y==test.p.y+3 && mario.p_h.x>=test.p.x && mario.p_h.x<=test.p_h.x && key.up==1){
			mario.p.y=test.p.y-cases;tombe=2;
		}
		if(mario.p_h.y==test.p.y+3 && mario.p.x>=test.p.x && mario.p.x<=test.p_h.x && key.up==1){
			mario.p.y=test.p.y-cases;tombe=2;
		}
		
		//collision droite
		if(mario.p_h.x>=test.p.x && mario.p_h.x<=test.p.x+3 && (mario.p_h.y>=test.p.y && mario.p_h.y<test.p_h.y) && key.right){mario.p.x=test.p.x-16*3-1;}
		if(mario.p_h.x>=test.p.x && mario.p_h.x<=test.p.x+3 && (mario.p.y>=test.p.y && mario.p.y<test.p_h.y) && key.right){mario.p.x=test.p.x-16*3-1;}
		//collision gauche
		if(mario.p.x<=test.p_h.x && mario.p.x>=test.p_h.x-3 && (mario.p_h.y>=test.p.y && mario.p_h.y<test.p_h.y) && key.left){mario.p.x=test.p_h.x+1;}
		if(mario.p.x<=test.p_h.x && mario.p.x>=test.p_h.x-3 && (mario.p.y>=test.p.y && mario.p.y<test.p_h.y) && key.left){mario.p.x=test.p_h.x+1;}
		
		replace_haut(&mario,&test);
		
		
		draw_fill_rectangle(mario.p,mario.p_h,red);
		draw_fill_rectangle(test.p,test.p_h,white);
		affiche_all();
		if(tombe==2){wait_clic();tombe=0;}
		tombe=0;
		
	}
	exit(0);
}
