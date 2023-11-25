#include <iostream>
#include <vector>
using namespace std;

struct Path{
  int node, depth;
};

int idx[100005], ans_node, ans_depth;
bool visited[100005];

vector<int> adj[100005];
vector<Path> path;
Path segtree[1000005];

void dfs(int now, int depth){
  for(auto next : adj[now]){
    if(!visited[next]){
      visited[next] = true;
      path.push_back({ next, depth + 1 });
      dfs(next, depth + 1);
      path.push_back({ now, depth });
    }
  }
}

void range(int now, int nowLeft, int nowRight, int left, int right){
  if(nowRight < left || right < nowLeft){
    return;
  }
  if(left <= nowLeft && nowRight <= right){
    if(ans_depth > segtree[now].depth){
      ans_depth = segtree[now].depth;
      ans_node = segtree[now].node;
    }
    return;
  }
  int mid = (nowLeft + nowRight) / 2;
  range(now * 2, nowLeft, mid, left, right);
  range(now * 2 + 1, mid + 1, nowRight, left, right);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, sz = 1;

  cin >> N;
  for(int i = 1; i < N; i++){
    int A, B;
    cin >> A >> B;
    adj[A].push_back(B);
    adj[B].push_back(A);
  }

  visited[1] = true;
  path.push_back({ 1, 1 });
  dfs(1, 1);

  for(int i = 0; i < path.size(); i++){
    idx[path[i].node] = i + 1;
  }

  while(path.size() > sz){
    sz *= 2;
  }
  for(int i = 1; i < sz * 2; i++){
    segtree[i].node = 0;
    segtree[i].depth = 999999999;
  }

  for(int i = sz; i < sz + path.size(); i++){
    segtree[i].node = path[i - sz].node;
    segtree[i].depth = path[i - sz].depth;
  }

  for(int i = sz - 1; i >= 1; i--){
    if(segtree[i * 2].depth < segtree[i * 2 + 1].depth){
      segtree[i].node = segtree[i * 2].node;
      segtree[i].depth = segtree[i * 2].depth;
    } else{
      segtree[i].node = segtree[i * 2 + 1].node;
      segtree[i].depth = segtree[i * 2 + 1].depth;
    }
  }

  cin >> M;
  for(int i = 1; i <= M; i++){
    int node1, node2;
    cin >> node1 >> node2;

    int l = idx[node1];
    int r = idx[node2];

    if(l > r){
      int tmp = l;
      l = r;
      r = tmp;
    }

    ans_node = 2 * N;
    ans_depth = 2 * N;

    range(1, 1, sz, l, r);

    cout << ans_node << "\n";
  }

  return 0;
}
