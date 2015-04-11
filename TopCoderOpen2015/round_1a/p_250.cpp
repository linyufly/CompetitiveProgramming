#include <cstdio>

#include <algorithm>
#include <set>

using namespace std;

int dfs(int *d_l, int *d_r, int l_l, int l_r, int dig, int status, bool safe_l, bool safe_r, bool leading) {
  int rem = 0;
  for (int i = 0; i <= 9; i++) {
    if ((1 << i) & status) {
      rem++;
    }
  }

  if (dig + 1 < rem) {
    return 0;
  }

  if (dig == -1) {
    return !status;
  }

  int count = 0;

  for (int bit = 0; bit <= 9; bit++) {
    if (bit < d_l[dig] && !safe_l) {
      continue;
    }

    if (bit > d_r[dig] && !safe_r) {
      continue;
    }

    int new_leading = leading;
    if (bit > 0) {
      new_leading = true;
    }

    int new_status = status;
    if (new_leading && ((1 << bit) & status)) {
      new_status ^= (1 << bit);
    }

    bool new_safe_l = safe_l;
    bool new_safe_r = safe_r;
    if (bit > d_l[dig]) {
      new_safe_l = true;
    }
    if (bit < d_r[dig]) {
      new_safe_r = true;
    }
    count += dfs(d_l, d_r, l_l, l_r, dig - 1, new_status, new_safe_l, new_safe_r, new_leading);
    if (count >= 2) {
      return 2;
    }
  }

  return count;
}

class Similars {
 public:
  int maxsim(int l, int r) {
    if (l >= r) {
      return 0;
    }

    static int d_l[10];
    static int d_r[10];
    int l_l = 0, l_r = 0;
    for (int num = l; num > 0; ) {
      d_l[l_l++] = num % 10;
      num /= 10;
    }

    for (int num = r; num > 0; ) {
      d_r[l_r++] = num % 10;
      num /= 10;
    }

    int ans = 0;
    for (int status = 0; status < (1 << 10); status++) {
      int count = 0;
      for (int i = 0; i <= 9; i++) {
        if ((1 << i) & status) {
          count++;
        }
      }
      if (count <= ans) {
        continue;
      }

      if (dfs(d_l, d_r, l_l, l_r, l_r - 1, status, false, false, false) >= 2) {
        ans = count;
      }
    }
    return ans;
  }
};

int main() {
  Similars sim;
  printf("%d\n", sim.maxsim(1, 10));

  return 0;
}

