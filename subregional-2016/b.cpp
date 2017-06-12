#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5, SQ=500;
int n, m, l, r, mn[N], bit[N];
vector<int> g[N];

void dfs(int u, int r) {
  if (mn[u]) return;
  mn[u] = r;
  for(int v : g[u]) dfs(v, r);
}

void add(int i, int v) {
  i += 2;
  while(i < N) bit[i] += v, i+=i&-i;
}

int get(int i) {
  i += 2;
  int ans = 0;
  while(i) ans += bit[i], i -= i&-i;
  return ans;
}

struct query { int i, l, r, ans; } qs[N];
bool c1(query a, query b) { return a.l/SQ == b.l/SQ ? a.r < b.r : a.l < b.l; }
bool c2(query a, query b) { return a.i < b.i; }

int find(int v) {
  int l = 1, r = n;
  while(l < r) {
    int m = (l+r+1)/2;
    if (get(m) <= v/2) l = m;
    else r = m-1;
  }

  int tgt = get(v - get(l) <= get(l+1) ? l : l+1);

  l = 1, r = n;
  while(l < r) {
    int m = (l+r)/2;
    if (get(m) < tgt) l = m+1;
    else r = m;
  }

  return l;
}

int main() {
  scanf("%d%d", &n, &m);

  for(int v, u=1; u<=n; ++u) {
    scanf("%d", &v);
    g[v].push_back(u);
  }

  for(int u=1; u<=n; ++u) dfs(u, u);

  for(int i=0; i<m; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    qs[i].l = l, qs[i].r = r, qs[i].i = i;
  }

  sort(qs, qs+m, c1);
  for (int l = 0, r = -1, i = 0; i < m; ++i) {
    query &q = qs[i];
    while (r < q.r) add(mn[++r], +1);
    while (r > q.r) add(mn[r--], -1);
    while (l < q.l) add(mn[l++], -1);
    while (l > q.l) add(mn[--l], +1);

    q.ans = find(r-l+1);
  }

  sort(qs, qs+m, c2);
  for(int i=0; i<m; ++i) printf("%d\n", qs[i].ans);
  return 0;
}
