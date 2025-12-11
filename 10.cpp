#include <bits/stdc++.h>
#include <cassert>
#include <string>
#include <unordered_map>
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

  while (getline(cin, s)) {
    result.push_back(s);
  }

  return result;
}

int main() {
  vector<string> inputs = get_input();
  long long sum = 0;

  for (string &input : inputs) {
    string final_pattern = "";
    vector<vector<int>> switches;
    vector<int> joltage;
    int SZ = input.size();
    // cout << input << ' ' << SZ << '\n';

    for (int i = 0; i < SZ; ++i) {
      if (input[i] == '[') {
        int closing = input.find("]", i + 1);
        assert(closing != string::npos);
        final_pattern = input.substr(i + 1, closing - i - 1);
        i = closing;
      } else if (input[i] == '(') {
        int closing = input.find(")", i + 1);
        string sw = input.substr(i + 1, closing - i - 1);
        i = closing;
        vector<string> spl = split(sw, ',');
        vector<int> vs;
        for (string ss : spl) {
          vs.push_back(stoi(ss));
        }
        switches.push_back(vs);
      } else if (input[i] == '{') {
        int closing = input.find("}", i + 1);
        string sw = input.substr(i + 1, closing - i - 1);
        i = closing;
        vector<string> spl = split(sw, ',');
        for (string ss : spl) {
          joltage.push_back(stoi(ss));
        }
      }
    }

    cout << final_pattern << '\n';
    cout << "SWITCHES: \n";
    for (auto &x : switches) {
      for (auto &y : x) {
        cout << y << ' ';
      }
      cout << '\n';
    }
    cout << "JOLTAGE: \n";
    for (auto &x : joltage) {
      cout << x << ' ';
    }
    cout << '\n';

    // part 1
    /*
    int required_mask = 0;
    for (int i = 0; i < final_pattern.size(); ++i) {
      required_mask |= (1 << i) * (final_pattern[i] == '#');
    }

    vector<vector<int>> dp(1 << (final_pattern.size() + 1),
                           vector<int>(switches.size(), -1));

    function<int(int, int)> DP = [&](int mask, int i) {
      if (mask == required_mask) {
        return 0;
      }
      if (i == switches.size()) {
        return 10000;
      }
      if (dp[mask][i] != -1) {
        return dp[mask][i];
      }
      int cmask = mask;
      for (auto m : switches[i]) {
        cmask ^= (1 << m);
      }
      return dp[mask][i] = min(DP(mask, i + 1), DP(cmask, i + 1) + 1);
    };
    */

    vector<map<vector<int>, int>> dp(switches.size());
    const int MAX = 10000;

    function<int(vector<int>, int)> DP = [&](vector<int> mask, int i) {
      if (mask == joltage) {
        return 0;
      }
      if (i == switches.size()) {
        return MAX;
      }
      if (dp[i].count(mask)) {
        return dp[i][mask];
      }
      vector<int> cmask = mask;
      for (auto m : switches[i]) {
        cmask[m]++;
        if (cmask[m] > joltage[m]) {
          int result = DP(mask, i + 1);
          dp[i].emplace(mask, result);
          return result;
        }
      }
      int result =
          min({DP(mask, i + 1), DP(cmask, i + 1) + 1, DP(cmask, i) + 1});
      dp[i].emplace(mask, result);
      return result;
    };

    int res_t = DP(vector<int>(joltage.size(), 0), 0);
    cout << res_t << ' ';

    sum += 1LL * res_t;

    cout << '\n';
  }

  cout << sum << '\n';

  return 0;
}
