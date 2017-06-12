#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = (1<<30)+2;

ll n, p, x, y, mn;

int main() {
  scanf("%lld%lld", &n, &p);
  p--;

  ll l=0, r=n, m;
  while(l < r) {
    m = (l+r) / 2;
    if (n*n - m*m > p) l = m+1;
    else r = m;
  }

  if (l % 2 != n % 2) l++;
  x = y = 1 + (n-l)/2;
  p -= n*n - l*l;

  mn = min(l-1, p);
  x += min(l-1, p), p -= mn;

  mn = min(l-1, p);
  y += min(l-1, p), p -= mn;

  mn = min(l-1, p);
  x -= min(l-1, p), p -= mn;

  mn = min(l-1, p);
  y -= min(l-1, p), p -= mn;

  printf("%lld %lld\n", y, x);
  return 0;
}
