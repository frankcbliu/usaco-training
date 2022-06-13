/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
TASK: crypt1
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
vector<int> digits;
vector<int> twos;
vector<int> threes;

// 生成 i 位数的数据，并存储到 arr 中, num是初始值0
void generate(int num, int i, vector<int> *arr) {
  if (i == 0) {
    arr->push_back(num);
    return;
  }
  for (auto digit: digits) {
    generate(num * 10 + digit, i - 1, arr);
  }
}

// 输出数组内容
void show(const vector<int> &arr) {
  for (auto item: arr) {
    cout << item << " ";
  }
  cout << endl;
}

// 判断某个数字是否在 digits 中
bool isIn(int digit_) {
  for (auto digit: digits) {
    if (digit_ == digit) {
      return true;
    }
  }
  return false;
}

// 判断某个数是否都由 digits 组成
bool isValid(int num) {
  if (num < 10)
    return isIn(num);
  while (num > 0) {
    if (isIn(num % 10)) {
      num = num / 10;
    } else {
      return false;
    }
  }
  return true;
}


int main() {
  ofstream fout("crypt1.out");
  ifstream fin("crypt1.in");
  // 0. 获取输入
  int n; // 数字集长度
  fin >> n;
  digits.resize(n);
  for (int i = 0; i < n; ++i) { // 数字集
    fin >> digits[i];
  }
//  show(digits);
  // 1. 生成两位数
  generate(0, 2, &twos);
//  show(twos);
  // 2. 生成三位数
  generate(0, 3, &threes);
//  show(threes);

  int cnt = 0;
  // 3. 遍历所有情况
  for (auto three: threes) {
    for (auto two: twos) {
      int p1 = three * (two % 10);
      int p2 = three * (two / 10);
      int res = three * two;
      // 需要满足以下条件:
      // - p1,p2均为三位数, res为四位数
      // - p1,p2,res都是由 digits 数字集合中的数字组成的
      if (p1 < 1000 && p2 < 1000 && res < 10000 &&
          isValid(p1) && isValid(p2) && isValid(res)) {
//        cout << res << " ";
        cnt++;
      }
    }
  }
  fout << cnt << endl;
//  cout << endl;
  return 0;
}
