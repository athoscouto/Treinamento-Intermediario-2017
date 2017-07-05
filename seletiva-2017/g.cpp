#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6+5;
ll n, a[N], b[N], l, r, m;

int next(int i, ll *v) {
  while(i < n and v[i] <= m) i++;
  return i;
}

bool slv(ll *v) {
  for(int i=next(0, v); i<n; i=next(i, v)) {
    int j = next(i+1, v);
    if (j < n and v[i] == v[j]) i = j+1;
    else return 0;
  }
  return 1;
}

int main() {
  while(scanf("%lld", &n) != EOF) {
    for(int i=0; i<n; ++i) scanf("%lld", a+i);
    for(int i=0; i<n; ++i) scanf("%lld", b+i);

    ll l=0, r = 1e9+1;
    while(l < r) {
      m = (l+r)/2;
      if (slv(a) and slv(b)) r = m;
      else l = m + 1;
    }

    printf("%lld\n", l);
  }
  return 0;
}
