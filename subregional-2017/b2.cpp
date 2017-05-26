#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int l[N], r[N], st[N], ls[N], rs[N], id[N], mn[N], rt[N], k, n, m;
vector<int> g[N];

void dfs(int u, int r) {
  if (mn[u]) return;
  mn[u] = r;
  for(int v : g[u]) dfs(v, r);
}

int init(int i, int j) {
  int v = ++k;
  l[v] = i, r[v] = j;

  if (i != j) {
    ls[v] = init(i, (i+j)/2);
    rs[v] = init((i+j)/2+1, j);
  }

  return v;
}

int sum(int u, int i, int j) {
  if (j < l[u] or r[u] < i) return 0;
  if (i <= l[u] and r[u] <= j) return st[u];
  return sum(ls[u], i, j) + sum (rs[u], i, j);
}

void clone(int i, int j) {
  l[i] = l[j], r[i] = r[j];
  st[i] = st[j];
  ls[i] = ls[j], rs[i] = rs[j];
}

int update(int u, int i, int v) {
  if (i < l[u] or r[u] < i) return u;

  clone(++k, u);
  u = k;
  ls[u] = update(ls[u], i, v);
  rs[u] = update(rs[u], i, v);

  if (l[u] == r[u]) st[u] += v;
  else st[u] = st[ls[u]] + st[rs[u]];

  return u;
}

bool cp(int i, int j) { return mn[i] < mn[j]; }

int find(int a, int b) {
  int l = 1, r = n, v = b-a+1;
  while(l < r) {
    int m = (l+r+1)/2;
    if (sum(rt[m], a, b) <= v/2) l = m;
    else r = m-1;
  }

  int s1 = sum(rt[l], a, b), s2 = sum(rt[l+1], a, b);
  int tgt = (v - s1 <= s2) ? s1 : s2;

  l = 1, r = n;
  while(l < r) {
    int m = (l+r)/2;
    if (sum(rt[m], a, b) < tgt) l = m+1;
    else r = m;
  }
  return l;
}

int main() {
  scanf("%d%d", &n, &m);
  int root = init(1, n);

  for(int v, u=1; u<=n; ++u) {
    scanf("%d", &v);
    g[v].push_back(u);
    id[u] = u;
  }

  for(int u=1; u<=n; ++u) dfs(u, u);
  sort(id+1, id+n+1, cp);

  for(int i=1; i<=n; ++i) {
    int j = id[i];
    rt[mn[j]] = root = update(root, j, 1);
  }

  for(int i=1; i<=n; ++i) rt[i] = max(rt[i], rt[i-1]);

  for(int i=0; i<m; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", find(l, r));
  }

  return 0;
}
