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

// part 1
void solve_one(vector<string> input) {

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

  cout << result << '\n';
}

int main() {
  vector<string> input = get_input();

  vector<int> splits;
  int N = input.size();

  string &operations = input[N - 1];
  for (int i = 0; i < operations.size(); ++i) {
    if (operations[i] == '+' || operations[i] == '*') {
      splits.push_back(i);
    }
  }
  splits.push_back(operations.size());

  vector<vector<string>> matrix(N);

  for (int i = 0; i < N - 1; ++i) {
    for (int k = 0; k < splits.size() - 1; ++k) {
      string split = input[i].substr(splits[k], splits[k + 1] - splits[k]);
      // cout << split << "-->" << splits[k] << ':' << splits[k + 1] - splits[k]
      //     << ' ';
      // reverse for right to left handling
      reverse(split.begin(), split.end());
      matrix[i].push_back(split);
      cout << matrix[i].back() << ' ';
    }
    cout << '\n';
  }

  long long res = 0;

  cout << "\nCALCULATED MATRIX: \n";

  auto blank = [&](string s) {
    return s.empty() || std::all_of(s.begin(), s.end(), [](unsigned char c) {
             return std::isblank(c);
           });
  };

  for (int i = 0; i < splits.size() - 1; ++i) {
    char &op = operations[splits[i]];
    long long f = (op == '+' ? 0 : 1);
    for (int k = 0; k < 100; ++k) {
      string curr = "";
      for (int j = 0; j < N - 1; ++j) {
        if (k >= matrix[j][i].length()) {
          continue;
        } else {
          curr += matrix[j][i][k];
        }
      }
      if (blank(curr)) {
        continue;
      }
      cout << curr << ' ' << op << ' ';
      if (op == '*') {
        f *= stoll(curr);
      } else {
        f += stoll(curr);
      }
    }
    res += f;
    cout << '\n';
  }

  cout << res << '\n';

  return 0;
}
