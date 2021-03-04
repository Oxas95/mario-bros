#!/bin/bash

installSFML(){
	reset
	echo "installation SFML"
	sleep 1
	sudo apt install libsfml-dev 
	sleep 1
}

installCMake(){
	reset
	echo "installation CMake"
	sleep 1
	sleep 1
}

main(){
	cd libs
	until [ $reponse = "3" ]; do
		clear
		echo "1.install SFML"
		echo "2.install CMake (not working)"
		echo "3.exit"
		read -p "> " reponse
		if [ $reponse = "1" ]; then
			installSFML
		elif [ $reponse = "2" ]; then
			installCMake
		elif [ $reponse != "3" ]; then
			echo "reponse incorrect"
			sleep 2
		fi
		
	done
	reset
}

main
