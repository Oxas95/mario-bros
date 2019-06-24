#include "solid_block.hpp"
#include "texture.hpp"

Solid_block::Solid_block(solid_blockType typeBlock, areaType area, int x, int y) : Block(x,y) {
    switch(typeBlock){
        case block  : Block::setSprite(&textures::block[area]);  break;
        case ground : Block::setSprite(&textures::ground[area]); break;
        case hit    : Block::setSprite(&textures::hit[area]);    break;
    }
}

Solid_block::~Solid_block(){
    
}

