#include <cstdio>

#include <algorithm>

using namespace std;

bool used[10];

int Fill(long long num) {
  if (num) {
    int delta = !used[num % 10];
    used[num % 10] = true;
    return delta + Fill(num / 10);
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    int n;
    scanf("%d", &n);
    if (!n) {
      printf("INSOMNIA\n");
      continue;
    }
    fill(used, used + 10, false);
    int sum = 0;
    long long m;
    for (m = 1; sum < 10; m++) {
      sum += Fill(m * n);
    }
    printf("%lld\n", (m - 1) * n);
  }
  return 0;
}
