#include <bits/stdc++.h>

using namespace std;

int main() {

  string s;
  int dial = 50;
  int res = 0;

  while (cin >> s) {
    int n = stoi(s.substr(1));
    int old = dial;
    int sign = s[0] == 'L' ? -1 : 1;
    for (int i = 0; i < n; ++i) {
      dial = (dial + sign + 100) % 100;
      if (dial == 0) {
        res++;
      }
    }
    /*
    if (s[0] == 'L') {
      dial = (dial - n + 100) % 100;
    } else {
      dial = (dial + n) % 100;
    }
    if (dial == 0) {
      res++;
    }
    */
  }

  cout << res << '\n';

  return 0;
}
