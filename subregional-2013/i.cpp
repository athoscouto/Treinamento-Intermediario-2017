#include <bits/stdc++.h>
using namespace std;

const int N = 1000+3, INF = 1e9+7;
int cp1[N], cp2[N], dp[N], d[N], ans;
int n, c, t1, t2;

int main() {
  while(scanf("%d%d%d%d", &n, &c, &t1, &t2) != EOF) {
    for(int i=0; i<n; ++i) scanf("%d", d+i);

    for(int i=0; i<n; ++i) {
      cp1[i] = cp2[i] = 1;

      for(int j = (i+1) % n; i != j; ++j, j %= n) {
        int dst = d[j] - d[i] + c*(j < i);
        if (dst <= t1) cp1[i]++;
        if (dst <= t2) cp2[i]++;
      }
    }

    ans = INF;
    for(int i=0; i<n; ++i) {
      memset(dp, 63, sizeof dp);
      dp[0] = 0;

      for(int j=0; j<n; ++j) {
        int k;
        k = min(j+cp1[j], n);
        dp[k] = min(dp[k], dp[j]+t1);

        k = min(j+cp2[j], n);
        dp[k] = min(dp[k], dp[j]+t2);
      }

      ans = min(ans, dp[n]);

      rotate(cp1, cp1+1, cp1+n);
      rotate(cp2, cp2+1, cp2+n);
    }

    printf("%d\n", ans);
  }
  return 0;
}
