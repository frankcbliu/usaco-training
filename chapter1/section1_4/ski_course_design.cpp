/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
PROG: skidesign
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

#define MAX_N 1001
int N; // 1~1000
int hills[MAX_N];


// 2. 思考如何构建递归函数
int solve() {
  int min_cost = 0x7ffffff;
  int max_v = 0;
  for (int i = 1; i <= N; ++i) {
    max_v = max(hills[i], max_v);
  }

  for (int i = 0; i <= max_v - 17; ++i) { // 高度区间
    int cost = 0;
    for (int j = 1; j <= N; ++j) { // john 的 hills
      if (i <= hills[j] && hills[j] <= i + 17) continue;
      else { // 在区间外的才需要考虑计算
        int x = min(abs(i - hills[j]), abs(i + 17 - hills[j]));
        cost += x * x;
      }
//      if (hills[j] < i || hills[j] > i + 17) { // 在区间外的才需要考虑计算
//        int a = abs(i - hills[j]);
//        int b = abs(i + 17 - hills[j]);
//        cost += min(a * a, b * b);
//      }
    }
    min_cost = min(cost, min_cost);
  }
  return min_cost;
}


int main() {
  // 0. 获取输入
  ifstream fin("skidesign.in");
  fin >> N;
  for (int i = 1; i <= N; ++i) {
    fin >> hills[i];
  }
  fin.close();

  // 1. 输出
  ofstream fout("skidesign.out");
  fout << solve() << endl;
  fout.close();
  return 0;
}