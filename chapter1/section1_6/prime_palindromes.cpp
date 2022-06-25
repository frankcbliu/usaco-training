/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
TASK: pprime
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
vector<int> ans;
int a, b;

// 计算是否质数 & 判断是否满足范围
bool is_prime_and_check(int num) {
  if (num < a) return false;
  if (num < 2) return false;
  if (num == 2) return true;
  for (int i = 3; i * i <= num; i += 2) {
    if (num % i == 0)
      return false;
  }
  return true;
}

void generate_1() {
  int d1;
  for (d1 = 1; d1 <= 9; d1 += 2) {  /* only odd; evens aren't so prime */
    if (d1 > b) return;
    if (is_prime_and_check(d1))
      ans.push_back(d1);
  }
}

void generate_2() {
  int d1;
  for (d1 = 1; d1 <= 9; d1 += 2) {  /* only odd; evens aren't so prime */
    int val = 10 * d1 + d1;
    if (val > b) return;
    if (is_prime_and_check(val))
      ans.push_back(val);
  }
}

void generate_3() {
  int d1, d2;
  for (d1 = 1; d1 <= 9; d1 += 2) {  /* only odd; evens aren't so prime */
    for (d2 = 0; d2 <= 9; d2++) {
      int val = 100 * d1 + 10 * d2 + d1;
      if (val > b) return;
      if (is_prime_and_check(val))
        ans.push_back(val);
    }
  }
}

void generate_4() {
  int d1, d2;
  for (d1 = 1; d1 <= 9; d1 += 2) {  /* only odd; evens aren't so prime */
    for (d2 = 0; d2 <= 9; d2++) {
      int val = 1000 * d1 + 100 * d2 + 10 * d2 + d1;
      if (val > b) return;
      if (is_prime_and_check(val))
        ans.push_back(val);
    }
  }
}

void generate_5() {
  int d1, d2, d3;
  for (d1 = 1; d1 <= 9; d1 += 2) {  /* only odd; evens aren't so prime */
    for (d2 = 0; d2 <= 9; d2++) {
      for (d3 = 0; d3 <= 9; d3++) {
        int val = 10000 * d1 + 1000 * d2 + 100 * d3 + 10 * d2 + d1;
        if (val > b) return;
        if (is_prime_and_check(val))
          ans.push_back(val);
      }
    }
  }
}

void generate_6() {
  int d1, d2, d3;
  for (d1 = 1; d1 <= 9; d1 += 2) {  /* only odd; evens aren't so prime */
    for (d2 = 0; d2 <= 9; d2++) {
      for (d3 = 0; d3 <= 9; d3++) {
        int val = 100000 * d1 + 10000 * d2 + 1000 * d3 + 100 * d3 + 10 * d2 + d1;
        if (val > b) return;
        if (is_prime_and_check(val))
          ans.push_back(val);
      }
    }
  }
}

void generate_7() {
  int d1, d2, d3, d4;
  for (d1 = 1; d1 <= 9; d1 += 2)
    for (d2 = 0; d2 <= 9; d2++)
      for (d3 = 0; d3 <= 9; d3++)
        for (d4 = 0; d4 <= 9; d4++) {
          int val = 1000000 * d1 + 100000 * d2 + 10000 * d3 + 1000 * d4 + 100 * d3 + 10 * d2 + d1;
          if (val > b) return;
          if (is_prime_and_check(val))
            ans.push_back(val);
        }
}

void generate_8() {
  int d1, d2, d3, d4;
  for (d1 = 1; d1 <= 9; d1 += 2)
    for (d2 = 0; d2 <= 9; d2++)
      for (d3 = 0; d3 <= 9; d3++)
        for (d4 = 0; d4 <= 9; d4++) {
          int val = 10000000 * d1 + 1000000 * d2 + 100000 * d3 + 10000 * d4 + 1000 * d4 + 100 * d3 + 10 * d2 + d1;
          if (val > b) return;
          if (is_prime_and_check(val))
            ans.push_back(val);
        }
}

void generate_9() {
  int d1, d2, d3, d4, d5;
  for (d1 = 1; d1 <= 9; d1 += 2)
    for (d2 = 0; d2 <= 9; d2++)
      for (d3 = 0; d3 <= 9; d3++)
        for (d4 = 0; d4 <= 9; d4++)
          for (d5 = 0; d5 <= 9; d5++) {
            int val = 100000000 * d1 + 10000000 * d2 + 1000000 * d3 + 100000 * d4 + 10000 * d5 + 1000 * d4 + 100 * d3 +
                      10 * d2 + d1;
            if (val > b) return;
            if (is_prime_and_check(val))
              ans.push_back(val);
          }
}

int main() {
  // handle input
  ifstream fin("pprime.in");
  ofstream fout("pprime.out");
  fin >> a >> b;
  fin.close();
  // handle solve
  generate_1();
  generate_2();
  generate_3();
  generate_4();
  generate_5();
  generate_6();
  generate_7();
  generate_8();
  generate_9();

  for (auto i: ans) {
    fout << i << endl;
  }
  // handle output
  fout.close();
  return 0;
}
