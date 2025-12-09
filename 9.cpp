#include <bits/stdc++.h>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

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

  int N = input.size();
  vector<pair<int, int>> points(N);

  for (int i = 0; i < N; ++i) {
    vector<string> pt = split(input[i], ',');
    points[i] = {stoi(pt[1]), stoi(pt[0])};
  }

  auto check = [&](int x, int y) {
    auto pt1 = points[x], pt2 = points[y];

    vector<pait<int, int>> v = {
        p1, pt2, {p1.first, pt2.second}, {pt2.first, pt1.second}};

    for (auto pt : v) {
      bool inside = false;
    }

    return false;
  };

  long long res = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (check(i, k)) {
        res = max(res, 1LL * abs(points[i].first - points[j].first + 1) *
                           abs(points[i].second - points[j].second + 1));
      }
    }
  }

  cout << res << '\n';

  return 0;
}
