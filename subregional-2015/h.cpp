#include <bits/stdc++.h>
using namespace std;

const int N = 3000+10;
int n, x[N], y[N], id[N], m[N][N], ans;

bool cpx(int i, int j) { return x[i] < x[j]; }
bool cpy(int i, int j) { return y[i] < y[j]; }

int main() {
  scanf("%d", &n);
  for(int i=1; i<=n; ++i) scanf("%d%d", x+i, y+i), id[i] = i;

  sort(id+1, id+n+1, cpx);
  for(int i=1; i<=n; ++i) x[id[i]] = i;
  sort(id+1, id+n+1, cpy);
  for(int i=1; i<=n; ++i) y[id[i]] = i;


  for(int i=1; i<=n; ++i) m[x[i]][y[i]] = 1;

  for(int i=1; i<=n; ++i) for(int j=1; j<=n; ++j)
    m[i][j] += m[i-1][j] + m[i][j-1] - m[i-1][j-1];

  for(int i=1; i<=n; ++i) for(int j=i+1; j<=n; ++j) {
    int mnx, mxx, mny, mxy;
    mnx = min(x[i], x[j]), mxx = max(x[i], x[j]);
    mny = min(y[i], y[j]), mxy = max(y[i], y[j]);
    mnx--, mny--;

    int cnt = m[mxx][mxy] - m[mxx][mny] - m[mnx][mxy] + m[mnx][mny];

    if (cnt == 2) ans++;
  }

  printf("%d\n", ans);
  return 0;
}
