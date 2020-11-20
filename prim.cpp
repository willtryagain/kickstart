#include <bits/stdc++.h>
#define ll long long int

const int SIZE = 1e6 + 5;
const int V = 5;
using namespace std;


int parent[V];
int key[V];
bool mst_set[V];

int min_key(int key[], bool mst_set[]) {
  int min = INT_MAX;
  int index;
  for (size_t i = 0; i < V; i++) {
    if (mst_set[i] == false && key[i] < min) {
      min = key[i];
      index = i;
    }
  }
  return index;
}

void obtain_mst(int graph[][V]) {

  for (size_t i = 0; i < V; i++) {
    key[i] = INT_MAX;
    mst_set[i] = false;
  }
  key[0] = 0;
  parent[0] = -1;
  for (size_t i = 0; i < V-1; i++) {
    int u = min_key(key, mst_set);
    mst_set[u] = true;
    for (size_t j = 0; j < V; j++) {
      if (graph[u][j] && mst_set[j] == false &&
          graph[u][j] < key[j]) {
       parent[j] = u;
       key[j] = graph[u][j];
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
  obtain_mst(graph);
  for (size_t i = 1; i < V; i++) {
    printf("%d - %d %d\n", parent[i], i, graph[i][parent[i]]);
  }
  return 0;
}
