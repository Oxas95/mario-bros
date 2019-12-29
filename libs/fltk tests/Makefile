-Ifltk= `fltk-config --cxxflags --use-images`
-Lfltk= `fltk-config --ldflags` -lfltk -lfltk_images

all: test run

run:
	./test

test: test.o
	g++ -g -Wall test.o -o test $(-Lfltk)

test.o: test.cpp
	g++ -c -g -Wall test.cpp $(-Ifltk)
