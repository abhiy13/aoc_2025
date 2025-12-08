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

template <typename T> class dsu {
public:
  vector<T> p;
  vector<T> rank;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    rank.resize(n);
    iota(p.begin(), p.end(), 0);
    fill(rank.begin(), rank.end(), 1);
  }

  inline T get(T x) { return (x == p[x] ? x : (p[x] = get(p[x]))); }

  inline bool unite(T x, T y) {
    T px = get(x);
    T py = get(y);
    if (px != py) {
      if (rank[px] <= rank[py]) {
        p[px] = py;
        rank[py] += rank[px];
      } else {
        p[py] = px;
        rank[px] += rank[py];
      }
      return true;
    }
    return false;
  }
};

template <typename T> class Point {
public:
  T x, y, z;

  Point() {}

  Point(T _x, T _y, T _z) {
    x = _x;
    y = _y;
    z = _z;
  }

  Point(string s) {
    vector<string> pts = split(s, ',');
    x = (T)stoi(pts[0]);
    y = (T)stoi(pts[1]);
    z = (T)stoi(pts[2]);
  }

  inline T distance(Point other) {
    return (other.x - x) * (other.x - x) + (other.y - y) * (other.y - y) +
           (other.z - z) * (other.z - z);
  }
};

const int MAXN = 1000;
// for test
// const int MAXN = 10;

int main() {
  vector<string> input = get_input();

  int N = input.size();
  vector<Point<long long>> v(N);

  for (int i = 0; i < N; ++i) {
    v[i] = Point<long long>(input[i]);
  }

  dsu<int> D(N);

  // <distance, <index1, index2>:
  set<pair<long long, pair<int, int>>> distanceSet;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (j == i) {
        continue;
      }
      distanceSet.insert({v[i].distance(v[j]), {min(j, i), max(j, i)}});
    }
  }

  vector<pair<long long, pair<int, int>>> distances(distanceSet.begin(),
                                                    distanceSet.end());

  long long res = 1;

  // part 1
  /*
  for (auto x : distances) {
    cerr << x.first << ' ' << x.second.first << ' ' << x.second.second << '\n';
  }

  for (int count = 0, i = 0; i < MAXN; i++) {
    auto points = distances[i].second;
    if (D.unite(points.first, points.second)) {
      cout << "MATCH : " << i;
    }
    cout << "\n";
  }

  vector<long long> ranks;

  cout << "PARENTS: \n";
  for (int i = 0; i < N; ++i) {
    cout << i << ' ' << D.get(i) << '\n';
    if (D.get(i) != i) {
      continue;
    }
    cout << "RANK : " << i << ' ' << D.rank[i] << '\n';
    ranks.push_back(D.rank[i]);
  }

  sort(ranks.begin(), ranks.end(), greater<long long>());
  for (int i = 0; i < 3; ++i) {
    cout << ranks[i] << ' ';
    res *= ranks[i];
  }
  */

  pair<int, int> last;
  for (int i = 0; i < distances.size(); ++i) {
    auto points = distances[i].second;
    if (D.unite(points.first, points.second)) {
      last = points;
    }
  }

  res = v[last.first].x * 1LL * v[last.second].x;

  cout << res << '\n';

  return 0;
}
