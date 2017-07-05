#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5, M = 20;
int t, a, b, x, d[N], k[N], sm[N], mx, ans[M][N];

int main() {
  for(int i=2; i<N; ++i) if (!d[i])
    for(int j=i; j<=N; j+=i) d[j] = i;

  for(int i=2; i<N; ++i) {
    int x = i;

    while(x > 1) {
      int div = d[x];
      while(x % div == 0) x /= div;
      sm[i] += div;
    }

    if (d[i] == i) k[i] = 1;
    else k[i] = k[sm[i]] + 1;

    ans[k[i]][i]++;
  }

  for(int j=1; j<M; ++j) for(int i=2; i<N; ++i)
    ans[j][i] += ans[j][i-1];


  scanf("%d", &t);
  while(t--) {
    scanf("%d%d%d", &a, &b, &x);
    if (x >= M) printf("%d\n", 0);
    else printf("%d\n", ans[x][b] - ans[x][a-1]);
  }
  return 0;
}
