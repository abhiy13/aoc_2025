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

void solve_one() {
  vector<string> input = get_input();

  vector<pair<long long, long long>> ranges;

  int res = 0;
  for (string &s : input) {
    if (s.find("-") != string::npos) {
      vector<string> spl = split(s, '-');
      ranges.emplace_back(stoll(spl[0]), stoll(spl[1]));
    } else {
      long long num = stoll(s);
      for (auto &x : ranges) {
        if (num >= x.first && num <= x.second) {
          res++;
          break;
        }
      }
    }
  }

  cout << res << '\n';
}

int main() {
  vector<string> input = get_input();

  vector<pair<long long, long long>> ranges;

  for (string &s : input) {
    if (s.find("-") != string::npos) {
      vector<string> spl = split(s, '-');
      long long x = stoll(spl[0]), y = stoll(spl[1]);
      ranges.emplace_back(min(x, y), max(x, y));
    } else {
      break;
    }
  }

  sort(ranges.begin(), ranges.end());
  long long upto = 0;
  long long res = 0;

  for (int i = 0; i < ranges.size(); ++i) {
    long long L = ranges[i].first, R = ranges[i].second;
    for (int j = 0; j < i; ++j) {
      if (ranges[j].second >= L) {
        L = ranges[j].second + 1;
      }
    }
    res += max(0LL, R - L + 1);
  }

  cout << res << '\n';
  return 0;
}
