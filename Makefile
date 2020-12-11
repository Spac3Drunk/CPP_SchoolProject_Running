
FLAG_STSM = -fno-stack-protector
FLAG_SFML = -l sfml-graphics -l sfml-window -l sfml-system

all:
	g++ main.cpp Parcour.cpp Runner.cpp WindCompass.cpp -o main $(FLAG_SFML)

run:
	g++ main.cpp Parcour.cpp Runner.cpp WindCompass.cpp -o main $(FLAG_SFML)
	./main

valgrind:
	g++ -g main.cpp Parcour.cpp Runner.cpp WindCompass.cpp -o main $(FLAG_SFML) $(FLAG_STSM)
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --main-stacksize=83886080 ./main