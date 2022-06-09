/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
TASK: dualpal
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// 判断是否回文
bool is_palindromes(string value) {
  size_t n = value.size();
  for (int i = 0; i < n / 2; ++i) {
    if (value[i] != value[n - 1 - i]) {
      return false;
    }
  }
  return true;
}

// 把10进制的 value 转成目标进制
string to_base(int value, int base) { // base <= 10
  if (base == 10)
    return to_string(value);
  int s = value / base;
  int t = value % base;
  string res = to_string(t);
  while (s > 0) {
    t = s % base;
    s = s / base;
    res.insert(0, to_string(t)); // 从前面插入
  }
  return res;
}

int main() {
  ofstream fout("dualpal.out");
  ifstream fin("dualpal.in");
  int n, s;
  fin >> n >> s;
  // 注意: s 的范围是 0~10000, 不代表递增的 i 的范围
  for (int i = s + 1; i < 0x7fff && n > 0; ++i) {
    // 需要至少两个进制下是回文
    int t = 2;
    for (int base = 2; base <= 10 && t > 0; ++base) {
      string v = to_base(i, base);
      if (is_palindromes(v)) {
        t--;
      }
    }
    // t == 0说明达到两个了
    if (t == 0) {
      n--;
      fout << i << endl;
    }
  }
  return 0;
}
