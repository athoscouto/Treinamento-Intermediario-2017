#include <bits/stdc++.h>
using namespace std;

vector<int> v, u;
set<vector<int> > vis;
int n, m, x;

bool find(vector<int> u, vector<int> v) {
  if (vis.count(u) or u.size() < v.size()) return 0;
  vis.insert(u);

  for(int i=0; i<u.size(); ++i) {
    int sz = max((int) u.size()-i, i);
    vector<int> nu(sz);
    for(int j=nu.size()-1, k=i; k<u.size(); --j, ++k) nu[j] += u[k];
    for(int j=nu.size()-1, k=i-1; k>=0; --j, --k) nu[j] += u[k];
    if (find(nu, v)) return 1;
  }

  if (u.size() == v.size()) {
    for(int i=0; i<u.size(); ++i) if (u[i] != v[i]) return 0;
    return 1;
  }

  return 0;
}

int main() {
  while(scanf("%d", &n) != EOF) {
    u.clear();
    v.clear();
    vis.clear();

    for(int i=0; i<n; ++i) scanf("%d", &x), u.push_back(x);

    scanf("%d", &m);
    for(int i=0; i<m; ++i) scanf("%d", &x), v.push_back(x);

    printf("%c\n", find(u, v) ? 'S' : 'N');
  }

  return 0;
}
