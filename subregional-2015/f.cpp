#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int f[N], dp[N], n;

int main() {
  memset(dp, 63, sizeof dp);

  f[0] = 1;
  for(int i=1; f[i-1] < N; ++i) f[i] = i*f[i-1];

  dp[0] = 0;
  for(int i=0; i<N; ++i)
    for(int j=1; i+f[j]<N; ++j)
      dp[i+f[j]] = min(dp[i+f[j]], dp[i]+1);

  scanf("%d", &n);
  printf("%d\n", dp[n]);
  return 0;
}
