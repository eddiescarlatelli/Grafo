#include "grafo.h"

void Grafo::readLine(std::string v1, std::string v2, double peso){
    insereVertice(v1);
    insereVertice(v2);
    insereAresta(v1,v2,peso);
    insereAresta(v2,v1,peso);



}

Vertice* Grafo::getVertice(std::string nome){
    for(unsigned int i = 0;i<_vertices.size();i++){
        if(_vertices.at(i).getNome()==nome){
            return &_vertices.at(i);
        }
    }
    return nullptr;
}

Aresta* Grafo::getAresta(std::string v1, std::string v2){
    for(unsigned int i = 0;_arestas.size();i++){
        if(_arestas.at(i).getV1() == getVertice(v1) && _arestas.at(i).getV2() == getVertice(v2)){
            return &_arestas.at(i);
        }
    }
    return nullptr;
}

void Grafo::insereVertice(std::string nome){
    if(getVertice(nome)==nullptr){
        _vertices.push_back(Vertice(nome));
    }
}

void Grafo::insereAresta(std::string v1, std::string v2, double peso){
    if(getAresta(v1,v2)==nullptr){
        _arestas.push_back(Aresta(*getVertice(v1),*getVertice(v2),peso));
    }
}

std::vector <Vertice> Grafo::getVertices(){
    return _vertices;
}

std::vector <Aresta> Grafo::getArestas(){
    return _arestas;
}

int Grafo::dijkstra(int orig, int dest)
	{
		// vetor de distâncias
		int dist[_vertices.size()];

		/*
		   vetor de visitados serve para caso o vértice já tenha sido
		   expandido (visitado), não expandir mais
		*/
		int visitados[_arestas.size()];

		// fila de prioridades de pair (distancia, vértice)
		priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > > pq;

		// inicia o vetor de distâncias e visitados
		for(int i = 0; i < V; i++)
		{
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		// a distância de orig para orig é 0
		dist[orig] = 0;

		// insere na fila
		pq.push(make_pair(dist[orig], orig));

		// loop do algoritmo
		while(!pq.empty())
		{
			pair<int, int> p = pq.top(); // extrai o pair do topo
			int u = p.second; // obtém o vértice do pair
			pq.pop(); // remove da fila

			// verifica se o vértice não foi expandido
			if(visitados[u] == false)
			{
				// marca como visitado
				visitados[u] = true;

				list<pair<int, int> >::iterator it;

				// percorre os vértices "v" adjacentes de "u"
				for(it = adj[u].begin(); it != adj[u].end(); it++)
				{
					// obtém o vértice adjacente e o custo da aresta
					int v = it->first;
					int custo_aresta = it->second;

					// relaxamento (u, v)
					if(dist[v] > (dist[u] + custo_aresta))
					{
						// atualiza a distância de "v" e insere na fila
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}

		// retorna a distância mínima até o destino
		return dist[dest];
	}
};

