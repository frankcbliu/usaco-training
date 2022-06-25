/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
TASK: numtri
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int dp[1000][1000];
int R;
int ans = 0;

/**
 * 两种办法，自底向上会简单很多，自顶向下则还需要考虑边界问题
 */
void solve() { // 自顶向下
  for (int i = 1; i < R; ++i) {
    for (int j = 0; j <= i; ++j) {
      if (j == 0) {
        dp[i][j] += dp[i - 1][j];
      } else if (j == i) {
        dp[i][j] += dp[i - 1][j - 1];
      } else
        dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
    }
  }
}

int main() {
  ifstream fin("numtri.in");
  fin >> R;
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j <= i; ++j) {
      fin >> dp[i][j];
    }
  }
  fin.close();
  // 自底向上
  for (int i = R - 2; i >= 0; --i) {
    for (int j = 0; j <= i; ++j) {
      dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
    }
  }
  ans = dp[0][0];
  // 自顶向下
//  solve();
//  for (int i = 0; i < R; ++i) {
//    ans = max(ans, dp[R - 1][i]);
//  }
  // handle output
  ofstream fout("numtri.out");
  fout << ans << endl;
  fout.close();
  return 0;
}
