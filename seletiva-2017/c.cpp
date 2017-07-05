#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+1;
int v[N], c[N], n, a, x;

int main() {
  scanf("%d%d", &n, &a);

  v[a] = 1;
  for(int i=0; i<n; ++i) {
    scanf("%d", &x);
    if (c[x] < c[a]) v[x] = 1;
    c[x]++;
  }

  for(int i=1; i<N; ++i) if (c[i] >= c[a] and !v[i])
    return printf("%d\n", i), 0;

  printf("-1\n");
  return 0;
}
