#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e6;

ll n, k, l, m[2][2], r[2][2];

void mult(ll a[2][2], ll b[2][2], ll r[2][2]) {
  int tmp[2][2] = {{}, {}};
  for(int i=0; i<2; ++i) for(int j=0; j<2; ++j)
    for(int k=0; k<2; ++k) tmp[i][j] += a[i][k] * b[k][j] % mod;

  for(int i=0; i<2; ++i) for(int j=0; j<2; ++j)
    r[i][j] = tmp[i][j] % mod;
}

void exp(ll a[2][2], ll e, ll r[2][2]) {
  r[0][0] = r[1][1] = 1;
  r[1][0] = r[0][1] = 0;

  while(e) {
    if (e&1) mult(r, a, r);
    mult(a, a, a);
    e /= 2;
  }
}



int main() {
  while(scanf("%lld%lld%lld", &n, &k, &l) != EOF) {
    n /= 5;
    m[0][0] = k % mod, m[0][1] = l % mod;
    m[1][0] = 1, m[1][1] = 0;
    exp(m, n, r);

    printf("%06lld\n", r[0][0]);
  }
}
