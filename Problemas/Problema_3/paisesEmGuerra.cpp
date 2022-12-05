#include <iostream>
using namespace std;
#include <limits.h>
#include <bits/stdc++.h>

#define V 502

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}

void printSolution(int dist[], int target) {

    if(dist[target] >= INT_MAX) {
      cout << "Nao e possivel entregar a carta\n";
    }else {
      cout << dist[target] << "\n";
    }

}
void dijkstra(int graph[V][V], int src, int target)
{
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;
 
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)

            if (!sptSet[v] && !(graph[u][v] == -1) && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                  dist[v] = dist[u] + graph[u][v];
                }
    }

    printSolution(dist, target);
};

class Graph {
  public:
    int graph[V][V] = {};
 
    void addEdge(int v, int w, int custo) {

      if(graph[w][v] != -1) {
        graph[v][w] = 0;
        graph[w][v] = 0;
      } else {
        graph[v][w] = custo;
      }

    }
};

int main()
{
  int N, E;

  cin >> N;
  cin >> E;

  while(N != 0 || E != 0) {

    Graph city;

    for(int i=0; i<V; i++) {
      for(int j=0; j<V; j++) {
        city.graph[i][j] = -1;
      }
    };

    int X, Y, custo;
    int consultas;

    for(int i=0; i<E; i++) {
      cin >> X;
      cin >> Y;
      cin >> custo;
      city.addEdge(X, Y, custo);
    }

    cin >> consultas;

    for(int j=0; j<consultas; j++){
      cin >> X;
      cin >> Y;
      
      dijkstra(city.graph, X, Y);
    }


    cin >> N;
    cin >> E;

    cout << "\n";
  }
 
    return 0;
}