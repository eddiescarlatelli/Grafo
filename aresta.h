#include "vertice.h"

class Aresta{
    public:
        Aresta(Vertice& v1, Vertice& v2, double peso);
        Vertice* getV1();
        Vertice* getV2();
        double getPeso();
        bool operator == (Aresta& orig){
            if(_v1==orig._v1 && _v2==orig._v2){
                return true;
            }
            return false;
        }
    private:
        Vertice* _v1;
        Vertice* _v2;
        double _peso;
};