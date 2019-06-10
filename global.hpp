#ifndef global_hpp
#define global_hpp

#include <SFML/Graphics.hpp>

//pour faire sizeof(cases)
typedef char cases[8];
typedef char bigcases[16]; 

#define elseif_buttonResize() 	else if(k == sf::Keyboard::Num1 && w.getZoom() != 1) w.resize(1), affiche_textures(w);\
								else if(k == sf::Keyboard::Num2 && w.getZoom() != 2) w.resize(2), affiche_textures(w);\
								else if(k == sf::Keyboard::Num3 && w.getZoom() != 3) w.resize(3), affiche_textures(w);\
								else if(k == sf::Keyboard::Num4 && w.getZoom() != 4) w.resize(4), affiche_textures(w);\
								else if(k == sf::Keyboard::Num5 && w.getZoom() != 5) w.resize(5), affiche_textures(w)

#define nbCasesX 16 * 2
#define nbCasesY 14 * 2
#define nbBigCasesX 16
#define nbBigCasesY 14

#define skyColor sf::Color(107,140,255)

#endif //global_hpp
