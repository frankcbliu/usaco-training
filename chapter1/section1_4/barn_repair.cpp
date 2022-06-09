/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
PROG: barn1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

int main() {
  ofstream fout("barn1.out");
  ifstream fin("barn1.in");
  // 最多 m 块木板, s是门的总数, c 是牛的总数
  int m, s, c;
  fin >> m >> s >> c;
  // 0 代表没牛，1 代表里面有牛
  vector<int> arr = {0};
  arr.resize(c);
  for (int i = 0; i < c; ++i) {
    fin >> arr[i];
  }
  // 输入有牛的门牌号可能乱序，需要排序
  sort(arr.begin(), arr.end());
//  for (auto i: arr) cout << i << " "; // debug
//  cout << endl; // debug

  vector<int> res = {0}; // 需要按最大分块数初始化
  res.resize(m - 1);
  // 计算两两之间的门牌差值
  for (int i = 1; i < c; ++i) {
    res.push_back(arr[i] - arr[i - 1] - 1);
  }
  // 降序排序
  std::sort(res.rbegin(), res.rend());

  int sum = 0;
  for (int i = 0; i < m - 1; ++i) {
    // cout << res[i] << " ";
    sum += res[i];
  }
//  cout << endl << sum << endl; // debug
//  cout << arr[c - 1] - arr[0] + 1 - sum << endl; // debug
  fout << arr[c - 1] - arr[0] + 1 - sum << endl;
  return 0;
}