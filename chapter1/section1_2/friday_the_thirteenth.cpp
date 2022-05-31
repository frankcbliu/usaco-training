/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
TASK: friday
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// 判断是否闰年
bool isLeapYear(int year) {
  // 如果不是世纪年，需要是 4 的倍数
  // 如果是世纪年，需要为 400 的倍数
  return (year % 100 != 0 && year % 4 == 0) ||
         (year % 100 == 0 && year % 400 == 0);
}

int main() {
  ofstream fout("friday.out");
  ifstream fin("friday.in");
  int n = 20;
//  fin >> n;
  // 1900.1.1, Monday-> (1900+n-1).12.31
  int months[12] = { // 1-12月的天数，2 月的可能需要根据闰年进行处理 +1
          31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
  };

  // 记录13号是周一、周二到周日的次数
  int days[7] = {0};

  // 解法1: 模拟
  int day = 1;
  for (int year = 1900; year < 1900 + n; ++year) {
    bool is_leap = isLeapYear(year);
    for (int i = 0; i < 12; ++i) { // 月份
      // 计算这个月的13号是什么日子
      day = (day + 12) % 7;
      days[day]++;
      // 计算这个月有多少天，加上去
      day += months[i];
      if (i == 1 && is_leap)
        day++;
    }
  }

  // 输出 13号是周六、周日、一、... 的次数
  for (int i = 2; i < 9; ++i) {
    cout << days[i % 7] << " ";
  }
//  fout << a + b << endl;
  return 0;
}
