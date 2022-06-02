/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
TASK: beads
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int count_pre(string str) {
  if (str.length() <= 1) {
    return str.length();
  }
  char pre = str.at(0), pw = 'w';
  int cnt = 0;
  for (char ch: str) {
    if (ch != pre && ch != 'w' && pre != 'w') {// 先考虑退出循环的情况
      break;
    }
    if (ch == pre) { // 先考虑当前值能继续的情况
      cnt++;
    } else if (ch == 'w') {
      cnt++;
      if (pre != 'w')
        pw = pre;
    } else if (pre == 'w' && (ch == pw || pw == 'w')) {
      cnt++;
      pw = ch;
    } else {
      break;
    }
    pre = ch;
  }
  return cnt;
}

int main() {
  ofstream fout("beads.out");
  ifstream fin("beads.in");
  int n;
  string circle;
  fin >> n >> circle;
//  for debug
//  circle = "rrwwwwbb";
//  n = circle.length();
  circle = circle + circle;
  int max = 0;
  for (int i = 1; i < n + 1; ++i) {
    string left = circle.substr(0, i);
    std::reverse(left.begin(), left.end());
    int left_cnt = count_pre(left);
    string right = circle.substr(i, n - left_cnt);
// for debug
//    cout << left << " " << right << endl;
//    cout << left_cnt << " " << count_pre(right) << endl;
    max = std::max(max, left_cnt + count_pre(right));
  }
  fout << max << endl;
//  cout << max << endl; // for debug
  return 0;
}
