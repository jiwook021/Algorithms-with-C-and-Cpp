#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 99999999

void dijkstra(std::vector<std::vector<int>> graph, int vertex, int edge, int K, int X){
  int distance[300005];
  std::priority_queue<pair<int, int>> pq;
  for(int i = 1;i <= vertex;i++){
    distance[i] = INF;
  }
  distance[X] = 0;
  pq.push({ 0, X });
  while(!pq.empty()){
    int src_dist = -pq.top().first; //그 현재 정점까지 사용한 비용
    int src = pq.top().second; //정점
    pq.pop();

    if(distance[src] < src_dist) continue;

    for(auto next : graph[src]){
      if(distance[next] > src_dist + 1){
        distance[next] = src_dist + 1;
        pq.push({ -(src_dist + 1), next });
      }
    }
  }
  for(int i = 1; i <= vertex; i++){
    if(distance[i] == K){
      cout << i << "\n";
    }
  }
}

int main(){
  // N이 2부터 30만임
  std::vector<std::vector<int>> graph(300005);
  int N, M, K, X, src, dest;
  std::cin >> N >> M >> K >> X;

  for(int i = 0;i < M;i++){
    std::cin >> src >> dest;
    graph[src].push_back(dest);
  }
  dijkstra(graph, N, M, K, X);

  return 0;
}