/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
PROG: milk2
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

// debug
void show_vec(const vector<pair<int, int>>& arrs) {
  for (auto arr: arrs) {
    cout << arr.first << " " << arr.second << endl;
  }
  cout << "--------------" << endl;
}

int main() {
  ofstream fout("milk2.out");
  ifstream fin("milk2.in");
  // 1. 获取输入
  int n;
  fin >> n;
  vector<pair<int, int>> nums;
  nums.resize(n);
//  cout << "n:" << n << endl; // debug
  for (auto& arr: nums) {
    fin >> arr.first >> arr.second;
  }
  // 2. 合并区间 merge arrays
  std::sort(nums.begin(), nums.end());
//  show_vec(nums); // debug
  auto iter = nums.begin() + 1;
  while (iter != nums.end()) {
    if (iter->first <= (iter - 1)->second) {
      // merge nums[i-1] & nums[i]
      (iter - 1)->second = max((iter - 1)->second, iter->second);
      nums.erase(iter);
    } else {
      iter++;
    }
  }
//  show_vec(nums); // debug
  // 3. 暴力搜索
  int max_milk = 0, max_no_milk = 0;
  for (int i = 0; i < nums.size(); ++i) {
    max_milk = max(max_milk, nums[i].second - nums[i].first);
    if (i > 0)
      max_no_milk = max(max_no_milk, nums[i].first - nums[i - 1].second);
  }

//  cout << "max: " << max_milk << " max_no_milk:" << max_no_milk << endl;
  fout << max_milk << " " << max_no_milk << endl;

  return 0;
}