CC = g++

all: 
	$(CC) -I include/SDL2 -L lib game.cpp -o cosmic_shadows -lmingw32 -lSDL2main -lSDL2