/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
PROG: ariprog
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

int N, M; // n: 3~25  m: 1~250
int arr[26];
vector<int> list;
vector<pair<int, int>> res;

bool check(int i, int v) {
  if (i == 0) return true;
  if (i == 1 && v > arr[0]) return true;
  if (i >= 2 && (v - arr[i - 1] == arr[i - 1] - arr[i - 2])) return true;
  return false;
}

void dfs(int depth) {
  if (depth == N) {
    res.emplace_back(arr[0], arr[1] - arr[0]);
    return;
  }

  for (int j: list) {
    if (check(depth, j)) {
      arr[depth] = j;
      dfs(depth + 1);
      arr[depth] = 0;
    }
  }
}

int main() {
  ofstream fout("ariprog.out");
  ifstream fin("ariprog.in");
  fin >> N >> M;
  set<int> t;
  for (int i = 0; i <= M; ++i) {
    for (int j = 0; j <= M; ++j) {
      t.insert(i * i + j * j);
    }
  }
  for (auto item: t) {
    list.push_back(item);
  }
  cout << list.size() << endl;
  dfs(0);
  sort(res.begin(), res.end(), [](pair<int, int> a, pair<int, int> b) {
      if (a.second == b.second)
        return a.first < b.first;
      else
        return a.second < b.second;
  });
  for (auto r: res) {
    fout << r.first << " " << r.second << endl;
  }
  if (res.empty())
    fout << "NONE" << endl;
  return 0;
}