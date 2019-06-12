#ifndef Block_hpp
#define Block_hpp

class Block{
	private :
		sf::Sprite& sprite;
		sf::Vector2i position;
	
	public :
		bool draw(Fenetre&);
		bool drawCases(Fenetre&);
		isHitted();
};

#endif //Block_hpp
