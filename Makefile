CC = g++

all: 
	$(CC) -I include -L lib game.cpp -o cosmic_shadows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image