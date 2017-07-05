#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5, INF = 1e9+7;
int lis[N], n, x, ans;

int main() {
  scanf("%d", &n);
  for(int i=0; i<n; ++i) lis[i] = INF;
  for(int i=0; i<n; ++i) {
    scanf("%d", &x);
    int j = lower_bound(lis, lis+ans, x) - lis;
    lis[j] = min(lis[j], x);
    ans = max(ans, j+1);
  }
  printf("%d\n", ans);
  return 0;
}
