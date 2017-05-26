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

const ld EPS = 1e-9, PI = acos(-1.);
const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 1e5+5;

int v[3], ok=0;

int main() {
  scanf("%d%d%d", v, v+1, v+2);
  sort(v, v+3);
  if (v[0] == v[1] or v[1] == v[2]) ok = 1;
  if (v[0] + v[1] == v[2]) ok = 1;
  printf("%c\n", ok ? 'S' : 'N');
  return 0;
}
