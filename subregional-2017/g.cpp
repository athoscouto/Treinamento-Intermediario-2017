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
const int N = 500+5;

int n, p, w[N][N], b[N][N], r1, r2;

int main() {
  scanf("%d%d", &n, &p);
  for(int i=0; i<p; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    b[x][y] = 1;
  }
  for(int i=0; i<p; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    w[x][y] = 1;
  }

  for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) {
    b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
    w[i][j] += w[i-1][j] + w[i][j-1] - w[i-1][j-1];
  }

  for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j) for(int k=1; k<=min(i, j); ++k) {
    int x = b[i][j] - b[i-k][j] - b[i][j-k] + b[i-k][j-k];
    int y = w[i][j] - w[i-k][j] - w[i][j-k] + w[i-k][j-k];
    if (x and !y) r1++;
    if (!x and y) r2++;
  }

  printf("%d %d\n", r1, r2);
  return 0;
}
