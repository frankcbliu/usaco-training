/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
PROG: namenum
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;

// 两种 dfs 方法，给一个 size， 生成 size 位数的 0-2 的字符串
// 举例， size = 2, 生成 [00,01,02,10,11,12,20,21,22]
vector<string> dfs(int size) {
  if (size == 0)
    return {""};
  vector<string> back = dfs(size - 1);
  vector<string> res;
  for (int i = 0; i < 3; ++i) {
    for (const string& item: back) {
      res.push_back(char(i + '0') + item);
    }
  }
  return res;
}

vector<string> result;

void dfs2(string pre, int size) {
  if (size == 0) {
    result.push_back(pre);
    return;
  }
  for (int i = 0; i < 3; ++i) {
    dfs2(pre + to_string(i), size - 1);
  }
}

// 要题目要求把 char 转 int
int char_2_num(char ch) {
  switch (ch) {
    case 'A':
    case 'B':
    case 'C':
      return 2;
    case 'D':
    case 'E':
    case 'F':
      return 3;
    case 'G':
    case 'H':
    case 'I':
      return 4;
    case 'J':
    case 'K':
    case 'L':
      return 5;
    case 'M':
    case 'N':
    case 'O':
      return 6;
    case 'P':
    case 'R':
    case 'S':
      return 7;
    case 'T':
    case 'U':
    case 'V':
      return 8;
    default:
      return 9;
  }
}

// 按题目要求把 string 转成 long long
long long string_2_num(const string& name) {
  long long res = 0;
  for (char i: name) {
    res = res * 10 + char_2_num(i);
  }
  return res;
}


int main() {

  ofstream fout("namenum.out");
  ifstream fin("namenum.in");
  ifstream din("dict.txt"); // "../chapter1/section1_3/dict.txt"

  // 字典存储结构， 生成的数字 -> 字典内的字符串数组
  unordered_map<long long, vector<string>> name_map;
  for (int i = 0; i < 4617; ++i) {
    string tmp;
    din >> tmp;
    long long snum = string_2_num(tmp);
    if (name_map.find(snum) == name_map.end()) {
      vector<string> arr{tmp};
      name_map[snum] = arr;
    } else {
      name_map[snum].push_back(tmp);
    }
  }
  // 读取目标数字，注意长度是1-12，得用 long long , 不能用 int
  long long num;
  fin >> num;

  // 查找是否存在
  if (name_map.find(num) != name_map.end()) {
    auto arr = name_map[num];
    for (const auto& item: arr) {
      fout << item << endl;
    }
  } else {
    fout << "NONE" << endl;
  }

  return 0;
}