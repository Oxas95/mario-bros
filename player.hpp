#ifndef player_hpp
#define player_hpp

#include "fenetre.hpp"

typedef enum{
    stop,
    dead,
    jump,
    run,
    turn
} marioPosition;

class Player{
    private :
        sf::Sprite& sprite;
        short size;
        sf::Vector2i position;
        short rotation;
        marioPosition mp;
    
    public :
        Player();
        Player(int x, int y);
        Player(sf::Vector2i position);
        void changeSprite(marioPosition);
        void turnLeft(int zoomFenetre);
        void turnRight(int zoomFenetre);
        void setPosition(int x, int y);
        void setPositionCases(int x, int y);
        void setPosition(sf::Vector2i);
        sf::Vector2i getPosition();
        void drawAt(Fenetre& w, int x, int y);
        void drawAtCase(Fenetre& w, int x, int y);
        void grandir();
        void retrecir();
        short getSize();
        ~Player();
};

#endif //player_hpp
