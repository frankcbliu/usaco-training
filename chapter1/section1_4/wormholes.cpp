/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
PROG: wormhole
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>

using namespace std;

#define MAX_N 12

int N;
int X[MAX_N + 1], Y[MAX_N + 1];
int partner[MAX_N + 1] = {0};
int next_on_right[MAX_N + 1] = {0}; // 初始化为 0

// 11. 判断有无循环的逻辑
bool circle_exist() {
//  return true; // 12. 对前面的框架代码进行测试 , 4个点，组合有3种，输出结果应该为3
  for (int start = 1; start <= N; ++start) {
    int pos = start;
    for (int count = 0; count < N; ++count) { // 13. 通过 N 次步进，判断有无循环
      pos = next_on_right[partner[pos]];
    }
    /**
    *  14. 如果没有循环，也就是会存在一个 i 点，右边没有任何节点。
    *  而 next 数组中的值都初始化为 0 了，值是从 1 -> N , 所以 next_on_right[0] == 0,
    *  那么如果没有循环，最终 next_on_right[i] 的值一定等于 0
    */
    if (pos != 0) return true;
  }
  return false;
}

// 2. 构建 DFS 框架
int solve() {
  int i; // 3. 找到第一个还没有配对的点
  int total = 0;
  for (i = 1; i <= N; ++i) {
    if (partner[i] == 0) break;
  }

  // 9. 考虑递归 base 情况
  if (i > N) {
    // 10. 考虑有无循环
    if (circle_exist()) return 1;
    else return 0;
  }

  // 4. 为这个点寻找配对
  for (int j = i + 1; j <= N; ++j) {
    if (partner[j] == 0) { // 5. 找到下一个还未配对的点
      partner[i] = j;
      partner[j] = i;
//      solve(); // 6. 递归查找
      total += solve(); // 8. 累加结果
      // 7. 递归结束后要恢复
      partner[i] = partner[j] = 0;
    }
  }
  return total;
}

int main() {
  // 0. 获取输入
  ifstream fin("wormhole.in");
  fin >> N;
  for (int i = 1; i <= N; ++i) {
    fin >> X[i] >> Y[i];
  }

  // 15. 初始化 next_on_right 数组
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      if (Y[i] == Y[j] && X[i] < X[j]) // j 点在 i 点右边
        /**
         * 如果 i 点右边之前没有点，那么直接保存 j 点
         * 否则，就需要考虑之前的点 next_on_right[i] 和 现在的 j 点哪个更近
         */
        if (next_on_right[i] == 0 ||
            X[j] - X[i] < X[next_on_right[i]] - X[i])
          next_on_right[i] = j;
    }
  }

  // 1. 输出结果
  ofstream fout("wormhole.out");
  fout << solve() << endl;
  return 0;
}