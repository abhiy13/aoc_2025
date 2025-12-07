#include <bits/stdc++.h>
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

int main() {

  set<long long> st;
  for (int i = 1; i < MX; ++i) {
    string s = to_string(i) + to_string(i);
    for (;;) {
      long long x = stoll(s);
      st.insert(x);
      s += to_string(i);
      if (s.length() > 10) {
        break;
      }
    }
  }

  vector<long long> pre(st.begin(), st.end());

  string s;
  cin >> s;

  vector<string> ranges = split(s, ',');

  long long result = 0;

  for (string &range : ranges) {
    vector<string> r = split(range, '-');
    long long ld = stoll(r[0]);
    long long rd = stoll(r[1]);

    for (auto fx : pre) {
      if (fx >= ld && fx <= rd) {
        result += fx;
      }
      if (fx > rd) {
        break;
      }
    }
  }

  cout << result << '\n';

  return 0;
}
