
#define INF 999999999
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, dist[100005], a[100005], b[100005], w[100005], d[1005][1005];
vector <pair<int, int>> adj[100005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int st){
  for(int i = 1; i <= N; i++){
    dist[i] = INF;
  }
  dist[st] = 0;
  pq.push({ 0, st });
  while(!pq.empty()){
    auto [now_val, now] = pq.top();
    pq.pop();
    if(now_val > dist[now]) continue;
    for(auto [next, next_val] : adj[now]){
      int tot = now_val + next_val;
      if(dist[next] > tot){
        dist[next] = tot;
        pq.push({ tot, next });
      }
    }
  }
}
//   for(int i = 1; i <= N; i++){
//     int now = -1, value = INF;
//     for(int j = 1; j <= N; j++){
//       if(!visited[j] && value > dist[j]){
//         now = j;
//         value = dist[j];
//       }
//     }
//     for(auto [next, val] : adj[now]){
//       int tot = dist[now] + val;
//       if(dist[next] > tot){
//         dist[next] = tot;
//       }
//     }
//     visited[now] = true;
//   }


void bellman_ford(int st){
  for(int i = 1; i <= N; i++){
    dist[i] = INF;
  }
  dist[st] = 0;

  for(int j = 1; j < N; j++){
    for(int i = 1; i <= M; i++){
      int now = a[i];
      int next = b[i];
      int tot = dist[now] + w[i];
      if(dist[next] > tot){
        dist[next] = tot;
      }
    }
  }
  bool flag = false;
  for(int i = 1; i <= M; i++){
    int now = a[i];
    int next = b[i];
    int tot = dist[now] + w[i];
    if(dist[next] > tot){
      flag = true;
    }
  }
  if(flag){
    cout << "-1";
  } else{
    for(int i = 1; i <= N; i++){
      cout << dist[i] << " ";
    }
    cout << "\n";
  }
}

// void floyd_warshall(){
//   for(int i = 1; i <= N; i++){
//     for(int j = 1; j <= N; j++){
//       dist[i][j] = INF;
//     }
//     dist[i][i] = 0;
//   }
//   for(int i = 1; i <= M; i++){
//     dist[a[i]][b[i]] = dist[b[i]][a[i]] = w[i];
//   }
//   for(int k = 1; k <= N; k++){
//     for(int i = 1; i <= N; i++){
//       for(int j = 1; j <= N; j++){
//         dist[i][j] = min(dist[i][j], dist[i][k], dist[k][j]);
//       }
//     }
//   }
// }

int main(){
  cin >> N >> M; //N은 정점 갯수, M은 간선 갯수
  for(int i = 1; i <= M; i++){
    cin >> a[i] >> b[i] >> w[i];
    adj[a[i]].push_back({ b[i], w[i] });
    adj[b[i]].push_back({ a[i], w[i] });
  }

  // dijkstra(1);
  // bellman_ford(1);
  // floyd_warshall();

  return 0;
}




// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>

// #define MAX_EDGES 1000
// #define MAX_VERTICES 1000
// #define INF INT_MAX

// typedef struct {
//     int source;
//     int dest;
//     int weight;
// } Edge;

// void BellmanFord(Edge edges[], int V, int E, int src) {
//     int distance[V];
//     for (int i = 0; i < V; i++) {
//         distance[i] = INF;
//     }
//     distance[src] = 0;

//     // Relax all edges |V| - 1 times.
//     for (int i = 1; i <= V - 1; i++) {
//         for (int j = 0; j < E; j++) {
//             int u = edges[j].source;
//             int v = edges[j].dest;
//             int weight = edges[j].weight;
//             if (distance[u] != INF && distance[u] + weight < distance[v]) {
//                 distance[v] = distance[u] + weight;
//             }
//         }
//     }

//     // Check for negative-weight cycles.
//     for (int i = 0; i < E; i++) {
//         int u = edges[i].source;
//         int v = edges[i].dest;
//         int weight = edges[i].weight;
//         if (distance[u] != INF && distance[u] + weight < distance[v]) {
//             printf("Graph contains negative weight cycle\n");
//             return;
//         }
//     }

//     printf("Vertex   Distance from Source\n");
//     for (int i = 0; i < V; i++) {
//         printf("%d \t\t %d\n", i, distance[i]);
//     }
// }

// int main() {
//     int V = 5;  // Number of vertices in graph
//     int E = 8;  // Number of edges in graph
//     Edge edges[E];

//     // add edge 0-1 (or A-B in above figure)
//     edges[0].source = 0;
//     edges[0].dest = 1;
//     edges[0].weight = -1;

//     // add edge 0-2 (or A-C in above figure)
//     edges[1].source = 0;
//     edges[1].dest = 2;
//     edges[1].weight = 4;

//     // ... (add other edges)

//     BellmanFord(edges, V, E, 0);

//     return 0;
// }

