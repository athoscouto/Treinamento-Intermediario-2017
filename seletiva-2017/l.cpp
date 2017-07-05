#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef long long ll;
const int N = 1e2+5;

int n, t, s;
map<ll, ll> a, b;

int main() {
  while (~scanf("%d%d", &n, &t)) {
    a.clear();
    b.clear();
    for (int i = 0; i < n/2; ++i) {
      scanf("%d", &s);
      map<ll, ll> x;
      x[s] = 1;
      for (auto v : a) x[s+v.st] += v.nd;
      for (auto v : x) a[v.st] += v.nd;
    }

    for (int i = n/2; i < n; ++i) {
      scanf("%d", &s);
      map<ll, ll> x;
      x[s] = 1;
      for (auto v : b) x[s+v.st] += v.nd;
      for (auto v : x) b[v.st] += v.nd;
    }

    ll ans = 0;
    ans += a[t]; ans += b[t];
    for (auto v : a) ans += (v.nd * b[t-v.st]);
    printf("%lld\n", ans);
  }
  return 0;
}
