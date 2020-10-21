
CC=g++

CFlags= -Wall -w -g

INCLUDES:= -Iincludes/

SOURCES:= $(wildcard src/*cpp)

EXE=out

all:
	$(CC) $(CFlags) $(SOURCES) $(INCLUDES) -o $(EXE)

clean:
	rm $(EXE)

run:
	./$(EXE) < input

rerun:
ifneq ($(wildcard $(EXE)),)
	rm $(EXE)
endif
	$(CC) $(CFlags) $(SOURCES) $(INCLUDES) -o $(EXE)
	./$(EXE) < input
