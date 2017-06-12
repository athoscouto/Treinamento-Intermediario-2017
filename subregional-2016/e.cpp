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
const int N = (1<<16), M = 0x3f;

ll n, r1, r2, r3, mn[N], mx[N], sm[N], dp[N], d[M][N], cnt[N], f[17];

ll remove(ll x, ll dgt) {
  ll ans = 0, p = 1;
  while (x) {
    int ldgt = x&15;
    if ((1 << ldgt) != dgt) ans += ldgt*p, p <<= 4;
    x >>= 4;
  }
  return ans;
}

int main() {
  scanf("%llx", &n);

  f[0] = 1;
  for(int i=1; i<17; ++i) f[i] = (i*f[i-1]) % MOD;
  for(int i=1; i<N; ++i) cnt[i] = 1 + cnt[i-(i&-i)];

  for(int i=0; i<n; ++i) {
    scanf("%llx", &d[i][0]);

    for(int j=1; j<N; ++j) {
      int k = j&-j;
      d[i][j] = remove(d[i][j-k], k);
    }
  }

  for(int i=0; i<n; ++i) for(int j=0; j<N; ++j)
    dp[j] += d[i][j];

  for(int i=1; i<N; ++i) {
    mn[i] = dp[i] + mn[i-(i&-i)];
    for(int j=0; j<16; ++j) if (i & (1<<j)) {
      mn[i] = min(mn[i], dp[i] + mn[i^(1<<j)]);
      mx[i] = max(mx[i], dp[i] + mx[i^(1<<j)]);

      sm[i] += f[cnt[i]-1]*(dp[i] % MOD) + sm[i^(1<<j)];
      sm[i] %= MOD;
    }
  }

  printf("%llx %llx %llx\n", mn[N-1], mx[N-1], sm[N-1]);
  return 0;
}
