#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 987654321;
int n, m, ci = 0, cj = 0, k, tailI = 0, tailJ = 0;
bool map[100][100];
int visit[100][100];
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
int dir = 1;

struct command {
  int time;
  bool clock;
  command(int t, bool c): time(t), clock(c) {}
};
queue<command> q;
queue<pair<int, int>> snake;

int exec() {
  int t = 1;
  snake.push(make_pair(0, 0));
  visit[0][0] = true;
  while(true) {
    if(!q.empty() && q.front().time == t - 1) {
      if(q.front().clock && ++dir == 4) dir = 0;
      if(!q.front().clock && --dir == -1) dir = 3;
      q.pop();
    }
    ci += di[dir], cj += dj[dir];
    if(ci < 0 || cj < 0 || ci >= n || cj >= n || visit[ci][cj]) break;
    visit[ci][cj] = true;
    snake.push(make_pair(ci, cj));
    if(!map[ci][cj]) {
      pair<int, int> p = snake.front();
      snake.pop();
      visit[p.first][p.second] = false;
    } else map[ci][cj] = false;
    t++;
  }
  return t;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> n >> k;
  for(int i = 0; i < k; i++) {
    int a, b; cin >> a >> b;
    map[a-1][b-1] = true;
  }
  int l; cin >> l;
  for(int i = 0; i < l; i++) {
    int x; char c; cin >> x >> c;
    q.push(command(x, c == 'D'));
  }
  cout << exec();
  return 0;
}