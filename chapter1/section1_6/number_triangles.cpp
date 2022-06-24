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
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> arr;
int max_sum = 0;

int main() {
  // handle input
  ifstream fin("numtri.in");
  int R;
  fin >> R;
  for (int i = 0; i < R; ++i) {
    vector<int> arr_j;
    for (int j = 0; j <= i; ++j) {
      int t;
      fin >> t;
      int max_v = t;
      for (int k = j - 1; k <= j; ++k) {
        if (0 <= k && k < i && i > 0) {
          max_v = max(max_v, t + arr[i - 1][k]);
        }
      }
      arr_j.push_back(max_v);
    }
    arr.push_back(arr_j);
  }
  fin.close();
  // handle solve
  for (int i = 0; i < R; ++i) {
    max_sum = max(max_sum, arr[R - 1][i]);
  }

  // handle output
  ofstream fout("numtri.out");
  fout << max_sum << endl;
  fout.close();
  return 0;
}
