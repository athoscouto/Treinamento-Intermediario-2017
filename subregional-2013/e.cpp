#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+1;
int n, m, a[N], x;

int main() {
  while(scanf("%d%d", &n, &m) != EOF) {
    memset(a, 0, sizeof a);
    for(int i=0; i<m; ++i) scanf("%d", &x), a[x]++;
    if (n == m) printf("*");
    else for(int i=1; i<=n; ++i) if (!a[i]) printf("%d ", i);
    printf("\n");
  }
  return 0;
}
