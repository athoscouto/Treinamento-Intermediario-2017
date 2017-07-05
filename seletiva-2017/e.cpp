#include <bits/stdc++.h>
using namespace std;

const int N = 2000;
int t, n, v[] = {56, 96, 36, 76, 16};
char s[N];

int main() {
  scanf("%d", &t);
  while(t--) {
    scanf("%s", s);
    n = s[strlen(s)-1] - '0';
    if (strlen(s) == 1 and n == 0) printf("1\n");
    else if (strlen(s) == 1 and n == 1) printf("66\n");
    else printf("%d\n", v[(n + 3)%5]);
  }
  return 0;
}
