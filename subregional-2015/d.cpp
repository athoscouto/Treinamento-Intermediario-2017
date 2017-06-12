#include <bits/stdc++.h>
using namespace std;

const int N = 202;
int n, m, s[N], t[N][N], mt[N][N];
map<int, int> mp[N], ans;
set<int> st;

int main() {
  scanf("%d%d", &n, &m);
  for(int i=0; i<n; ++i) {
    char c1, c2;
    for(int j=0; j<m; ++j) {
      scanf(" %c%c", &c1, &c2);
      t[i][j] = 26*(c1-'a') + c2-'a';

      mp[i][t[i][j]]++;
      mp[n+j][t[i][j]]++;

      st.insert(t[i][j]);
    }
    scanf("%d", s+i);
  }
  for(int i=0; i<m; ++i) scanf("%d", s+n+i);

  while(!st.empty()) {
    for(int i=0; i<n+m; ++i) if (mp[i].size() == 1) {
      int key = mp[i].begin()->first;
      int val = mp[i].begin()->second;
      ans[key] = s[i] / val;

      for(int j=0; j<n+m; ++j) {
        s[j] -= ans[key] * mp[j][key];
        mp[j].erase(key);
      }

      st.erase(key);
    }
  }

  for(auto p : ans)
    printf("%c%c %d\n", p.first/26+'a', p.first%26+'a', p.second);

  return 0;
}
