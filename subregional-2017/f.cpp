#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e4+5;

int n, m, m1, m2, d1[N], d2[N], l1[N], l2[N], r1[N], r2[N];

int dfs(int u, int *d, int *l, int *ans) {
  if (!u) return 0;
  ans[u] = 1 + dfs(d[u], d, l, ans);
  dfs(l[u], d, l, ans);
  return ans[u];
}

int main() {
  scanf("%d", &n);
  for(int i=0; i<n; ++i) {
    int x, p, q;
    scanf("%d %d %d", &x, &p, &q);
    d1[x] = q;
    l1[x] = p;
  }

  scanf("%d", &m);
  for(int i=0; i<m; ++i) {
    int x, p, q;
    scanf("%d %d %d", &x, &p, &q);
    d2[x] = p;
    l2[x] = q;
  }

  dfs(1, d1, l1, r1);
  dfs(1, d2, l2, r2);

  for(int i=1; i<=n; ++i) m1 = max(r1[i], m1);
  for(int i=1; i<=m; ++i) m2 = max(r2[i], m2);

  printf("%d\n", n + m - max(min(r1[1], m2), min(r2[1], m1)));
  return 0;
}
