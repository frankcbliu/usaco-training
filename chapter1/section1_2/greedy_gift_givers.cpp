/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
PROG: gift1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <cassert>
#include <map>
#include <vector>

using namespace std;

// just for debug
void print(map<string, int> groups) {
  cout << "-------" << endl;
  auto iter = groups.begin();
  while (iter != groups.end()) {
    cout << iter->first << " " << iter->second << '\n';
    iter++;
  }
}

int main() {
  ofstream fout("gift1.out");
  ifstream fin("gift1.in");
  // 1. 获取人数
  int np;
  fin >> np;
  map<string, int> groups;
  vector<string> map_index;
  string name;
  // 2. 获取所有人名，生成 name -> money 的映射
  for (int i = 0; i < np; ++i) {
    fin >> name;
    map_index.push_back(name);
    groups[name] = 0;
  }
  // 3. 遍历每个人的分钱方案
  for (int i = 0; i < np; ++i) {
    fin >> name; // 3.1 记录 givers 的名字
    int total, nums;
    fin >> total >> nums; // 3.2 total是givers从银行取出来的钱数，nums是需要分钱的人数
    if (nums == 0) {
      continue;
    }
    assert(nums != 0);
    groups[name] += total % nums - total; // 3.3 分钱者的钱数变化 = 原有的钱 + 分钱后剩下的钱 - 从银行取出的钱数
    for (int j = 0; j < nums; ++j) {
      fin >> name;
      groups[name] += total / nums;  // 3.4 被分到钱的人增加钱
    }
//    print(groups); // debug 使用
  }

  // 4. 按输入顺序，输出每个人及对应的钱
  for (auto& i: map_index) {
    fout << i << " " << groups[i] << '\n';
  }

  return 0;
}