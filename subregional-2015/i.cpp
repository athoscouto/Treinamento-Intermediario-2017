#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int di[] = {-1, +0, +0, +1};
int dj[] = {+0, -1, +1, +0};

typedef long long ll;
typedef pair<int, int> ii;
typedef set<ii> omino;
set<omino> ominos[N+1];
set<ll> bit[N+1];
ll mask[N][N];

void add(ii p, omino const &o, int k) {
  if (o.count(p) != 0) return;

  int mi = p.first, mj = p.second;
  for(auto p : o) {
    mi = min(mi, p.first);
    mj = min(mj, p.second);
  }

  omino cur;
  cur.insert({p.first - mi, p.second - mj});
  for(auto p : o) cur.insert({p.first - mi, p.second - mj});

  ominos[k].insert(cur);
}

void fnd(int k) {
  if (k == 1) {
    omino o;
    add({0, 0}, o, 1);
    return;
  }

  fnd(k-1);

  for(omino const &o : ominos[k-1]) for (auto p : o)
    for(int l=0; l<4; ++l) add({p.first + di[l], p.second + dj[l]}, o, k);
}

const int M = 50+1;
ll r, c, h, n, t, m[M][M][M];

bool check(int h, ll msk) {
  for(int i=0; i<r; ++i) for(int j=0; j<c; ++j)
    if ((msk & m[h][i][j]) == msk) return 1;
  return 0;
}

void slv() {
  int ans = 0;
  scanf("%lld%lld%lld%lld", &r, &c, &h, &n);

  memset(m, 0, sizeof m);
  for(int i=0, x; i<r; ++i) for(int j=0; j<c; ++j) {
    scanf("%d", &x);
    while(x <= h) m[x][i][j] = 1, x++;
  }

  for(int k=0; k<=h; ++k) for(int i=0; i<r; ++i) for(int j=0; j<c; ++j)
    for(int x=0; x<N; ++x) for(int y=0; x+y<N; ++y)
      if (m[k][i+x][j+y]) m[k][i][j] |= mask[x][y];

  for(ll msk : bit[n]) {
    int l = 0, r = h;
    while(l < r) {
      int m = (l+r)/2;
      if (check(m, msk)) r = m;
      else l = m+1;
    }

    ans += h-l;
  }

  printf("%d\n", ans);
}

int main() {
  // build polyomino
  fnd(N);

  // build mask
  for(int i=0, k=0; i<N; ++i) for(int j=0; i+j<N; ++j)
    mask[i][j] = 1ll << k, k++;

  // map polyominos to masks
  for(int n=1; n<=N; ++n) for(omino const &o : ominos[n]) {
    ll msk = 0;
    for (ii p : o) msk |= mask[p.first][p.second];
    bit[n].insert(msk);
  }

  scanf("%lld", &t);
  while(t--) slv();
  return 0;
}
