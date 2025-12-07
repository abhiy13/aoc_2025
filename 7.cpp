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

  queue<pair<int, int>> Q;

  int N = input.size(), M = input[0].size();

  for (int i = 0; i < M; ++i) {
    if (input[0][i] == 'S') {
      Q.emplace(0, i);
    }
  }

  int res = 0;

  while (!Q.empty()) {
    auto t = Q.pop();
    if (t.first >= N || t.second >= M || t.second < 0) {
      res++;
      continue;
    }
    if (input[t.first][t.second] == '^') {
      Q.emplace(t.first + 1, t.second - 1);
      Q.emplace(t.first + 1, t.second + 1);
    } else {
      Q.emplace(t.first + 1, t.second);
    }
  }

  cout << res << '\n';

  return 0;
}
