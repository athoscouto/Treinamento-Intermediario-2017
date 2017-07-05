#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<vi, vi> pr;

const int INF = 1e9+7;
int n, w, h, l, u, v, ans;
int dx[] = {-1, 0, 0, +1};
int dy[] = {0, -1, +1, 0};
char m[15][15];
queue<pr> q;
map<pr, int> mv;

bool valid(int u, int v, vi x, vi y) {
  for(int i=0; i<n; ++i)
    if (u == x[i] and v == y[i])
      return 0;

  return m[u][v] == '.';
}


int main() {
  while(scanf("%d%d%d%d", &n, &w, &h, &l) != EOF) {
    ans = INF;
    mv.clear();
    while(!q.empty()) q.pop();

    l++;

    vi x, y;
    x.resize(n);
    y.resize(n);

    memset(m, 'W', sizeof m);
    for(int i=1; i<=h; ++i) {
      for(int j=1; j<=w; ++j) {
        char c;
        scanf(" %c\n", &c);
        if (c == '1') x[0] = i, y[0] = j;
        if (c == '2') x[1] = i, y[1] = j;
        if (c == '3') x[2] = i, y[2] = j;
        if (c == '4') x[3] = i, y[3] = j;
        if (c == 'X') u = i, v = j;
        if (c != 'W') c = '.';
        m[i][j] = c;
      }
    }


    pr st = pr(x, y);
    mv[st] = 1;
    q.push(st);
    while(!q.empty()) {
      pr st = q.front();
      vi x = st.first;
      vi y = st.second;
      q.pop();

      if (x[0] == u and y[0] == v) {
        ans = mv[st] - 1;
        break;
      }

      if (mv[st] == l) continue;

      for(int i=0; i<n; ++i) {
        for(int j=0; j<4; ++j) {
          int nx = x[i], ny = y[i];
          while(valid(nx+dx[j], ny+dy[j], x, y))
            nx += dx[j], ny += dy[j];

          vi vx, vy;
          vx.assign(x.begin(), x.end());
          vy.assign(y.begin(), y.end());
          vx[i] = nx, vy[i] = ny;
          pr nst = pr(vx, vy);

          if (mv[nst]) continue;
          mv[nst] = mv[st] + 1;
          q.push(nst);
        }
      }
    }

    if (ans == INF)
      printf("NO SOLUTION\n");

    else printf("%d\n", ans);
  }
  return 0;
}
