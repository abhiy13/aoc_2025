#include <bits/stdc++.h>
#include <cassert>
#include <sstream>
#include <string>
#include <vector>

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

  while (getline(cin, s)) {
    result.push_back(s);
  }

  return result;
}

vector<string> get_by_word(string input) {
  string s;
  stringstream ss(input);
  vector<string> result;

  while (ss >> s) {
    result.push_back(s);
  }

  return result;
}

int main() {
  vector<string> input = get_input();

  vector<vector<long long>> sheet(input.size(), vector<long long>());
  vector<vector<string>> ssheet(input.size(), vector<string>());

  int size = input.size();
  for (int i = 0; i < input.size() - 1; ++i) {
    vector<string> f = split(input[i], '\t');
    for (string &s : f) {
      sheet[i].push_back(stoll(s));
      ssheet[i].push_back(to_string(stoll(s)));
      cout << ssheet[i].back() << ' ';
    }
    cout << '\n';
  }

  long long result = 0;

  vector<string> calc = get_by_word(input[size - 1]);

  /* part 1
  for (int i = 0; i < calc.size(); ++i) {
    // cout << calc[i] << ' ';
    if (calc[i] == "+") {
      long long sum = 0;
      for (int j = 0; j < size - 1; ++j) {
        sum += sheet[j][i];
      }
      result += sum;
    } else if (calc[i] == "*") {
      long long mul = 1;
      for (int j = 0; j < size - 1; ++j) {
        mul *= sheet[j][i];
      }
      result += mul;
    }
  }
  */

  cout << "CALC" << '\n';

  for (int i = 0; i < calc.size(); ++i) {
    if (calc[i] == "+") {
      long long sum = 0;
      vector<long long> new_nums;
      bool one = true;
      for (int k = 100; k >= 0; --k) {
        string news = "";
        one = false;
        for (int j = 0; j < size - 1; ++j) {
          if (ssheet[j][i].size() > k) {
            news += ssheet[j][i][k];
            one = true;
          }
        }
        if (one) {
          new_nums.push_back(stoll(news));
        } else {
        }
      };
      for (auto x : new_nums) {
        cout << x << ' ';
        sum += x;
      }
      result += sum;
    } else if (calc[i] == "*") {
      long long mul = 1;
      vector<long long> new_nums;
      bool one = true;
      for (int k = 100; k >= 0; --k) {
        string news = "";
        one = false;
        for (int j = 0; j < size - 1; ++j) {
          if (ssheet[j][i].size() > k) {
            news += ssheet[j][i][k];
            one = true;
          }
        }
        if (one) {
          new_nums.push_back(stoll(news));
        } else {
        }
      };
      for (auto x : new_nums) {
        cout << x << ' ';
        mul *= x;
      }
      result += mul;
    }
    cout << '\n';
  }

  cout << result << '\n';

  return 0;
}
