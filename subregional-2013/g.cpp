#include <bits/stdc++.h>
using namespace std;

const int N = 300+5;
int n, m, k, t[N][N], *v, pos[N], val[N], id[N], bs[N], ok;

bool cp(int i, int j) { return v[i] < v[j]; }

int slv() {
  for(int i=0; i<n; ++i) {
    v = t[i];
    sort(id, id+m, cp);
    for(int j=0; j<m; ++j) {
      if (!i) bs[j] = id[j];
      if (id[j] != bs[j]) ok = 0;
    }
  }

  for(int i=0; i<m; ++i) val[i] = id[i], pos[val[i]] = i;
  for(int i=0; i<m; ++i) {
    if (val[i] != i) {
      pos[val[i]] = pos[i];
      val[pos[i]] = val[i];

      val[i] = i;
      pos[i] = i;

      k++;
    }
  }
}

void transpose() {
  for(int i=0; i<max(n, m); ++i) for(int j=0; j<i; ++j)
    swap(t[i][j], t[j][i]);
  swap(n, m);
}

int main() {
  while(scanf("%d%d", &n, &m) != EOF) {
    ok = 1;
    k = 0;

    for(int i=0; i<n; ++i) for(int j=0; j<m; ++j)
      scanf("%d", &t[i][j]);

    for(int i=0; i<m; ++i) id[i] = i;
    slv();

    transpose();

    for(int i=0; i<m; ++i) id[i] = i;
    slv();

    if (!ok) printf("*\n");
    else printf("%d\n", k);
  }
  return 0;
}
