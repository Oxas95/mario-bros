ISFML=-I/usr/local/include
LSFML=-lsfml-graphics -lsfml-window -lsfml-system -L/usr/local/lib
RSFML=export LD_LIBRARY_PATH=/usr/local/lib &&
ficCpp = main.cpp	entity/Entity.cpp fenetre.cpp input.cpp editeur.cpp jouer.cpp entity/entity_rect.cpp entity/entity_ronde.cpp entity/arbre.cpp Carte.cpp entity/Cactus.cpp entity/Rocher.cpp entity/Tronc.cpp entity/Mur.cpp entity/Joueur.cpp entity/Collision.cpp entity/Balle.cpp selecteur_carte.cpp entity/IA.cpp
ficH   = 			entity/Entity.h   fenetre.h   input.h   editeur.h   jouer.h   entity/entity_rect.h   entity/entity_ronde.h   entity/arbre.h   Carte.h   entity/Cactus.h   entity/Rocher.h   entity/Tronc.h   entity/Mur.h   entity/Joueur.h   entity/Collision.h   entity/Balle.h	selecteur_carte.h	entity/IA.h
ficO   = main.o			   Entity.o   fenetre.o   input.o   editeur.o   jouer.o          entity_rect.o          entity_ronde.o   arbre.o          Carte.o   Cactus.o          Rocher.o          Tronc.o          Mur.o			Joueur.o		  Collision.o   	   Balle.o			selecteur_carte.o	IA.o

all: main run

run:
	$(RSFML) ./main

valgrind:
	$(RSFML) valgrind ./main

reset:
	reset

main: reset $(ficO)
	
	g++ -g -Wall $(ficO) $(LSFML) -o main
	rm -f *.gch entity/*.gch

main.o: main.cpp input.h fenetre.h editeur.h jouer.h
	g++ -c -g -Wall main.cpp input.h fenetre.h editeur.h jouer.h $(ISFML)

Entity.o: entity/Entity.cpp entity/Entity.h fenetre.h
	g++ -c -g -Wall entity/Entity.cpp entity/Entity.h fenetre.h $(ISFML)

fenetre.o: fenetre.cpp fenetre.h
	g++ -c -g -Wall fenetre.cpp fenetre.h $(ISFML)

input.o: input.cpp input.h fenetre.h
	g++ -c -g -Wall input.cpp input.h fenetre.h $(ISFML)

editeur.o: editeur.cpp editeur.h fenetre.h input.h Carte.h entity/Joueur.h entity/Collision.h entity/Entity.h selecteur_carte.h
	g++ -c -g -Wall editeur.cpp editeur.h fenetre.h input.h Carte.h entity/Joueur.h entity/Collision.h entity/Entity.h selecteur_carte.h $(ISFML)

jouer.o: jouer.cpp jouer.h fenetre.h Carte.cpp Carte.h entity/Entity.h deplacementIA.cpp selecteur_carte.h
	g++ -c -g jouer.cpp jouer.h fenetre.h Carte.cpp Carte.h entity/Entity.h deplacementIA.cpp selecteur_carte.h $(ISFML)

entity_ronde.o: entity/entity_ronde.cpp entity/entity_ronde.h entity/Entity.h fenetre.h
	g++ -c -g -Wall entity/entity_ronde.cpp entity/entity_ronde.h entity/Entity.h fenetre.h $(ISFML)

entity_rect.o: entity/entity_rect.cpp entity/entity_rect.h entity/Entity.h fenetre.h
	g++ -c -g -Wall entity/entity_rect.cpp entity/entity_rect.h entity/Entity.h fenetre.h $(ISFML)

arbre.o: entity/arbre.cpp entity/arbre.h entity/entity_ronde.h entity/Entity.h fenetre.h
	g++ -c -g -Wall entity/arbre.cpp entity/arbre.h entity/entity_ronde.h entity/Entity.h fenetre.h $(ISFML)

Carte.o: Carte.cpp Carte.h entity/Entity.h entity/entity_ronde.h entity/entity_rect.h entity/arbre.h fenetre.h entity/Cactus.h entity/Rocher.h entity/Tronc.h entity/Mur.h entity/Joueur.h entity/Collision.h entity/IA.h
	g++ -c -g -Wall Carte.cpp Carte.h entity/Entity.h entity/entity_ronde.h entity/entity_rect.h entity/arbre.h fenetre.h entity/Cactus.h entity/Rocher.h entity/Tronc.h entity/Mur.h entity/Joueur.h entity/Collision.h entity/IA.h $(ISFML)
	
Cactus.o: entity/Cactus.cpp entity/Cactus.h entity/entity_ronde.h entity/Entity.h fenetre.h
	g++ -c -g -Wall entity/Cactus.cpp entity/Cactus.h entity/entity_ronde.h entity/Entity.h fenetre.h $(ISFML)
	
Rocher.o: entity/Rocher.cpp entity/Rocher.h entity/entity_ronde.h entity/Entity.h fenetre.h
	g++ -c -g -Wall entity/Rocher.cpp entity/Rocher.h entity/entity_ronde.h entity/Entity.h fenetre.h $(ISFML)

Joueur.o: entity/Joueur.cpp entity/Joueur.h entity/Balle.h entity/entity_ronde.h entity/Entity.h fenetre.h
	g++ -c -g -Wall entity/Joueur.cpp entity/Joueur.h entity/Balle.h entity/entity_ronde.h entity/Entity.h fenetre.h $(ISFML)
	
Tronc.o: entity/Tronc.cpp entity/Tronc.h entity/entity_rect.h entity/Entity.h fenetre.h
	g++ -c -g -Wall entity/Tronc.cpp entity/Tronc.h entity/entity_rect.h entity/Entity.h fenetre.h $(ISFML)

Mur.o: entity/Mur.cpp entity/Mur.h entity/entity_rect.h entity/Entity.h fenetre.h
	g++ -c -g -Wall entity/Mur.cpp entity/Mur.h entity/entity_rect.h entity/Entity.h fenetre.h $(ISFML)

Balle.o: entity/Balle.cpp entity/Balle.h entity/entity_ronde.h entity/Entity.h fenetre.h
	g++ -c -g -Wall entity/Balle.cpp entity/Balle.h entity/entity_ronde.h entity/Entity.h fenetre.h $(ISFML)

Collision.o: entity/Collision.cpp entity/Collision.h
	g++ -c -g -Wall entity/Collision.cpp entity/Collision.h $(ISFML)

selecteur_carte.o: selecteur_carte.cpp selecteur_carte.h Carte.h entity/Entity.h fenetre.h
	g++ -c -g -Wall selecteur_carte.cpp selecteur_carte.h Carte.h entity/Entity.h fenetre.h $(ISFML)

IA.o: entity/IA.cpp entity/IA.h entity/Joueur.cpp entity/Joueur.h entity/Balle.h entity/entity_ronde.h entity/Entity.h fenetre.h
	g++ -c -g -Wall entity/IA.cpp entity/IA.h entity/Joueur.cpp entity/Joueur.h entity/Balle.h entity/entity_ronde.h entity/Entity.h fenetre.h $(ISFML)

clean:
	rm -f *.o main entity/*.gch *.gch

install:
	unzip SFML.zip
	sudo cp -r SFML /usr/local
	rm -f -r SFML

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

main2:
	g++ -g -Wall $(ficCpp) $(ficH) $(ISFML) $(LSFML) -o main
