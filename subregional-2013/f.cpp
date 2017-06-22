#include <bits/stdc++.h>
using namespace std;

int n, x, sz, k;
set<int> p;

int main() {
  while(scanf("%d", &n) != EOF) {
    sz = k = 0;
    p.clear();

    for(int i=0; i<n; ++i) {
      scanf("%d", &x);
      p.insert(sz);
      sz += x;
    }

    if (sz % 3) {
      printf("0\n");
      continue;
    }

    for(int x : p) {
      int y = (x + sz/3) % sz, z = (sz + x - sz/3) % sz;
      if (p.count(y) and p.count(z)) k++;
    }

    printf("%d\n", k/3);
  }
  return 0;
}
