#include <bits/stdc++.h>
using namespace std;

const int N = 3e3+5;

int n, k, p[N], dp[N][N];
char s[N];

int slv(int i, int j) {
  if (j < i) return 0;
  if (dp[i][j] != -1) return dp[i][j];

  if (i == j) return dp[i][j] = p[i] ? N+1 : 1;
  int ans = 0;

  ans = max(ans, slv(i+1, j));
  ans = max(ans, slv(i, j-1));
  ans = max(ans, slv(i+1, j-1) + (s[i] == s[j])*((p[i] ? N+1 : 1) + (p[j] ? N+1 : 1)));

  return dp[i][j] = ans;
}

int main() {
  scanf("%s%d", s, &k);
  n = strlen(s);

  memset(dp, -1, sizeof dp);
  for(int x, i=0; i<k; ++i) scanf("%d", &x), p[x-1] = 1;

  printf("%d\n", slv(0, n-1) % N);
  return 0;
}
