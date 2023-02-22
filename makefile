CC= g++
FLAGS = -g -Wall -c
INCLUDE_DIR_SDL = -I/usr/include/SDL2
LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image
EXE = bin/exemple bin/affichage bin/test

all : $(EXE)


obj/Image.o : src/Image.h src/Image.cpp
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) src/Image.cpp -o obj/Image.o $(LIBS_SDL)

obj/Pixel.o : src/Pixel.h src/Pixel.cpp
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) src/Pixel.cpp -o obj/Pixel.o $(LIBS_SDL)

obj/mainExemple.o : src/Image.h src/Pixel.h src/mainExemple.cpp data
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) src/mainExemple.cpp -o obj/mainExemple.o $(LIBS_SDL)

bin/exemple : obj/Image.o obj/Pixel.o obj/mainExemple.o 
	$(CC) $(INCLUDE_DIR_SDL) obj/Image.o obj/Pixel.o obj/mainExemple.o -o bin/exemple $(LIBS_SDL)

obj/mainAffichage.o : src/Image.h src/Pixel.h src/mainAffichage.cpp
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) src/mainAffichage.cpp -o obj/mainAffichage.o $(LIBS_SDL)

bin/affichage : obj/Image.o obj/Pixel.o obj/mainAffichage.o
	$(CC) $(INCLUDE_DIR_SDL) obj/Image.o obj/Pixel.o obj/mainAffichage.o -o bin/affichage $(LIBS_SDL)

obj/mainTest.o : src/Image.h src/Pixel.h src/mainTest.cpp
	$(CC) $(FLAGS) $(INCLUDE_DIR_SDL) src/mainTest.cpp -o obj/mainTest.o $(LIBS_SDL)

bin/test : obj/Image.o obj/Pixel.o obj/mainTest.o
	$(CC) $(INCLUDE_DIR_SDL) obj/Image.o obj/Pixel.o obj/mainTest.o -o bin/test $(LIBS_SDL)

valTest:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/test

data :
	data/image2.ppm :data/image1.ppm 

data/image1.ppm :
	touch data/image1.ppm


 data/image2.ppm :
	touch  data/image2.ppm


clean:
	rm -f  ./obj/* ./bin/*

