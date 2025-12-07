#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int main() {

  string s;
  vector<string> grid;

  while (cin >> s) {
    grid.push_back(s);
  }

  int n = grid.size(), m = grid[0].size();

  int res = 0;

  int removed = 0;
  do {
    removed = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int adj = 0;
        if (grid[i][j] != '@') {
          continue;
        }
        for (int k = 0; k < 8; ++k) {
          int x = i + dx[k], y = j + dy[k];
          if (x < 0 || x >= n || y < 0 || y >= n) {
            continue;
          }
          if (grid[x][y] == '@')
            adj++;
        }
        if (adj < 4) {
          grid[i][j] = '.';
          res++;
          removed++;
        }
      }
    }
  } while (removed != 0);

  cout << res << '\n';

  return 0;
}
