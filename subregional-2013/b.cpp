#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6+1, INF = 1e9;
const int QRY = 2, INS = 1, REM = 3;

int n, c, xs[N], ys[N], xe[N], ye[N], p[N], slp[N], nxt[N], nxtp[N], lx[N], ly[N], vis[N];

struct event { int x, t, i; };
bool cp1(event e1, event e2) {
  return (e1.x < e2.x) or (e1.x == e2.x and e1.t < e2.t);
}

bool cp2(event e1, event e2) {
  int i = e1.i, j = e2.i, swp = 0;
  ll x1, x2, y1, y2;
  if (xs[i] > xs[j]) swap(i, j), swp = 1;

  x1 = xe[i] - xs[i], y1 = ye[i] - ys[i];
  x2 = xs[j] - xs[i], y2 = ys[j] - ys[i];

  return swp ^ (x1*y2 - y1*x2 > 0);
}

vector<event> ve;
set<event, bool(*)(event, event)> s(cp2);

void dfs(int u) {
  if (vis[u]) return;
  vis[u] = 1;

  int v = nxt[u];
  if (slp[v] == 0) lx[u] = nxtp[u], ly[u] = ys[v];
  else dfs(v), lx[u] = lx[v], ly[u] = ly[v];
}

int main() {
  while(scanf("%d%d", &n, &c) != EOF) {
    ve.clear();
    s.clear();

    ys[0] = ye[0] = INF;
    xs[0] = -INF, xe[0] = INF;
    slp[0] = nxt[0] = 0;
    ve.push_back({-INF, INS, 0});

    for (int i=1; i<=n; ++i) {
      scanf("%d%d%d%d", xs+i, ys+i, xe+i, ye+i);
      if (xs[i] > xe[i]) swap(xs[i], xe[i]), swap(ys[i], ye[i]);

      ve.push_back({xs[i], INS, i});
      ve.push_back({xe[i], REM, i});

      slp[i] = (ye[i] > ys[i]) - (ys[i] > ye[i]);

      if (slp[i] ==  0) nxt[i] = i;
      else nxtp[i] = (slp[i] == 1) ? xe[i] : xs[i];
    }

    for (int i=1; i<=c; ++i) {
      scanf("%d", p+i);
      ve.push_back({p[i], QRY, n+i});
      nxtp[n+i] = p[i];
    }

    sort(ve.begin(), ve.end(), cp1);
    for (event e : ve) {
      if (e.t == QRY) {
        nxt[e.i] = s.begin()->i;
      }
      else if (e.t == INS) {
        s.insert(e);
        if (slp[e.i] == -1) nxt[e.i] = s.upper_bound(e)->i;
      }
      else if (e.t == REM) {
        event f = {xs[e.i], INS, e.i};
        s.erase(f);
        if (slp[e.i] ==  1) nxt[e.i] = s.upper_bound(f)->i;
      }
    }

    memset(vis, 0, sizeof vis);
    for (int i=1; i<=n+c; ++i) dfs(i);

    for (int i=1; i<=c; ++i) {
      printf("%d", lx[n+i]);
      if (ly[n+i] != INF) printf(" %d", ly[n+i]);
      printf("\n");
    }
  }
  return 0;

}
