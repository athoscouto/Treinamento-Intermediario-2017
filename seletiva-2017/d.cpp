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
const int N = 1e5+5;

int t, a, n, x[N], h[N];
int hl[N], hr[N];

int main() {
  scanf("%d", &t);
  while (t--) {
    cl(hl,0); cl(hr,0);

    scanf("%d%d", &a, &n);
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
    for (int i = 0; i <= n; i++) scanf("%d", &h[i]);

    for (int i = 1;   i <= n; i++) hl[i] = max(h[i-1], hl[i-1]);
    for (int i = n-1; i >= 0; i--) hr[i] = max(h[i+1], hr[i+1]);

    ll ans = 0, sx = 0;
    for (int i = 1; i <= n; ++i) {
      sx += x[i];
      if (hl[i] > h[i] and hr[i] > h[i]) continue;
      else {
        ans += a*sx*min(h[i], hl[i]);
        sx = 0;
      }
    }

    printf("%lld\n", ans);
  }
  return 0;
}
