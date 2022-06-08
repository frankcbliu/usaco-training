/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
PROG: palsquare
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

// 判断输入的字符串是否回文
bool is_palindrome(string value) {
  size_t n = value.size();
  for (int i = 0; i < n / 2; ++i) {
    if (value[i] != value[n - 1 - i]) {
      return false;
    }
  }
  return true;
}

// 数值转字符串
string int_2_str(int t) {
  string res;
  if (t <= 9)
    res.push_back(char(t + '0'));
  else
    res.push_back(char(t - 10 + 'A'));
  return res;
}

// 把10进制的 value 转成目标进制
string to_base(int value, int base) {
  if (base == 10)
    return to_string(value);
  int s = value / base;
  int t = value % base;
  string res = int_2_str(t);
  while (s > 0) {
    t = s % base;
    s = s / base;
    res.insert(0, int_2_str(t)); // 从前面插入
  }
  return res;
}

int main() {
  ofstream fout("palsquare.out");
  ifstream fin("palsquare.in");
  // 1. 获取进制
  int base;
  fin >> base; // 2~20

  // 2. 遍历 1~300(10进制)
  for (int i = 1; i <= 300; ++i) {
    string vv = to_base(i * i, base);
    if (is_palindrome(vv)) {
      string v = to_base(i, base);
      fout << v << " " << vv << endl;
    }
  }
  return 0;
}