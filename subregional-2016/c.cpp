#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define _ << ", " <<

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<int> cont;
typedef pair<int, cont> ic;

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

cont s, e;
priority_queue<ic, vector<ic>, greater<ic> > q;
map<cont, int> cst;

void add(cont &c, int w) {
  if (cst.count(c) and w >= cst[c]) return;
  q.push({w, c});
  cst[c] = w;
}

int main() {
  s.resize(8), e.resize(8);
  for(int i=0; i<2; ++i) for(int j=0; j<4; ++j) scanf("%d", &s[4*i+j]);
  for(int i=0; i<2; ++i) for(int j=0; j<4; ++j) scanf("%d", &e[4*i+j]);

  q.push({0, s});
  cst[s] = 0;

  while(!q.empty()) {
    int w = q.top().first;
    cont c = q.top().second;
    q.pop();

    if (w > cst[c]) continue;

    int ok = 1;
    for(int i=0; i<8; ++i) if (c[i] != e[i]) ok = 0;
    if (ok) break;

    for(int i=0; i<2; ++i) for(int j=0; j<3; ++j) {
      int x =4*i+j;
      swap(c[x], c[x+1]);
      add(c, w + c[x] + c[x+1]);
      swap(c[x], c[x+1]);
    }

    for(int j=0; j<4; ++j) {
      int x = j, y = 4+j;
      swap(c[y], c[x]);
      add(c, w + c[y] + c[x]);
      swap(c[y], c[x]);
    }
  }

  printf("%d\n", cst[e]);
  return 0;
}
