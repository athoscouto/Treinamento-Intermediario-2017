#include <bits/stdc++.h> // runtime: 0.296s
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
const int N = 1e5+1, LOG=20, INF = 1e9+7;

int n, m, s, anc[LOG][N], wgt[LOG][N], h[N];
priority_queue<iii> q;
vector<iii> adj[N];

void prim() {
  h[1] = 1;
  for(auto p : adj[1]) q.push(p);

  while(!q.empty()) {
    int u = q.top().second.first;
    int v = q.top().second.second;
    int w = q.top().first;
    q.pop();

    if (h[v]) continue;

    anc[0][v] = u;
    wgt[0][v] = w;
    h[v] = h[u] + 1;

    for(auto p : adj[v]) q.push(p);
  }
}

int lca(int u, int v) {
  int w = INF;

  if (h[v] > h[u]) swap(u, v);
  for(int i=LOG-1; i>=0; --i) if (h[u] - (1<<i) >= h[v]) {
    w = min(w, wgt[i][u]);
    u = anc[i][u];
  }

  if (u == v) return w;

  for(int i=LOG-1; i>=0; --i) if (anc[i][u] != anc[i][v]) {
    w = min(w, wgt[i][u]), w = min(w, wgt[i][v]);
    u = anc[i][u], v = anc[i][v];
  }

  return min(w, min(wgt[0][v], wgt[0][u]));
}

int main() {
  while(scanf("%d%d%d", &n, &m, &s) != EOF) {
    for(int i=1; i<=n; ++i) adj[i].clear(), h[i] = 0;

    for(int i=0; i<m; ++i) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      adj[u].push_back({w, {u, v}});
      adj[v].push_back({w, {v, u}});
    }

    prim();

    for(int i=1; i<LOG; ++i) for(int j=1; j<=n; ++j) {
      anc[i][j] = anc[i-1][anc[i-1][j]];
      wgt[i][j] = min(wgt[i-1][j], wgt[i-1][anc[i-1][j]]);
    }

    for(int i=0; i<s; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      printf("%d\n", lca(u, v));
    }
  }
  return 0;
}
