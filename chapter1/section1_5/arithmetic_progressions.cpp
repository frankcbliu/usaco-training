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
vector<pair<int, int>> ans;
bool m[2 * 250 * 250 + 1];
vector<int> a0_list;

bool check(int a0, int d) {
  for (int n = 0; n < N; ++n) {
    if (!m[a0 + n * d]) return false;
  }
  return true;
}

void force_search() {
  int m2 = 2 * M * M;
//  for (int a0 = 0; a0 < m2 - N + 1; ++a0) { //
  for (int i = 0; i < a0_list.size() - N + 1; ++i) { // 用 a0_list 可以优化速度，但是空间占用会更高一些
    int a0 = a0_list[i];
    for (int d = 1; d <= (m2 - a0) / (N - 1); ++d) { // 关键优化点 d <= (2*M^2 - a0) / (n-1)
      if (check(a0, d)) {
        ans.emplace_back(d, a0);
      }
    }
  }
}

int main() {
  ofstream fout("ariprog.out");
  ifstream fin("ariprog.in");
  fin >> N >> M;
  set<int> tmp_set;
  for (int i = 0; i <= M; ++i)
    for (int j = 0; j <= M; ++j) {
      int v = i * i + j * j;
      m[v] = true;
      tmp_set.insert(v);
    }
  for (auto a0: tmp_set)
    a0_list.push_back(a0);

  // 暴力搜索
  force_search();
  // 对结果进行排序
  sort(ans.begin(), ans.end());
  for (auto r: ans)
    fout << r.second << " " << r.first << endl;
  if (ans.empty())
    fout << "NONE" << endl;
  return 0;
}