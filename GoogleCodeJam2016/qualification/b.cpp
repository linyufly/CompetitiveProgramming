#include <cstdio>
#include <cstring>

char str[10000];
int len;

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    scanf("%s", str);
    len = strlen(str);
    int ans = 0;
    char goal = '+';
    for (int j = len - 1; j >= 0; j--) {
      if (str[j] != goal) {
        ans++;
        goal = goal == '+' ? '-' : '+';
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
