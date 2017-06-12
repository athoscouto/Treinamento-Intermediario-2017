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

int n, m, s[N], ans;

int main() {
  scanf("%d%d", &n, &m);
  for(int i=0; i<m; ++i) {
    for(int j=0; j<n; ++j) {
      int x;
      scanf("%d", &x);
      s[j] += x;
      if (s[j] >= s[ans]) ans = j;
    }
  }

  printf("%d\n", ans+1);
  return 0;
}
