#include <iostream>
#include <string>
#include <vector>
#include "aresta.h"
#include <list>
#include <queue>

class Grafo{
    public:
        void readLine(std::string v1, std::string v2, double peso);
        Vertice* getVertice(std::string nome);
        Aresta* getAresta(std::string v1, std::string v2);
        std::vector <Vertice> getVertices();
        std::vector <Aresta> getArestas();
        int dijkstra(int orig, int dest);


    private:
        std::vector <Aresta> _arestas;
        std::vector <Vertice> _vertices;
        void insereVertice(std::string nome);
        void insereAresta(std::string v1, std::string v2, double peso);
        list<pair<int, int> > * adj;

};