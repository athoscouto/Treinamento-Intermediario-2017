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

char s[N], t[N];
int k, ok = true;

bool is_vowel(char c) {
  return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

int main() {
  scanf("%s", s);
  for(int i=0; s[i]; ++i) if (is_vowel(s[i])) t[k++] = s[i];
  for(int i=0; i<k; ++i) if (t[i] != t[k-1-i]) ok = false;
  printf("%c\n", ok ? 'S' : 'N');

  return 0;
}
