#include <bits/stdc++.h> // runtime: 0.180s
using namespace std;

const int N = 1e5+1, LOG=20, INF = 1e9+7;

struct edge { int u, v, w; };
bool cp(edge e1, edge e2) { return e1.w > e2.w; }

int n, m, s, anc[LOG][N], awg[LOG][N], p[N], h[N];
vector<edge> ve;
vector<int> adj[N], wgt[N];


int find(int u) { return (u == p[u]) ? u : p[u] = find(p[u]); }

void join(int u, int v) {
  u = find(u), v = find(v);
  if (h[v] > h[u]) swap(u, v);
  if (h[u] == h[v]) h[u]++;
  p[v] = u;
}

void kruskal() {
  for(int i=1; i<=n; ++i) {
    p[i] = i;
    adj[i].clear();
    wgt[i].clear();
  }

  for(auto e : ve) {
    int u = e.u, v = e.v;
    if (find(u) != find(v)) {
      join(u, v);
      adj[u].push_back(v);
      wgt[u].push_back(e.w);

      adj[v].push_back(u);
      wgt[v].push_back(e.w);
    }
  }
}

void dfs(int u) {
  for(int i=0; i<adj[u].size(); ++i) {
    int v = adj[u][i];
    int w = wgt[u][i];

    if (h[v]) continue;

    h[v] = h[u] + 1;
    anc[0][v] = u;
    awg[0][v] = w;

    dfs(v);
  }
}

int lca(int u, int v) {
  int w = INF;

  if (h[v] > h[u]) swap(u, v);
  for(int i=LOG-1; i>=0; --i) if (h[u] - (1<<i) >= h[v]) {
    w = min(w, awg[i][u]);
    u = anc[i][u];
  }

  if (u == v) return w;

  for(int i=LOG-1; i>=0; --i) if (anc[i][u] != anc[i][v]) {
    w = min(w, awg[i][u]);
    w = min(w, awg[i][v]);
    u = anc[i][u];
    v = anc[i][v];
  }

  w = min(w, awg[0][u]);
  w = min(w, awg[0][v]);
  return w;
}

int main() {
  while(scanf("%d%d%d", &n, &m, &s) != EOF) {
    ve.clear();

    for(int i=0; i<m; ++i) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      ve.push_back({u, v, w});
    }

    sort(ve.begin(), ve.end(), cp);
    kruskal();

    for(int i=1; i<=n; ++i) h[i] = 0;
    h[1] = 1;
    anc[0][1] = 0;
    dfs(1);

    for(int i=1; i<LOG; ++i) for(int j=1; j<=n; ++j) {
      anc[i][j] = anc[i-1][anc[i-1][j]];
      awg[i][j] = min(awg[i-1][j], awg[i-1][anc[i-1][j]]);
    }

    for(int i=0; i<s; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      printf("%d\n", lca(u, v));
    }
  }
  return 0;
}
