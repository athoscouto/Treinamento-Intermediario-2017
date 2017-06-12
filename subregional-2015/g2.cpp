#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e2+3, mod = 1e9+7;
ll n, k, dp[N][N], cb[N][N];

ll slv(ll c, ll i) {
  if (dp[c][i] != -1) return dp[c][i];

  dp[c][i] = 0;
  for(int j=0; j<=min(c, k-1); ++j) {
    dp[c][i] += cb[c][j] * slv(c-j, i+1);
    dp[c][i] %= mod;
  }

  return dp[c][i];
}

int main() {
  scanf("%lld%lld", &n, &k);

  memset(dp, -1, sizeof dp);
  for(int i=0; i<=n; ++i) dp[0][i] = 1;
  for(int i=1; i<=n; ++i) dp[i][n] = 0;

  for(int i=0; i<=n; ++i) cb[i][0] = 1;
  for(int i=1; i<=n; ++i) for(int j=1; j<=i; ++j)
    cb[i][j] = (cb[i-1][j-1] + cb[i-1][j]) % mod;

  printf("%lld\n", (n == 1) ? 1 : slv(n-2, 0));
  return 0;
}
