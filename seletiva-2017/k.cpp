#include <bits/stdc++.h>
#define y1 niasundsa
using namespace std;

const int N = 1e5+1;

int d[N], u[N], l[N], r[N];
int x1[N], x2[N], y1[N], y2[N];
int cl, cr, cu, cd;
int n, m, s, ans=-1;

int main() {
  scanf("%d%d%d", &s, &n, &m);

  for(int i=0; i<s; ++i) {
    scanf("%d%d%d%d", x1+i, y1+i, x2+i, y2+i);
    if (x1[i] > x2[i]) swap(x1[i], x2[i]);
    if (y1[i] > y2[i]) swap(y1[i], y2[i]);

    d[y2[i]]++;
    u[y1[i]]++;
    l[x1[i]]++;
    r[x2[i]]++;
  }

  scanf("%d%d%d%d", &cl, &cr, &cu, &cd);

  for(int i=1; i<=n; ++i) l[i] += l[i-1];
  for(int i=n-1; i>=1; --i) r[i] += r[i+1];

  for(int i=1; i<=m; ++i) u[i] += u[i-1];
  for(int i=m-1; i>=1; --i) d[i] += d[i+1];

  for(int i=0; i<s; ++i)
    if (l[x2[i]-1] == cl + (x1[i] != x2[i]) and
        r[x1[i]+1] == cr + (x1[i] != x2[i]) and
        u[y2[i]-1] == cu + (y1[i] != y2[i]) and
        d[y1[i]+1] == cd + (y1[i] != y2[i]))
      ans = i + 1;

  printf("%d\n", ans);
  return 0;
}
