#include "aresta.h"

Aresta::Aresta(Vertice& v1, Vertice& v2, double peso)
{
    _v1 = &v1;
    _v2 = &v2;
    _peso = peso;
}
 Vertice* Aresta::getV1(){
     return _v1;
 }
 Vertice* Aresta::getV2(){
     return _v2;
 }
double Aresta::getPeso(){
    return _peso;
}
