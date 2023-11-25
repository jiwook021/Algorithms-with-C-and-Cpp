#include <iostream>
using namespace std;

using ll = long long;

int N;
ll inp[1000005], bit[1000005];

void up(int idx, ll val){
  while(idx <= N){
    bit[idx] += val;
    idx += (idx & (-idx));
  }
}

ll down(int idx){
  ll result = 0;
  while(idx > 0){
    result += bit[idx];
    idx -= (idx & (-idx));
  }
  return result;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int M, K;
  cin >> N >> M >> K;
  for(int i = 1; i <= N; i++){
    cin >> inp[i];
    up(i, inp[i]);
  }
  for(int i = 1; i <= M + K; i++){
    int cs;
    ll a, b;
    cin >> cs >> a >> b;
    if(cs == 1){
      ll diff = b - inp[a];
      inp[a] = b;
      up(a, diff);
    } else{
      cout << down(b) - down(a - 1) << "\n";
    }
  }
  return 0;
}