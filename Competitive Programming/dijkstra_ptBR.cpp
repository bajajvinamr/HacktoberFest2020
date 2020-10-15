#include <iostream>
#include <list>
#include <queue>
#define INFINITO 10000000

using namespace std;

class Grafo
{
private:
	int V; // n�mero de v�rtices

	/* 
		Ponteiro para um array contendo as listas de adjac�ncias		
		
		->  primeiro int como o v�rtice de destino
 		->	segundo int como o curso da aresta
	
	
		Exemplo:				
			ajd[0].push_back(make_pair(1, X));		
				
			**** o v�rtice 0 possui como adjacente do v�rtice 1 com custo X
	
	*/
	
	list<pair<int, int> > * adj;

public:

	// construtor
	Grafo(int V)
	{
		this->V = V; // atribui o n�mero de v�rtices

		/*
			cria as listas onde cada lista � uma lista de pairs
			onde cada pair � formado pelo v�rtice destino e o custo
		*/
		adj = new list<pair<int, int> >[V];
	}

	// adiciona uma aresta ao grafo de v1 �v2
	void addAresta(int v1, int v2, int custo)
	{
		adj[v1].push_back(make_pair(v2, custo));
	}

	/*
	
		Algoritmo de Dijkstra, retorna a dist�ncia m�nima entre o v�rtice de
		origem e o de destino
		
		Par�metros:
			int orig -> v�rtice de origem
			int dest -> v�rtice de origem
			
		Retorno:
			inteiro com o valor da dist�ncia m�nima entre v�rtices	
	*/
	int dijkstra(int orig, int dest)
	{
		// vetor de dist�ncias
		int dist[V];

		/*
		   vetor de visitados -> serve para caso o v�rtice j� tenha sido
		   visitado, n�o ser visitado novamente
		*/
		int visitados[V];

		// fila de prioridades de pair (distancia, v�rtice)
		priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

		// inicia o vetor de dist�ncias e visitados
		for(int i = 0; i < V; i++)
		{
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		// a dist�ncia de orig para orig � 0
		dist[orig] = 0;

		// insere na fila
		pq.push(make_pair(dist[orig], orig));


		// loop do algoritmo
		while(!pq.empty())
		{			
			pair<int, int> p = pq.top(); // extrai o pair do topo
			int u = p.second; // obt�m o v�rtice do pair
			pq.pop(); // remove da fila
			

			// verifica se o v�rtice n�o foi visitado
			if(visitados[u] == false)
			{
				// marca como visitado
				visitados[u] = true;

				list<pair<int, int> >::iterator it;

				// percorre os v�rtices "v" adjacentes dp v�rtice "u" (linha 96)
				for(it = adj[u].begin(); it != adj[u].end(); it++)
				{					
					// obt�m o v�rtice adjacente e o custo da aresta
					int v = it->first;
					int custo_aresta = it->second;

					// relaxamento
					if(dist[v] > (dist[u] + custo_aresta))
					{
						// atualiza a dist�ncia de "v" e insere na fila
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));	
					}
				}
			}	
					}
		
		// retorna a dist�ncia m�nima at� o destino
		return dist[dest];
	}
};

int main(int argc, char *argv[])
{
	Grafo g(6);

	
	g.addAresta(0, 1, 4);
	g.addAresta(0, 2, 2);
	g.addAresta(0, 3, 5);
	g.addAresta(1, 4, 1);
	g.addAresta(2, 1, 1);
	g.addAresta(2, 3, 2);
	g.addAresta(2, 4, 1);
	g.addAresta(4, 3, 1);
	g.addAresta(4, 0, 1);
	g.addAresta(0, 5, 0);
	g.addAresta(5, 4, 2);
		/* add v1 � v2 com custo x
	g.addAresta(0, 4, 10);
	g.addAresta(0, 1, 1);
	g.addAresta(0, 3, 3);
	g.addAresta(1, 2, 5);
	g.addAresta(2, 4, 1);
	g.addAresta(3, 2, 2);
	g.addAresta(3, 4, 6);*/

	cout << endl << g.dijkstra(0, 4) << endl;

	return 0;
}
