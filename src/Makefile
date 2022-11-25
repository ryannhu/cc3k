CXX = g++
CXXFLAGS = -std=c++14 -g -Werror=vla -Wall -MMD
ENEMIES = werewolf.o phoenix.o vampire.o troll.o enemy.o merchant.o goblin.o
ITEMS = compass.o treasure.o barriersuit.o potion.o

OBJECTS = ${ENEMIES} ${ITEMS}  factory.o main.o game.o floor.o chamber.o character.o decorator.o item.o player.o wounddef.o woundatk.o boostatk.o boostdef.o dwarf.o human.o elf.o orc.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = cc3k

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
