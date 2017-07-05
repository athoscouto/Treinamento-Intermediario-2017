#include <bits/stdc++.h>
using namespace std;

const int M = 1000+1, O = 22, N = 80;
int dp[M][O][N], o, n, m, u, v, w, t;

int main() {
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d%d", &o, &n, &m);
    memset(dp, 63, sizeof dp);

    dp[0][0][0] = 0;
    for(int i=0; i<m; ++i) {
      scanf("%d%d%d", &u, &v, &w);
      for(int j=0; j<=o; ++j) for(int k=0; k<=n; ++k) {
        int no = min(j+u, o);
        int nn = min(k+v, n);
        dp[i+1][no][nn] = min(dp[i+1][no][nn], dp[i][j][k] + w);
        dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
      }
    }

    printf("%d\n", dp[m][o][n]);
  }
  return 0;
}
