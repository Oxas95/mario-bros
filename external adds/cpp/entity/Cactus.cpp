#include "Cactus.h"

Cactus::Cactus(int x, int y, int rayon, int vie) : Entity_ronde(x,y,rayon,vie){
	
	if(rayon == 20)
		set_texture("Cactus_40px.png");
	
	if(rayon == 30)
		set_texture("Cactus_60px.png");
	
	if(rayon == 40)
		set_texture("Cactus_80px.png");
}
Cactus::~Cactus(){
	printf("destruction Cactus\n");
}

entityType Cactus::getType(){
	return cactus; //2
}
void Cactus  :: save ( FILE* fs)
{
	fprintf( fs, "cactus \n" ); 
	if (rayon == 20) fprintf( fs, "%d\n",petit  );
	if (rayon == 30) fprintf( fs, "%d\n",moyen );
	if (rayon == 40) fprintf( fs, "%d\n",grand );
	Entity_ronde :: save (fs); 
}
