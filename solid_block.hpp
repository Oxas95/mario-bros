#ifndef solid_block_hpp
#define solid_block_hpp

#include "Block.hpp"
#include "texture.hpp"
#include "global.hpp"
#include "carte.hpp"

typedef enum{
	block,
	ground,
	hit
}solid_blockType;


class Solid_block : public Block{
	private :
		
	
	public :
		Solid_block(solid_blockType, areaType, int x, int y);
		virtual ~Solid_block();
};

#endif //solid_block_hpp
