#!/bin/bash

installSFML(){
	reset
	echo "installation SFML"
	sleep 1
	rm -fr SFML
	unzip SFML.zip
	sudo cp -r SFML/* /usr/local
	rm -fr SFML
	sleep 1
}

installCMake(){
	reset
	echo "installation CMake"
	sleep 1
	unzip cmake-3.14.5-Linux-x86_64.zip
	./cmake-3.14.5-Linux-x86_64.sh
	rm -fr cmake-3.14.5-Linux-x86_64
	sleep 1
}

installTGUI(){
	reset
	echo "installation TGUI"
	sleep 1
	rm -fr build
	mkdir build
	unzip TGUI-0.8.5.zip
	mv TGUI-0.8.5 TGUI
	cd build
	cmake . ../TGUI
	make
	cd ..
	rm -fr TGUI
	sleep 1
}

main(){
	cd libs
	until [ $reponse = "4" ]; do
		clear
		echo "1.install SFML"
		echo "2.install CMake"
		echo "3.install TGUI"
		echo "4.exit"
		read -p "> " reponse
		if [ $reponse = "1" ]; then
			installSFML
		elif [ $reponse = "2" ]; then
			installCMake
		elif [ $reponse = "3" ]; then
			installTGUI
		elif [ $reponse != "4" ]; then
			echo "reponse incorrect"
			sleep 2
		fi
		
	done
	reset
}

main
