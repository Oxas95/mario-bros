#include "uvsqgraphics.h"
#include "paint.h"

#define quit() printf("erreur : le fichier est corrompu\n"),fclose(f),exit(2);

//variables de dimensions
int tailleW,tailleH,cases,L,H;

char coulp = 0; // pour ne pas enregistrer de couleur precedente dans l'option de couleur personnalisé la premiere fois
char edit;

//couleurs en chiffres
struct couleurchiffre {
	int r;
	int g;
	int b;
};typedef struct couleurchiffre rgb;

rgb ce,cp,cc;

//fonctions

void purger(void){
    
    int c;
    
    while ( ( c=getchar() )!='\n' && c!=EOF);
}

void clean(char *chaine){
    char *p = strchr(chaine, '\n');

    if (p) *p = 0;

    else purger();
}

void carreviolet(int x,int y){
	affiche_auto_off();
	
	POINT haut_d,milieu,haut_g,bas_d,bas_g;
	COULEUR coul1=couleur_RGB(160,160,160), coul2=couleur_RGB(220,220,220);
	
	bas_g.x=(cases*x)+1; bas_g.y=(cases*y)+1;
	haut_d.x=bas_g.x+cases-2; haut_d.y=bas_g.y+cases-2;
	milieu.x=bas_g.x+((cases-2)/2);
	milieu.y=bas_g.y+((cases-2)/2);
	bas_d.y=bas_g.y; bas_d.x=haut_d.x;
	haut_g.x=bas_g.x; haut_g.y=haut_d.y;
	draw_fill_rectangle(bas_g,milieu,coul1);
	draw_fill_rectangle(haut_d,milieu,coul1);
	draw_fill_rectangle(bas_d,milieu,coul2);
	draw_fill_rectangle(haut_g,milieu,coul2);
	affiche_all();
	affiche_auto_on();
}

void efface_grille(int c[tailleW][tailleH][3]){
	char i,j;
    for(i=0;i<tailleW;i++){
		for(j=0;j<tailleH;j++){
			carreviolet(i,j);
		}
	}
	
	int w1,w2,w3;
	for(w1=0;w1<tailleW;w1++){
		for(w2=0;w2<tailleH;w2++){
			for(w3=0;w3<3;w3++){
				c[w1][w2][w3]=-1;
			}	
		}	
	}
	
}

void recup_taille_edition(char *nom){
	FILE *f = NULL;
	f = fopen(nom,"r");
	if(!f) printf("le fichier n'existe pas ou n'a pas pu être ouvert\n"),exit(1);
	if(fscanf(f,"%d%d",&tailleW, &tailleH) != 2)quit();
	fclose(f);
}

void recup_edition(int c[tailleW][tailleH][3], char *nom){ 
	int x,y;
	
	FILE *f = NULL;
	f = fopen(nom,"r");
	if(!f) printf("le fichier n'existe pas ou n'a pas pu être ouvert\n"),exit(1);
	if(fscanf(f,"%d%d",&tailleW, &tailleH) != 2)quit();
	
	for(x = 0; x < tailleW; x ++){
		for(y = 0; y < tailleH; y ++){
			if(fscanf(f,"%d",&c[x][y][0]) != 1)quit();
			if(fscanf(f,"%d",&c[x][y][1]) != 1)quit();
			if(fscanf(f,"%d",&c[x][y][2]) != 1)quit();
		}
	}
	fclose(f);
}

void dessine_grille(int c[tailleW][tailleH][3]){
	affiche_auto_off();
	char i;
	POINT p1,p2;
	COULEUR trait = black;
	
	if(edit != '1')efface_grille(c);
	
	p1.x = p1.y = 0; p2.y = H;
    for(i = 0 ; i < tailleW ; i++){
		p1.x = p2.x = p1.x + cases;
		draw_line(p1,p2,trait);
    }
	
	p1.x = p1.y = 0; p2.x = L;
    for(i = 0 ; i < tailleH ; i++){
		p1.y = p2.y = p1.y + cases;
		draw_line(p1,p2,trait);
    }
    
    if(edit == '1'){
		POINT haut,bas;
		int x,y;
		COULEUR coul;
		for(x = 0; x < tailleW; x ++){
			for(y = 0; y < tailleH; y ++){
				if(c[x][y][0] != - 1){
					coul = couleur_RGB(c[x][y][0],c[x][y][1],c[x][y][2]);
					bas.x = (cases * x) + 1;    bas.y = (cases * y) + 1;
					haut.x = bas.x + cases - 2; haut.y = bas.y + cases - 2;
					draw_fill_rectangle(haut,bas,coul);
				}
				else carreviolet(x,y);
			}
		}
	}
	affiche_auto_on();
	affiche_all();
}

void enregistrer(int c[tailleW][tailleH][3]){
	int w1,w2,w3;
	char* nom_dessin = malloc(30 * sizeof(char));
	printf("nom du dessin : ");
	scanf("%29s",nom_dessin);
	clean(nom_dessin);
	int value = 1;
	
	FILE *f = NULL;
	if((f = fopen(nom_dessin,"r"))){
		printf("une sauvegarde existe déjà à ce nom, voulez-vous l'écraser ? 1 = oui\n");
		scanf("%c",&edit);
		if(edit != '1') value = 0;
	}
	else f = fopen(nom_dessin,"w");
	
	if(value){
		fprintf(f,"%d %d",tailleW, tailleH);
		for(w1 = 0; w1 < tailleW; w1 ++){
			fprintf(f,"\n");
			for(w2 = 0; w2 < tailleH; w2 ++){
				for(w3 = 0 ; w3 < 3; w3 ++)
					fprintf(f,"%d ",c[w1][w2][w3]);
			}
		}
		fclose(f);
	}
	
}


POINT pinceau(int c[tailleW][tailleH][3]){
	affiche_auto_off();
	POINT choix;
	int x,y;
	
	choix = wait_clic();
	
	x = choix.x / cases;
	y = choix.y / cases;
	
	if(x < tailleW && y < tailleH && c[x][y][0] != - 1){
		cc.r = c[x][y][0];
		cc.g = c[x][y][1];
		cc.b = c[x][y][2];
		
		affiche_all();
	}
		
	affiche_auto_on();
	return choix;
}

void dessine_menu(){
	affiche_auto_off();
	POINT p1,p2;
	//taille des cases : 25
	//taille entre les cases : 25
	
	int disquette[1204]={20,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,0,0,0,-1,-1,-1,0,0,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,0,0,0,0,0,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,0,0,0,-1,-1,-1,0,0,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,0,0,0,0,0,0,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,255,66,0,255,66,0,255,66,0,255,66,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,255,66,0,255,66,0,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,0,0,0,0,0,0,120,120,120,120,120,120,-1,-1,-1,-1,-1,-1,-1,-1,-1,120,120,120,255,66,0,255,66,0,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,0,0,0,0,0,0,120,120,120,120,120,120,-1,-1,-1,-1,-1,-1,-1,-1,-1,120,120,120,255,66,0,255,66,0,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,0,0,0,0,0,0,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,255,66,0,255,66,0,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,0,0,0,0,0,0,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,255,66,0,255,66,0,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,0,0,0,0,0,0,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,255,66,0,255,66,0,255,66,0,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,0,0,0,-1,-1,-1,0,0,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,0,0,0,-1,-1,-1,0,0,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,0,0,0,-1,-1,-1,0,0,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,255,255,255,255,255,255,0,0,0,255,255,255,0,0,0,-1,-1,-1,0,0,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,0,0,0,0,0,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,0,0,0,-1,-1,-1,0,0,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,255,66,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int pinceau[679]={15,200,200,200,187,187,187,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,141,141,141,210,230,240,187,187,187,187,187,187,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,141,141,141,213,227,240,213,227,240,187,187,187,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,141,141,141,175,193,210,213,227,240,213,227,240,187,187,187,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,141,141,141,175,193,210,213,227,240,240,240,240,187,187,187,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,141,141,141,175,193,210,240,240,240,240,240,240,187,187,187,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,141,141,141,240,240,240,240,240,240,240,240,240,187,187,187,-1,-1,-1,30,80,140,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,141,141,141,240,240,240,240,240,240,240,240,240,30,80,140,40,120,180,30,80,140,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,141,141,141,240,240,240,30,80,140,40,120,180,40,120,180,30,80,140,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,30,80,140,40,120,180,80,150,200,80,150,200,40,120,180,30,80,140,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,30,80,140,40,120,180,40,120,180,80,150,200,80,150,200,80,150,200,40,120,180,30,80,140,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,30,80,140,30,80,140,40,120,180,80,150,200,80,150,200,80,150,200,40,120,180,30,80,140,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,30,80,140,40,120,180,80,150,200,80,150,200,40,120,180,30,80,140,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,30,80,140,40,120,180,40,120,180,40,120,180,30,80,140,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,30,80,140,30,80,140,30,80,140,-1,-1,-1,-1,-1,-1};

	
	//5eme ligne
	p1.x=L+25, p1.y=25*10, p2.x=p1.x+25; p2.y=p1.y+25;
	draw_rectangle(p1,p2,white);
	p1.x+=5;p1.y+=5;
	draw_paint(pinceau,p1,1);
	//récupérer une couleur
	
	p1.x=L+75, p1.y=25*10, p2.x=p1.x+25; p2.y=p1.y+25;
	draw_rectangle(p1,p2,white);
	p1.x+=2; p1.y+=2;
	draw_paint(disquette,p1,1);
	//enregistrement
	
	//1ere ligne
	p1.x=L+25, p1.y=25*8, p2.x=p1.x+25; p2.y=p1.y+25;
	draw_fill_rectangle(p1,p2,white); 
	
	p1.x=L+75, p1.y=25*8, p2.x=p1.x+25; p2.y=p1.y+25;
	draw_fill_rectangle(p1,p2,red);
	
	p1.x=L+125, p1.y=25*8, p2.x=p1.x+25; p2.y=p1.y+25;
	draw_fill_rectangle(p1,p2,blue);
	
	
	//2eme ligne
	
	p1.x=L+25, p1.y=25*6, p2.x=p1.x+25; p2.y=p1.y+25;
	draw_fill_rectangle(p1,p2,couleur_RGB(0,180,0)/*le vert*/);
	
	p1.x=L+75, p1.y=25*6, p2.x=p1.x+25; p2.y=p1.y+25;
	draw_fill_rectangle(p1,p2,jaune);
	
	p1.x=L+125, p1.y=25*6, p2.x=p1.x+25; p2.y=p1.y+25;
	draw_fill_rectangle(p1,p2,black);
	
	
	//3eme ligne
	p1.x=L+25, p1.y=25*4, p2.x=p1.x+25; p2.y=p1.y+25;
	draw_rectangle(p1,p2,white); draw_line(p1,p2,white);
	
	p1.x=L+75, p1.y=25*4, p2.x=p1.x+25; p2.y=p1.y+25;
	draw_rectangle(p1,p2,white);
	p1.x+=(25/2)-3; p1.y+=(25/2)+8;
	aff_pol("+",10,p1,white);
	
	
	//4eme ligne
	p1.x=L+75, p1.y=25*2, p2.x=p1.x+25; p2.y=p1.y+25;
	draw_rectangle(p1,p2,white);
	draw_line(p1,p2,white);
	int y=p2.y;
	p2.y=p1.y; p1.y=y;
	draw_line(p1,p2,white);//efface tout
	affiche_all();
	affiche_auto_on();
}

void choisir_couleur(POINT choix,int c[tailleW][tailleH][3]){
	POINT p1,p2;
	
	//1ere colonne
	if (choix.x<=L+50 && choix.x>=L+25){
		
		if(choix.y<=25*11 && choix.y>=25*10){choix=pinceau(c);}
		if(choix.y<=25*5 && choix.y>=25*4){cc.b=cc.g=cc.r=-1;/*vide*/}
		if(choix.y<=25*9 && choix.y>=25*8){cc.b=cc.g=cc.r=255;/*blanc*/}
		if(choix.y<=25*7 && choix.y>=25*6){/*le vert */cc.g=180; cc.b=cc.r=0;}
		if(choix.y<=25*3 && choix.y>=25*2){ if(coulp){cc.b=cp.b; cc.g=cp.g; cc.r=cp.r;/* couleur precedemment enregistré*/} }
	}
	
	//2eme colonne
	if (choix.x>=L+75 && choix.x<=L+100){
		if(choix.y<=25*11 && choix.y>=25*10){enregistrer(c);}//enregistrement du dessin
		if(choix.y<=25*5 && choix.y>=25*4){//enregistre une nouvelle couleur
			if(coulp){
				cp.r=ce.r; cp.g=ce.g; cp.b=ce.b;
				coulp=2;
				p1.x=H+25, p1.y=25*2, p2.x=p1.x+25; p2.y=p1.y+25;
				draw_fill_rectangle(p1,p2,couleur_RGB(cp.r,cp.g,cp.b));
				draw_rectangle(p1,p2,white);
			}
			coulp=1;
			printf("rouge : "); cc.r=ce.r=lire_entier_clavier();
			printf("vert : "); cc.g=ce.g=lire_entier_clavier();
			printf("bleu : "); cc.b=ce.b=lire_entier_clavier();
			p1.x=H+125; p1.y=25*4; p2.x=p1.x+25; p2.y=p1.y+25;
			draw_fill_rectangle(p1,p2,couleur_RGB(ce.r,ce.g,ce.b));
			draw_rectangle(p1,p2,white);
		}
		if(choix.y<=225 && choix.y>=200){/*red*/ cc.r=255; cc.g=cc.b=0;}
		if(choix.y<=25*7 && choix.y>=25*6){/*jaune*/ cc.b=0; cc.g=cc.r=255;}
		if(choix.y<=25*3 && choix.y>=25*2){efface_grille(c);}//efface tout
	}
	
	//3eme colonne
	if (choix.x >= L + 125 && choix.x <= L + 150){
		if(choix.y <= 25 * 5 && choix.y >= 25 * 4){ 
			if(coulp) {cc.r = ce.r; cc.g = ce.g; cc.b = ce.b;} 
		}
		if(choix.y <= 25 * 9 && choix.y >= 25 * 8){/*bleu*/ cc.r = cc.g=0; cc.b = 255;}
		if(choix.y <= 25 * 7 && choix.y >= 25 * 6){/*black*/ cc.r = cc.g = cc.b = 0;}
		if(choix.y <= 25 * 3 && choix.y >= 25 * 2);/*rien pour l'instant*/
	}
}


void affiche_couleur(POINT choix, int c[tailleW][tailleH][3]){
	int x,y;
	x = choix.x / cases;
	y = choix.y / cases;
	c[x][y][0] = cc.r; c[x][y][1] = cc.g; c[x][y][2] = cc.b;
	
	if(cc.g == -1) carreviolet(x,y);
	else {
		POINT haut,bas;
		bas.x = (cases * x) + 1; bas.y = (cases * y) + 1;
		haut.x = bas.x + cases - 2; haut.y = bas.y+cases - 2;
		draw_fill_rectangle(bas,haut,couleur_RGB(cc.r,cc.g,cc.b));
	}
}

int main(){
	cc.r = cc.g = cc.b = - 1;
	ce = cp = cc;
	char *nom = malloc(sizeof(char) * 30);
	
	printf("voulez vous éditer un dessin ?  1 = oui\n");
	edit = getchar(); purger();
	
	if(edit == '1'){
		printf("entrez le nom du dessin à éditer : \n");
		scanf("%29s",nom); purger();
		recup_taille_edition(nom);
	}
	
	else{	
		printf("quelle taille de quadrillage voulez vous horizontalement ?\n");
		tailleW = lire_entier_clavier();
		printf("quelle taille de quadrillage voulez vous verticalement ?\n");
		tailleH = lire_entier_clavier();
	}
	
	int c[tailleW][tailleH][3];
	if(tailleH > tailleW)	cases = 600 / tailleH;
	else					cases = 600 / tailleW;
	
	L = tailleW * cases;
	H = tailleH * cases;
	
	if(edit == '1')recup_edition(c,nom);
	
	init_graphics(L + 200, (H < 400) ? 400 : H);
	SDL_WM_SetCaption("painter",NULL);
	fill_screen(gris);
	dessine_grille(c);
	dessine_menu();
	
	POINT choix,p1,p2;
	p1.x = L + 50;  p1.y = ((H < 400) ? 400 : H) - 100;
	p2.x = L + 125; p2.y = ((H < 400) ? 400 : H) - 25;
	
	while(1){
		//commencer à dessiner
		draw_fill_rectangle(p1,p2,couleur_RGB(cc.r,cc.g,cc.b));
		if(cc.r == - 1) draw_line(p1,p2,black);
		
		choix = wait_clic();
		
		if(choix.x > L-1) choisir_couleur(choix,c);
		
		else if(choix.x <= L-1 && choix.y <= H - 1) affiche_couleur(choix,c);
		
	}

	wait_escape();
	exit(0);
}
