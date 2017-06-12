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
const int N = 300;

int ans = INF, n, m, c[N][N], v[N][N];
int dx[] = {-1,  0,  0, +1};
int dy[] = { 0, +1, -1,  0};

int dfs(int i, int j) {
  if (!i or i > n or !j or j > m or v[i][j]) return 0;
  v[i][j] = 1;
  for(int k=0; k<4; ++k) {
    int x = i + dx[k];
    int y = j + dy[k];
    if (c[i][j] == c[x][y]) v[i][j] += dfs(x, y);
  }
  return v[i][j];
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
    scanf("%d", &c[i][j]);
  for(int i=1; i<=n; ++i) for(int j=1; j<=m; ++j)
    if (!v[i][j]) ans = min(ans, dfs(i, j));

  printf("%d\n", ans);
  return 0;
}
