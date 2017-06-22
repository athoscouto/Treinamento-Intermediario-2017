#include <bits/stdc++.h>
using namespace std;

int v[3];
char c;

int main() {
  while(scanf("%d%d%d", v, v+1, v+2) != EOF) {
    c = '*';
    if ((v[0] and !v[1] and !v[2]) or (!v[0] and v[1] and v[2])) c = 'A';
    if ((v[1] and !v[0] and !v[2]) or (!v[1] and v[0] and v[2])) c = 'B';
    if ((v[2] and !v[1] and !v[0]) or (!v[2] and v[1] and v[0])) c = 'C';
    printf("%c\n", c);
  }
  return 0;
}
