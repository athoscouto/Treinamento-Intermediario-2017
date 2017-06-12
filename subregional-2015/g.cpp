#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e2+3, mod = 1e9+7;
ll n, k, dp[N][N], c[N][N];

ll slv(int n, int m) {
  if (dp[n][m] != -1) return dp[n][m];

  if (!n) dp[n][m] = 1;
  else if (!m) dp[n][m] = 0;
  else {
    dp[n][m] = 0;
    for(int i=1; i<=n; ++i) {
      ll dlt = c[n-1][i-1] * i % mod * slv(i-1 , k-1) % mod * slv(n-i, m-1) % mod;
      dp[n][m] += dlt;
      dp[n][m] %= mod;
    }
  }

  return dp[n][m];
}

int main() {
  scanf("%lld%lld", &n, &k);

  memset(dp, -1, sizeof dp);
  for(int i=0; i<=n; ++i) c[i][0] = 1;
  for(int i=0; i<=n; ++i) for(int j=1; j<=i; ++j)
    c[i][j] = c[i-1][j] + c[i-1][j-1] % mod;


  printf("%lld\n", slv(n-1, k));
  return 0;
}
