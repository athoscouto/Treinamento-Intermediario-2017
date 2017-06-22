#include <bits/stdc++.h>
using namespace std;

const int N = 1e3, INF = 1e9+7;
int n, m, k, a[N], pos[N], id[N], vis[N], x;
vector<int> g[N];

int dfs(int u, int r) {
  int ans = (r == u) ? INF : a[id[u]];

  if (vis[u] == x) return ans;
  vis[u] = x;

  for(int v : g[u]) ans = min(ans, dfs(v, r));
  return ans;
}

int main() {
  while(scanf("%d%d%d", &n, &m, &k) != EOF) {
    for(int i=1; i<=n; ++i) g[i].clear(), pos[i] = id[i] = i;

    for(int i=1; i<=n; ++i) scanf("%d", a+i);
    for(int i=0; i<m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      g[v].push_back(u);
    }

    for(int i=0; i<k; ++i) {
      char c;
      int u, v, q;
      scanf(" %c", &c);
      if (c == 'T') {
        scanf("%d%d", &u, &v);
        swap(pos[u], pos[v]);
        id[pos[u]] = u;
        id[pos[v]] = v;
      }
      else {
        scanf("%d", &u);
        x++;
        q = dfs(pos[u], pos[u]);
        if (q == INF) printf("*\n");
        else printf("%d\n", q);
      }
    }
  }
  return 0;
}
