TARGET = ExercicioGrafo1
CC = g++
LD = g++
WARN = -Wall -std=c++11
OBJS = main.cpp grafo.cpp vertice.cpp aresta.cpp

all: $(OBJS)
	$(LD) $(WARN) -o $(TARGET) $(OBJS)
