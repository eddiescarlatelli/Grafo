#include "grafo.h"
#include <fstream>
#include <algorithm>

using namespace std;

Grafo criaGrafo(std::string arquivo){
  Grafo grafo;
  string line;
  ifstream file ("example.txt");
  if (file.is_open()){
    while (getline (file,line)){
      string v1;
      string v2;
      double peso;
      size_t pos = 0;
      vector <string> token;
      while ((pos = line.find(' ')) != std::string::npos) {
        token.push_back(line.substr(0, pos));
        line.erase(0, pos + 1);
      }
      v1 = token.at(0);
      v2 = token.at(1);
      replace(line.begin(),line.end(),',','.');
      peso = stod(line);
      grafo.readLine(v1,v2,peso);
      
    }
    file.close();
    return grafo;
  }

  else cout << "Unable to open file"; 
  return grafo;
} 

int main () {
  Grafo grafo = criaGrafo("example.txt");
  int exit;

  cout << "\nInsira uma opção: " << endl;
  cout << "1. Imprima na tela o número de vértices e arestas do Grafo." << endl;
  cout << "2. Imprima a lista de todos os vértices no Grafo" << endl;
  cout << "3. Exibe a sequencia de arestas atravessadas e o custo total do caminho com o menor custo entre vertices escolhidos através do Algoritmo de Dijkstra" << endl;
  cout << "4. Imprime o diâmetro do grafo" << endl;
  cout << "5. Imprime na tela o vértice com maior centralidade" << endl;
  cout << "6. Imprime o vértice com maior centralidade de intermediação" << endl;

  cin >> exit;

  if(exit == 1){
    cout << "Vertices: " << grafo.getVertices().size() << endl;
    cout << "Arestas: " << grafo.getArestas().size() << endl;
  }
  if(exit == 2){
    for(unsigned int i = 0; i < grafo.getVertices().size(); i++){
      cout << grafo.getVertices().at(i).getNome() << endl;
    }
  }
  if(exit == 3){
    
  }


  return 0;
}
