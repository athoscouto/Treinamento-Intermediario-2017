#include <bits/stdc++.h>
using namespace std;

const int N = 1e4+5, M = 50+5;
int n, m, t[N][M], ok = 1;

void swap_row(int x, int y) {
  for(int i=0; i<m; ++i)
    swap(t[x][i], t[y][i]);
}

void pivot(int k) {
  for(int i=k+1; i<n; ++i) if (t[i][k])
    for(int j=k; j<m; ++j) t[i][j] ^= t[k][j];
}

int main() {
  scanf("%d%d", &n, &m);

  for(int i=0; i<n; ++i) for(int j=0; j<m; ++j)
    scanf("%d", &t[i][j]), t[i][j] %= 2;

  for(int j=0; j<m; ++j) {
    int fnd = 0;
    for(int i=j; i<n; ++i) if (t[i][j]) {
      if (i != j) swap_row(i, j);
      fnd = 1;
      break;
    }

    if (!fnd) {
      ok = 0;
      break;
    }

    pivot(j);
  }

  if (ok) {
    for(int i=0; i<m; ++i) {
      for(int j=0; j<i; ++j)
        assert(!t[i][j]);
      assert(t[i][i]);
    }
  }

  printf("%c\n", n > m and ok ? 'N' : 'S');
  return 0;
}
