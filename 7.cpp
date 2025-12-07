#include <bits/stdc++.h>
#include <cassert>
#include <string>

using namespace std;

const int MX = 100001;

vector<string> split(string s, char delimeter) {
  stringstream ss(s);
  string cr;

  vector<string> result;

  while (getline(ss, cr, delimeter)) {
    result.push_back(cr);
  }

  return result;
}

vector<string> get_input() {
  string s;
  vector<string> result;

  while (cin >> s) {
    result.push_back(s);
  }

  return result;
}

int main() {
  vector<string> input = get_input();

  vector<pair<int, int>> Q;
  set<pair<int, int>> visited;

  int N = input.size(), M = input[0].size();
  vector<vector<long long>> dp(N, vector<long long>(M, -1));

  auto add = [&](int x, int y) {
    if (visited.count({x, y})) {
      return;
    }
    visited.insert({x, y});
    Q.emplace_back(x, y);
  };

  // part - 2
  function<long long(int, int)> dfs = [&](int x, int y) {
    if (x >= N || y >= N || y < 0) {
      return 1LL;
    }
    if (dp[x][y] != -1) {
      return dp[x][y];
    }
    if (input[x][y] == '^') {
      return dp[x][y] = dfs(x + 1, y - 1) + dfs(x + 1, y + 1);
    } else {
      return dp[x][y] = dfs(x + 1, y);
    }
  };

  for (int i = 0; i < M; ++i) {
    if (input[0][i] == 'S') {
      add(0, i);
      cout << "Second : ";
      cout << dfs(0, i) << '\n';
    }
  }

  int res = 0;

  while (!Q.empty()) {
    auto t = Q.back();
    Q.pop_back();
    if (t.first >= N || t.second >= M || t.second < 0) {
      continue;
    }
    if (input[t.first][t.second] == '^') {
      res++;
      add(t.first + 1, t.second - 1);
      add(t.first + 1, t.second + 1);
    } else {
      add(t.first + 1, t.second);
    }
  }

  // first
  cout << res << '\n';

  return 0;
}
