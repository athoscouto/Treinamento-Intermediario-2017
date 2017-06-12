#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 3e4+5;

int n, m, v[N], d[N];
vi adj[N], wgt[N];
priority_queue<pii, vector<pii>, greater<pii> > q;

int main() {
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);

    adj[u].push_back(n+v);
    wgt[u].push_back(w);

    adj[n+u].push_back(v);
    wgt[n+u].push_back(w);

    adj[v].push_back(n+u);
    wgt[v].push_back(w);

    adj[n+v].push_back(u);
    wgt[n+v].push_back(w);
  }

  memset(d, -1, sizeof d);

  q.push({0, 1});
  d[1] = 0;
  while(!q.empty()) {
    int u = q.top().second;
    int du = q.top().first;
    q.pop();

    if (du > d[u]) continue;

    for(int i = 0; i < adj[u].size(); ++i) {
      int v = adj[u][i];
      int dv = du + wgt[u][i];

      if (d[v] != -1 and dv >= d[v]) continue;
      d[v] = dv;
      q.push({dv, v});
    }
  }

  printf("%d\n", d[n]);
  return 0;
}
