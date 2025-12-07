#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
const int MAXK = 13;

int N;
long long dp[MAXN][MAXK];
long long findMax(string &s, int i, int k) {
  if (k == 0) {
    return 0;
  }
  if (i == N) {
    return -LONG_LONG_MAX;
  }
  if (dp[i][k] != -1) {
    return dp[i][k];
  }
  long long x = findMax(s, i + 1, k);
  long long y = findMax(s, i + 1, k - 1);
  if (y >= 0) {
    y += (long long)pow(10L, k - 1) * (s[i] - '0');
  }
  return dp[i][k] = max(x, y);
}

int main() {

  long long result = 0;
  string s;

  while (cin >> s) {
    for (int i = 0; i < MAXN; ++i) {
      for (int j = 0; j < MAXK; ++j) {
        dp[i][j] = -1;
      }
    }

    N = s.length();
    // cout << findMax(s, 0, 12) << ' ' << N << ' ' << result << '\n';
    result += findMax(s, 0, 12);
  }

  cout << result << '\n';

  return 0;
}
