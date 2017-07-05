#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+1;
ll n, q, anc[25][N], dis[25][N], h[N];
vector<int> g[N];

ll lca(int u, int v) {
  ll ans = 0;

  if (h[u] < h[v]) swap(u, v);
  for (int i = 20; i >= 0; --i) if (h[u] - (1<<i) >= h[v])
    ans += dis[i][u], u = anc[i][u];

  if (u == v) return ans;

  for (int i = 20; i >= 0; --i) if (anc[i][u] != anc[i][v])
    ans += dis[i][u] + dis[i][v], u = anc[i][u], v = anc[i][v];

  ans += dis[0][u] + dis[0][v];

  return ans;
}

int main() {
  while(scanf("%lld", &n) and n) {
    memset(h, 0, sizeof h);

    for(int i=1; i<n; ++i) {
      scanf("%lld%lld", &anc[0][i], &dis[0][i]);
      h[i] = h[anc[0][i]] + 1;
    }

    anc[0][0] = 0;
    for (int i=1; (1<<i) < n; ++i) for (int j=0; j<n; ++j) {
      anc[i][j] = anc[i-1][anc[i-1][j]];
      dis[i][j] = dis[i-1][j] + dis[i-1][anc[i-1][j]];
    }

    scanf("%lld", &q);
    for(int i=0; i<q; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      printf("%lld%c", lca(u, v), (i == q-1) ? '\n' : ' ');
    }
  }

  return 0;
}
