ISFML = -I/usr/local/include
LSFML = -lsfml-graphics -lsfml-window -lsfml-system -L/usr/local/lib
RSFML = export LD_LIBRARY_PATH=/usr/local/lib &&

ficCpp = mario.cpp	texture.cpp	Collision.cpp	fenetre.cpp				menu.cpp	play.cpp	Block.cpp	carte.cpp
ficH   = 			texture.hpp	Collision.hpp	fenetre.hpp	global.hpp	menu.hpp	play.hpp	Block.hpp	carte.hpp
ficO   = mario.o	texture.o	Collision.o		fenetre.o				menu.o		play.o		Block.o		carte.o

default: reset mario

all: reset mario clear run

run:
	$(RSFML) ./mario

debug:
	$(RSFML) valgrind ./mario

reset:
	reset

clear:
	clear

mario: $(ficO)
	g++ -g -Wall global.hpp $(ficO) $(LSFML) -o mario
	rm -f *.gch

Block.o: Block.cpp Block.hpp fenetre.hpp texture.hpp Collision.hpp
	g++ -c -g -Wall Block.cpp Block.hpp $(ISFML)

carte.o: carte.cpp carte.hpp Block.hpp global.hpp
	g++ -c -g -Wall carte.cpp carte.hpp $(ISFML)

Collision.o: Collision.cpp Collision.hpp
	g++ -c -g -Wall Collision.cpp Collision.hpp $(ISFML)

fenetre.o: fenetre.cpp fenetre.hpp global.hpp texture.hpp
	g++ -c -g -Wall fenetre.cpp fenetre.hpp $(ISFML)

mario.o: mario.cpp global.hpp menu.hpp fenetre.hpp texture.hpp
	g++ -c -g -Wall mario.cpp $(ISFML)

menu.o: menu.cpp menu.hpp global.hpp texture.hpp
	g++ -c -g -Wall menu.cpp menu.hpp $(ISFML)

play.o: play.cpp play.hpp
	g++ -c -g -Wall play.cpp play.hpp $(ISFML)

texture.o: texture.cpp texture.hpp fenetre.hpp
	g++ -c -g -Wall texture.cpp texture.hpp $(ISFML)

clean:
	rm -fR *.o mario *.gch

install:
	chmod +x libs/install.sh
	libs/install.sh

#SFML est installé dans /usr/local

git:
	git add -A
	git commit
	git push

tar_gz: clean
	rm -fr ../projet_cpp
	rm -f ../Projet_cpp_Bazin-Lapegue-De_Jesus.tar.gz
	mkdir ../projet_cpp
	cp -r * ../projet_cpp
	tar czvf ../Projet_cpp_Bazin-Lapegue-De_Jesus.tar.gz ../projet_cpp
	rm -fr ../projet_cpp

mario2:
	g++ -g -Wall $(ficCpp) $(ficH) $(ISFML) $(LSFML) -o mario
