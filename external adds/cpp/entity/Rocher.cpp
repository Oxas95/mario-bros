#include "Rocher.h"

Rocher::Rocher(int x, int y, int rayon, int vie) : Entity_ronde(x,y,rayon,vie){
	if(rayon == 20)
		set_texture("Rocher_40px.png");
	
	if(rayon == 50)
		set_texture("Rocher_100px.png");
	
	if(rayon == 80)
		set_texture("Rocher_160px.png");
}
Rocher::~Rocher(){
	printf("destruction Rocher\n");
}

entityType Rocher::getType(){
	return rocher; //3
}
void Rocher   :: save ( FILE* fs)
{
	fprintf( fs, "rocher  \n" ); 
	if (rayon == 20) fprintf( fs, "%d\n",petit  );
	if (rayon == 50) fprintf( fs, "%d\n",moyen );
	if (rayon == 80) fprintf( fs, "%d\n",grand );
	Entity_ronde :: save (fs); 
}
