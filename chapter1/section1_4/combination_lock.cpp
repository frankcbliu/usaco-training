/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
PROG: combo
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

void show(const vector<int> &arr) {
  for (int i: arr) {
    cout << i << " ";
  }
  cout << endl;
}

set<vector<int>> res;

// 给定某位数上的数字 i, 以及位数上的范围 n, 生成这位数上的可能范围 (也就是跟这个密码足够接近的数字)
vector<int> generate_key(int i, int n) {
  vector<int> keys;
  for (int j = -2; j <= 2; ++j) {
    int t = (i + j + n) % n;
    keys.push_back(t ? t : n);
  }
  return keys;
}

// 根据三位数上的可能性，遍历生成 close_enough 的密码
void generate(const vector<int>& arr1, const vector<int>& arr2, const vector<int>& arr3) {
  for (auto a: arr1) {
    for (auto b: arr2) {
      for (auto c: arr3) {
        res.insert({a, b, c});
      }
    }
  }
}

// 简化代码
void generate_vec(vector<int> c, int n) {
  generate(generate_key(c[0], n), generate_key(c[1], n), generate_key(c[2], n));
}

int main() {
  ofstream fout("combo.out");
  ifstream fin("combo.in");
  // 1. 获取输入
  int n;
  fin >> n;
  vector<int> c1, c2;
  c1.resize(3);
  c2.resize(3);
  for (int &i: c1) fin >> i;
  for (int &i: c2) fin >> i;
  // 2. 计算所有足够接近的密码
  generate_vec(c1, n);
  generate_vec(c2, n);
  // 3. 输出结果
  fout << res.size() << endl;
  return 0;
}