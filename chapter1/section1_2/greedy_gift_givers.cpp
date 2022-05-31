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
//void print(map<string, int> groups) {
//  cout << "-------" << endl;
//  auto iter = groups.begin();
//  while (iter != groups.end()) {
//    cout << iter->first << " " << iter->second << '\n';
//    iter++;
//  }
//}

int main() {
  ofstream fout("gift1.out");
  ifstream fin("gift1.in");
  int np;
  fin >> np;
  map<string, int> groups;
  vector<string> map_index;
  string name;
  for (int i = 0; i < np; ++i) {
    fin >> name;
    map_index.push_back(name);
    groups[name] = 0;
  }
  for (int i = 0; i < np; ++i) {
    fin >> name; // givers
    // money give-nums
    int total, nums;
    fin >> total >> nums;
    if (nums == 0) {
      continue;
    }
    assert(nums != 0);
    groups[name] += total % nums - total;
    for (int j = 0; j < nums; ++j) {
      fin >> name;
      groups[name] += total / nums;
    }
//    print(groups); // debug 使用
  }

  for (auto & i : map_index) {
    fout << i << " " << groups[i] << '\n';

  }

  return 0;
}