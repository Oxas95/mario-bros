//modele a ne pas supprimer
int fenetre(){
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);
        window.display();
    }
    return 0;
}

void fenetre2(){
	sf::Texture texture;
	if (!texture.loadFromFile("Textures/rocher.png")){
		cout << "erreur de chargement de la texture\n";
	}
	
	sf::Sprite sprite;
	sprite.setTexture(texture);
	
	sprite.setTextureRect(sf::IntRect(0, 0, 29, 21));
	
	sprite.setPosition(sf::Vector2f(100.f, 100.f));
	int i = 0, j = 0;
	int move = 1;
	bool vis = true;
    Fenetre w(900,500, "toto");
    while (w.isOpen()){
		sf::Event event;
        while (w.getWindow().pollEvent(event)){
            if (event.type == sf::Event::Closed)
                w.close();
            if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Left)i-= move;
				if(event.key.code == sf::Keyboard::Right)i+= move;
				if(event.key.code == sf::Keyboard::Up)j-= move;
				if(event.key.code == sf::Keyboard::Down)j+= move;
				if(event.key.code == sf::Keyboard::A)move++;
				if(move > 0 && event.key.code == sf::Keyboard::Q)move--;
				if(event.key.code == sf::Keyboard::V)vis = !vis;
			}
        }
        w.getWindow().clear(sf::Color::White);
        
        sprite.setPosition(sf::Vector2f(i, j));
        if(vis)w.getWindow().draw(sprite);
        
        w.getWindow().display();
	}
    w.close();
}
