/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
PROG: milk
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
  ofstream fout("milk.out");
  ifstream fin("milk.in");
  // n: 所需牛奶总量, m: 提供牛奶的农夫数量
  int n, m;
  fin >> n >> m;

  // 每个农夫能提供的牛奶的 价格, 数量
  vector<pair<int, int >> farmers;
  for (int i = 0; i < m; ++i) {
    int price, num;
    fin >> price >> num;
    farmers.emplace_back(price, num);
  }
  // 核心点: 按牛奶单价排序
  std::sort(farmers.begin(), farmers.end());
  int money = 0;
  // 遍历农夫列表
  for (auto farmer: farmers) {
    if (n > farmer.second) { // 把这个农夫的牛奶全部买下
      n -= farmer.second;
      money += farmer.first * farmer.second;
    } else { // 所需 < 农夫的牛奶提供量，按所需买即可
      money += farmer.first * n;
      break;
    }
  }
  fout << money << endl;
  return 0;
}