#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 3e3+10;

int n, a, b, m[N][N], ans;
vector <pii> pt;

int main () {
  scanf("%d", &n);
  // pt = pts ordered by x,
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a, &b);
    pt.pb(mp(a,b));
  }

  sort(pt.begin(), pt.end());
  for (int i = 0; i < n; i++) pt[i].st = i+1;

  for (int i = 0; i < n; i++) swap(pt[i].st, pt[i].nd), pt[i].st = -pt[i].st;

  sort(pt.begin(), pt.end());
  for (int i = 0; i < n; i++) pt[i].st = i+1;
  for (int i = 0; i < n; i++) swap(pt[i].st, pt[i].nd);

  // drawing point inside the matrix
  for (int i = 0; i < n; i++) m[pt[i].st][pt[i].nd]++;

  // prefix sum
  for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
    m[i][j] += m[i-1][j] + m[i][j-1] - m[i-1][j-1];

  // checking if another point between every 2 pts
  for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) {
    pii u = pt[i];
    pii v = pt[j];
    int a = max(u.st, v.st);
    int b = max(u.nd, v.nd);
    int da = abs(u.st - v.st) + 1;
    int db = abs(u.nd - v.nd) + 1;
    if (m[a][b] - m[a-da][b] - m[a][b-db] + m[a-da][b-db] == 2) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
