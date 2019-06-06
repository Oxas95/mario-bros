#ifndef IA_h
#define IA_h

#include "Joueur.h"

class IA : public Joueur{
	private :
		bool tire;
	public :
		IA(int x, int y,int vie,bool bleu,bool tire);
		bool& get_tire();
		void set_tire(bool tire);
		virtual ~IA();
};

#endif // IA_h
