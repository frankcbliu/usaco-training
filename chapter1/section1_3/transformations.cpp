/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
PROG: transform
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Square {
public:
    // 初始化 Square
    Square(vector<char*> arr) {
      n = arr.size();
      arr_ = new char* [n];
      for (int i = 0; i < n; ++i) {
        arr_[i] = new char[n];
        for (int j = 0; j < n; ++j) {
          arr_[i][j] = arr[i][j];
        }
      }
    };

    // 输出 Square，debug 用
    void show() {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          cout << arr_[i][j] << " ";
        }
        cout << endl;
      }
      cout << "----------------" << endl;
    }

    // 判断当前 Square 和 传入的 Square 是否一致
    bool isEqual(Square square) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (arr_[i][j] != square.arr_[i][j])
            return false;
        }
      }
      return true;
    }

    // 顺时针旋转90度，注意，最后会赋值给当前Square存储的arr
    void rotate90() {
      char** copy = new char* [n];
      for (int i = 0; i < n; ++i) copy[i] = new char[n];

      for (int i = 0; i < n; ++i) {
        // 用下面第二种赋值方式的话，就可以把 copy[i] = new char[n]; 放到这里来。
        for (int j = 0; j < n; ++j) {
          copy[j][n - 1 - i] = arr_[i][j];
//          copy[i][j] = arr_[n - 1 - j][i]; // 这种方式比较难想，不直观，容易出错
        }
      }
      arr_ = copy;
    }

    void rotate180() {
      char** copy = new char* [n];
      for (int i = 0; i < n; ++i) copy[i] = new char[n];

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          copy[n - 1 - i][n - 1 - j] = arr_[i][j];
//          copy[i][j] = arr_[n - 1 - i][n - 1 - j];
        }
      }
      arr_ = copy;
    }

    void rotate270() {
      char** copy = new char* [n];
      for (int i = 0; i < n; ++i) copy[i] = new char[n];

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          copy[n - 1 - j][i] = arr_[i][j];
//          copy[i][j] = arr_[j][n - 1 - i];
        }
      }
      arr_ = copy;
    }

    // 以中心竖线为轴进行翻转
    void reflection() {
      char** copy = new char* [n];
      for (int i = 0; i < n; ++i) copy[i] = new char[n];

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          copy[i][n - 1 - j] = arr_[i][j];
//          copy[i][j] = arr_[i][n - 1 - j];
        }
      }
      arr_ = copy;
    }

    int n;
    char** arr_;
};


int main() {
  ofstream fout("transform.out");
  ifstream fin("transform.in");
  // 1. 获取输入
  int n;
  fin >> n; // 1.1 获取方块个数
  vector<char*> arr;
  for (int i = 0; i < n; ++i) {
    arr.push_back(new char[n]);
    for (int j = 0; j < n; ++j) {
      fin >> arr[i][j];
    }
  }
  Square before(arr); // 1.2 获取变换前的方块
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)fin >> arr[i][j];
  }
  Square after(arr); // 1.3 获取变换后的方块


  // 2. 遍历所有操作
  for (int i = 1; i <= 6; ++i) {
    Square tmp(before);
    switch (i) {
      case 1:
        tmp.rotate90();
        break;
      case 2:
        tmp.rotate180();
        break;
      case 3:
        tmp.rotate270();
        break;
      case 4:
        tmp.reflection();
        break;
      case 5:
        continue;
      default: // #6是没有操作，正好放到 default 里
        break;
    }
    // 说明有相等的，直接输出后返回
    if (tmp.isEqual(after)) {
      fout << i << endl;
      return 0;
    }
    // 对于 #5 来说，相当于 1~3 + 4， 所以放在 1~3 的后面，减少代码量
    if (1 <= i && i <= 3) {
      tmp.reflection();
      if (tmp.isEqual(after)) { // 如果有满足 5 的，输出返回
        fout << 5 << endl;
        return 0;
      }
    }
  }
  // 能走到这里的，说明前面没有满足的，输出返回
  fout << 7 << endl;
  return 0;
}