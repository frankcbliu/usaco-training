/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: q6412591
TASK: sprime
LANG: C++
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
int N;
vector<int> ans;

bool is_prime(int num) {
  if (num < 2) return false;
  if (num == 2 || num == 3)return true;
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0) return false;
  }
  return true;
}

void dfs(int i, int val) {
  if (!is_prime(val)) return;
  if (i == N) {
    ans.push_back(val);
    return;
  }
  if (is_prime(val)) {
    for (int j = 0; j <= 9; ++j) {
      dfs(i + 1, val * 10 + j);
    }
  }
}

int main() {
  // handle input
  ifstream fin("sprime.in");
  fin >> N;
  fin.close();
  // handle solve
  vector<int> arr = {2, 3, 5, 7};
  for (auto i: arr) {
    dfs(1, i);
  }
  // handle output
  ofstream fout("sprime.out");
  for (auto i: ans) {
    fout << i << endl;
  }
  fout.close();
  return 0;
}
