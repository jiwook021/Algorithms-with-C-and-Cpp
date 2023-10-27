//https://www.acmicpc.net/problem/2042
#include <iostream>
using namespace std;

using ll = long long;

ll seg_tree[2100005];

ll get_interval_sum(int now, int now_left, int now_right, int find_left, int find_right){
  if(find_right < now_left || now_right < find_left){
    return ll(0);
  }
  if(find_left <= now_left && now_right <= find_right){
    return seg_tree[now];
  }
  int middle = (now_left + now_right) / 2;
  return get_interval_sum(now * 2, now_left, middle, find_left, find_right) + get_interval_sum(now * 2 + 1, middle + 1, now_right, find_left, find_right);
}

void up(ll idx, ll val){
  ll diff = val - seg_tree[idx];
  while(idx != 0){
    seg_tree[idx] += diff;
    idx = idx >> 1;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, K, sz = 1;
  cin >> N >> M >> K;
  while(sz < N){
    sz = sz << 1;
  }
  for(int i = 0; i < N; i++){
    cin >> seg_tree[i + sz];
  }
  for(int i = sz - 1; i >= 1; i--){
    seg_tree[i] = seg_tree[i * 2] + seg_tree[i * 2 + 1];
  }
  for(int i = 1; i <= M + K; i++){
    ll cs, a, b;
    cin >> cs >> a >> b;
    if(cs == 1){
      up(sz + a - 1, b);
    } else{
      cout << get_interval_sum(1, 1, sz, a, b) << "\n";
    }
  }
  return 0;
}