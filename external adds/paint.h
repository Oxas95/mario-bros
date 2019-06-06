#include "dessins.h"

void draw_paint(int pixc[],POINT position,int tc){
	typedef struct C_RGB{int r; int g; int b;} rgbc;
	int WH,WH2,i;
	WH=pixc[0];
	WH2=WH*WH;
	
	int pixc2[WH2*3];
	for (int i = 0; i < WH2*3; i++){
		pixc2[i]=pixc[i+1];
	}
	
	rgbc c[WH2];
	for(i=0;i<WH2;i++){
		c[i].r = pixc2[i*3];
		c[i].g = pixc2[i*3+1];	
		c[i].b = pixc2[i*3+2];	
	}
	int H = 0;
	int W = 0;
	POINT P1,P2;
	for(i=0;i<WH2;i++){
		if (!(c[i].r==-1 && c[i].g==-1 && c[i].b==-1)){
			P1.x = position.x+W*tc;
			P1.y = position.y+H*tc;
			P2.x = position.x+W*tc+tc-1;
			P2.y = position.y+H*tc+tc-1;
			draw_fill_rectangle(P1,P2,couleur_RGB(c[i].r,c[i].g,c[i].b));
		}
		if (H>WH-2){H = 0;W++;}
		else H++;
	}
}
