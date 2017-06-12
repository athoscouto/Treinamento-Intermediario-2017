#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5, INF = 1e9+7;
int n, c, p[N], v[N][2];

int main() {
  scanf("%d%d", &n, &c);

  v[0][0] = 0;
  v[0][1] = -INF;

  for(int i=0; i<n; ++i) {
    scanf("%d", p+i);
    v[i+1][0] = max(v[i][0], v[i][1] + p[i]);
    v[i+1][1] = max(v[i][0] - c - p[i], v[i][1]);
  }

  printf("%d\n", v[n][0]);
  return 0;
}
