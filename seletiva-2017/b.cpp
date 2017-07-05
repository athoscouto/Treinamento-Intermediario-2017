#include <bits/stdc++.h>
using namespace std;

const int N = 5e2+5, INF = 1e9+7;
int n, m, d[N], p[N], vis[N];
vector<int> adj[N];
queue<int> q;

int main() {
  int T;
  scanf("%d", &T);
  for(int t = 1; t<=T; t++) {

    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) adj[i].clear();
    for(int i=0; i<m; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    int ans = INF;
    for(int i=0; i<n; i++) {
      memset(vis, 0, sizeof vis);
      q.push(i);
      vis[i] = 1;
      d[i] = 0;
      while(q.size()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
          if (!vis[v]) vis[v] = 1, d[v] = d[u]+1, q.push(v), p[v] = u;
          else if (v != p[u]) ans = min(ans, d[u]+d[v]+1);
        }
      }
    }

    printf("Case %d: ", t);
    if (ans != INF) printf("%d\n", ans);
    else printf("impossible\n");
  }
  return 0;
}
