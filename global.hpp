#ifndef global_hpp
#define global_hpp

#include <SFML/Graphics.hpp>

//pour faire sizeof(cases)
typedef char cases[8];
typedef char bigcases[16]; 

#define nbCasesX 16 * 2
#define nbCasesY 14 * 2
#define nbBigCasesX 16
#define nbBigCasesY 14

/*
typedef enum{
	b_coin,
	brick,
	coin
}blockType;*/

//colors
#define skyColor sf::Color(107,140,255)

#endif //global_hpp
