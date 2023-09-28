#include <iostream>
#include <string>

class Vertice{
    public:
        Vertice(std::string nome);
        std::string getNome();
        bool operator == (Vertice& orig){
            return _nome == orig.getNome();
        }
    private:
        std::string _nome;
};