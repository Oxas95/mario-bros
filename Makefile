ISFML = -I/usr/local/SFML/include
LSFML = -lsfml-graphics -lsfml-window -lsfml-system -L/usr/local/SFML/lib
RSFML = export LD_LIBRARY_PATH=/usr/local/SFML/lib &&

ficCpp = mario.cpp
ficH   = 
ficO   = mario.o

all: mario run

run:
	$(RSFML) ./mario

debug:
	$(RSFML) valgrind ./mario

reset:
	reset

mario: reset $(ficO)
	g++ -g -Wall $(ficO) $(LSFML) -o mario
	rm -f *.gch

mario.o: mario.cpp
	g++ -c -g -Wall mario.cpp $(ISFML)

Collision.o: Collision.cpp Collision.h
	g++ -c -g -Wall Collision.cpp Collision.h $(ISFML)

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
