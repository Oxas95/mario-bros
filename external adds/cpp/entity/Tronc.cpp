#include "Tronc.h"

Tronc::Tronc(int x, int y, int sizeX,int sizeY, int vie) : Entity_rect(x,y,sizeX,sizeY,vie){
	if(sizeX == 50 && sizeY == 25)
		set_texture("Tronc_50x25px.png");
	
	if(sizeX == 80 && sizeY == 40)
		set_texture("Tronc_80x40px.png");
	
	if(sizeX == 120 && sizeY == 60)
		set_texture("Tronc_120x60px.png");
}
Tronc::~Tronc(){
	printf("destruction Tronc\n");
}

entityType Tronc::getType(){
	return tronc; //4
}
void Tronc  :: save ( FILE* fs)
{
	fprintf( fs, "tronc \n" ); 
	if (size.x == 50)  fprintf( fs, "%d\n",petit  );
	if (size.x == 80)  fprintf( fs, "%d\n",moyen );
	if (size.x == 120) fprintf( fs, "%d\n",grand );
	Entity_rect :: save (fs); 
}
