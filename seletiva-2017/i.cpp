#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e3+1;
int l, r, n, m, kl, kr, kp, vs[N], vp[N];
vector<int> gp[N], gs[N];
bitset<N> s[N], p[N];

void dfsp(int u) {
  if (vp[u]) return;
  vp[u] = 1;

  for(int v : gp[u]) dfsp(v), p[u][v] = 1, p[u] |= p[v];
}

void dfss(int u) {
  if (vs[u]) return;
  vs[u] = 1;

  for(int v : gs[u]) dfss(v), s[u][v] = 1, s[u] |= s[v];
}

int main() {
  while(scanf("%d%d%d%d", &l, &r, &n, &m) != EOF) {
    for(int i=0; i<N; ++i) gp[i].clear(), gs[i].clear(), s[i].reset(), p[i].reset();
    memset(vs, 0, sizeof vs);
    memset(vp, 0, sizeof vp);
    kl = kr = kp = 0;

    for(int i=0; i<m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      gp[v].push_back(u);
      gs[u].push_back(v);
    }

    for(int i=0; i<n; ++i) dfss(i), dfsp(i);

    for(int i=0; i<n; ++i) {
      int ss = 0, ps = 0;

      for(int j=0; j<n; ++j)
        ss += s[i][j], ps += p[i][j];

      if (l >= n - ss) kl++;
      if (r >= n - ss) kr++;
      if (r <= ps) kp++;
    }

    printf("%d\n%d\n%d\n", kl, kr, kp);
  }
  return 0;
}
